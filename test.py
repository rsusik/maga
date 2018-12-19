import subprocess, sys, os, platform, argparse, gzip, shutil
from urllib.request import urlopen

# example: python3 mag_test.py -a mag -c sources.50MB -r 10,100,1000 -m 8,32 -q 2 -s 5 -u 4 -k 2

pattern_loc = '.' # each folder should start with patterns and have a name with suffix .r1000 where 1000 is number of patterns
set_loc = './sets'
alg_loc = '.'

curr_path = os.getcwd()

pizza_corpus = {
	'proteins.50MB': 'http://pizzachili.dcc.uchile.cl/texts/protein/proteins.50MB.gz',
	'proteins.100MB': 'http://pizzachili.dcc.uchile.cl/texts/protein/proteins.100MB.gz',
	'proteins.200MB': 'http://pizzachili.dcc.uchile.cl/texts/protein/proteins.200MB.gz',
	'sources.50MB': 'http://pizzachili.dcc.uchile.cl/texts/code/sources.50MB.gz',
	'sources.100MB': 'http://pizzachili.dcc.uchile.cl/texts/code/sources.100MB.gz',
	'sources.200MB': 'http://pizzachili.dcc.uchile.cl/texts/code/sources.200MB.gz',
	'dna.50MB': 'http://pizzachili.dcc.uchile.cl/texts/dna/dna.50MB.gz',
	'dna.100MB': 'http://pizzachili.dcc.uchile.cl/texts/dna/dna.100MB.gz',
	'dna.200MB': 'http://pizzachili.dcc.uchile.cl/texts/dna/dna.200MB.gz',
	'english.50MB': 'http://pizzachili.dcc.uchile.cl/texts/nlang/english.50MB.gz',
	'english.100MB': 'http://pizzachili.dcc.uchile.cl/texts/nlang/english.100MB.gz',
	'english.200MB': 'http://pizzachili.dcc.uchile.cl/texts/nlang/english.200MB.gz',
	'english.1024MB':'http://pizzachili.dcc.uchile.cl/texts/nlang/english.1024MB.gz',
	'xml.50MB': 'http://pizzachili.dcc.uchile.cl/texts/xml/dblp.xml.50MB.gz',
	'xml.100MB': 'http://pizzachili.dcc.uchile.cl/texts/xml/dblp.xml.100MB.gz',
	'xml.200MB': 'http://pizzachili.dcc.uchile.cl/texts/xml/dblp.xml.200MB.gz',
}

def check_patterns_existance(corpus, r, m):
	filename = "{}patterns.r{}/patterns.{}.{}.bin".format(pattern_loc, r, corpus, m)
	if os.path.isfile(filename):
		return True
	os.system("python3 generate_patterns.py -c {} -r {} -m {}".format(corpus, r, m))
	

def check_corpus_existance(corpus):
	filename = "{}/{}".format(set_loc, corpus)
	if os.path.isfile(filename):
		return True
	if corpus not in pizza_corpus:
		return False
	print("Warning: Corpus does NOT exists. Trying to download (it may take a while).")
	sys.stdout.flush()
	url = pizza_corpus[c]
	with urlopen(url) as ret:
		if ret.code != 200:
			return False
	gz_filename = "{}.gz".format(filename)
	os.makedirs(os.path.dirname(gz_filename), exist_ok=True)
	with urlopen(url) as response, open(gz_filename, 'wb') as gz_file:
		shutil.copyfileobj(response, gz_file)
	if os.path.isfile(gz_filename):
		with gzip.open(gz_filename, 'rb') as gz_file, open(filename, 'wb') as dest_file:
			dest_file.write(gz_file.read())
		if os.path.isfile(filename):
			os.remove(gz_filename)
			return True
	return False

parser = argparse.ArgumentParser(description='MAG testing script.', 
	epilog="Example:\npython3 test.py -a approx_mag_l3_k1 -c english.50MB -r 100 -m 8,16,32,64 -q 2,4,6 -s 5 -u 4 -k 1,2")
parser.add_argument("-r", "--npatterns", dest='r', type=str, default='100', help="number of patterns")
parser.add_argument("-a", "--algorithm", dest='a', type=str, default='approx_mag_l2_k1', help="algorithm[s] to be tested")
parser.add_argument("-c", "--corpus", dest='c', type=str, default='english.50MB', help="corpus")
parser.add_argument("-m", "--length", dest='m', type=str, default='8,16,32,64', help="pattern length[s] (e.g. 8,16,32)")
parser.add_argument("-u", "--faosou", dest='u', type=str, default='4', help="FAOSO parameter U")
parser.add_argument("-k", "--faosok", dest='k', type=str, default='1,2', help="FAOSO parameter k")
parser.add_argument("-q", "--q-gram", dest='q', type=str, default='2,4,6,8', help="q-gram size")
parser.add_argument("-s", "--sigma", dest='s', type=str, default='4,5', help="dest. alph. size")

args = parser.parse_args()


set_args_list  = args.c.split(',')
a_args_list    = args.a.split(',')
r_args_list    = args.r.split(',')
m_args_list    = args.m.split(',')
u_args_list    = args.u.split(',')
k_args_list    = args.k.split(',')
q_list         = args.q.split(',')
sig_list       = args.s.split(',')

for c in set_args_list:
	if check_corpus_existance(c) == False:
		print("Error: corpus {} does NOT exists".format(c))
		exit(100)

for c in set_args_list:
	for r in r_args_list:
		for m in m_args_list:
			check_patterns_existance(c, r, m)

print("a\tc\tr\tq\tm\tU\tk\tKdiff\ts\ts^2\tps\tn\tv\twh\tmatches\tacc\tpre_t\tsearch_t\tfull_t\tsearch[MB/s]\tfull[MB/s]")
for a in a_args_list:
	for sig in sig_list:
		for q in q_list:
			for c in set_args_list:
				for r in r_args_list:
					for m in m_args_list:
						for u in u_args_list:
							for k in k_args_list:
								proc_filename    = "{}/{}".format(alg_loc, a)
								pattern_filename = "{}/patterns.r{}/patterns.{}.{}.bin".format(pattern_loc, r, c, m)
								corpus_filename     = "{}/{}".format(set_loc, c)
								if not os.path.isfile(proc_filename):
									print("Error: The prog file not found ({})".format(proc_filename))
									exit()
								if not os.path.isfile(pattern_filename):
									print("Error: The pattern file not found ({})".format(pattern_filename))
									exit()
								if not os.path.isfile(corpus_filename):
									print("Error: The set file not found ({})".format(corpus_filename))
									exit()
								#print proc_filename, pattern_filename, m, corpus_filename, u, k, q, sig
								proc = subprocess.Popen([proc_filename, pattern_filename, m, corpus_filename, u, k, q, sig], stdout=subprocess.PIPE)
								output = proc.stdout.read()
								output = "{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}".format(a, c, r, q, m, u, k, output.decode('ascii'))
								sys.stdout.write(output)
								sys.stdout.flush()
