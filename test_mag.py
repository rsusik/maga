import subprocess, sys, os, platform

# D:\Politechnika/#doktorat/ApproxNew/Solution/source/mag_dna_opt_l3_k0.exe D:\Politechnika/#doktorat/Multiple/patterns.r100/patterns.english.50MB.32.bin 32 D:\Politechnika/#doktorat/Multiple/sets/english.50MB 4 2 2 4

# test_mag.py approx_mag_dna_l2_k2.exe dna.64MB 256 32,64 4 2 2,3,4,5,6,7,8,9,10 4 >tmp.txt
# test_mag.py approx_mag_dna_l3_k2.exe dna.64MB 256 64 8,4,2 4,2,1 2,3,4,5,6,7,8,9,10 4 >> new_tmp.txt
# test_mag.py approx_mag_dna_l2_k2.exe dna.64MB 256 64 8,4,2 4,2,1 2,3,4,5,6,7,8 4 >> new_tmp.txt
# test_mag.py approx_mag_dna_l2_k2.exe dna.64MB 256 64 8 1 5 4 > new_tmp.txt
# test_mag.py approx_mag_dna_l3.exe dna.64MB 256 64 8 1 5 4 > new_tmp.txt

if platform.system() == 'Linux':
# Linux:
	pattern_loc = '/media/Twardziel/Politechnika/#doktorat/Multiple/patterns' # each folder should have name with suffix .r1000 where 1000 is number of patterns
	set_loc = '/media/Twardziel/Politechnika/#doktorat/Multiple/sets'
	output_loc = '/media/Twardziel/Politechnika/#doktorat/Multiple/out'
	alg_loc = './'
else:
# Windows
	pattern_loc = 'D:\Politechnika/#doktorat/Multiple/patterns' # each folder should have name with suffix r1000 where 1000 is number of patterns
	set_loc = 'D:\Politechnika/#doktorat/Multiple/sets'
	output_loc = 'D:\Politechnika/#doktorat/Multiple/out'
	alg_loc = 'D:\Politechnika/#doktorat/ApproxNew/Solution/source'



args_num = len(sys.argv) - 1
curr_path = os.getcwd()

arg_offset = 0
tof = False

# Error
if args_num < 1:
    print >> sys.stderr, "Error not enought parameters. See --help."
    exit()

if sys.argv[1]=='--help':
	print 'Pattern matching tester help.'
	print ''
	print 'Syntax:'
	print 'test [--help|--tof] algorithm[.exe] test_set r m u k q-size sigma'
	print ''
	print '--help      Shows the help'
	print '--tof       Writes output of each alg. to separate file(used for correctness check)'
	print 'algorithm   Algorithm(eg. cf,fso)'
	print 'test_set    Test set(eg. english.100MB)'
	print 'r           Pattern number(eg. 1000)'
	print 'm           Pattern length(eg. 8)'
	print 'u           U parameter(eg. 8)'
	print 'k           K parameter(eg. 2)'
	print ''
	print 'Example:'
	print 'test.py mag_dna_opt,mag_dna_l2,mag_l2,mag dna.200MB 100,1000 8,16,32,64 8 1,2 2,3,4,5,6,7,8,9,10 4,5'
	print ''
	exit()
elif sys.argv[1]=='--tof':
	tof = True
	arg_offset += 1

# Error
if args_num < 7:
    print >> sys.stderr, "Error not enought parameters. See --help."
    exit()

# algorithm
algs      = sys.argv[1+arg_offset] # algorithms
# arguments:
set_args  = sys.argv[2+arg_offset] # test text sets
r_args    = sys.argv[3+arg_offset] # pattern length
m_args    = sys.argv[4+arg_offset] # pattern length
u_args    = sys.argv[5+arg_offset] # U
k_args    = sys.argv[6+arg_offset] # K
q_args    = sys.argv[7+arg_offset] # Q
sig_args  = sys.argv[8+arg_offset] # Sigma

set_args_list  = set_args.split(',')
a_args_list    = algs.split(',')
r_args_list    = r_args.split(',')
m_args_list    = m_args.split(',')
u_args_list    = u_args.split(',')
k_args_list    = k_args.split(',')
q_list         = q_args.split(',')
sig_list       = sig_args.split(',')

#print 'Starting calculation for following parameters'
#print 'Sets      : ' + set_args
#print 'M         : ' + m_args
#print 'U         : ' + u_args
#print 'K         : ' + k_args
#print 'Q-Size    : ' + q_args

if not tof:
    print 'A\t' + 'S\t' + 'R\t' + 'Q\t' + 'M\t' + 'U\t' + 'K\t' + 'KDIFF\T' + 'Sig\t' + 'Sig^Q\t' + 'PSize\t' + 'txtSize\t' + 'Ver\t' + 'WhLoops\t' + 'Matches\t' + 'DataAcc\t' + 'Pre\t' + 'Run\t' + 'Pre+Run\t' + 'Run[MBs]\t' + 'P+R[MBs]\t' 
for a in a_args_list:
	for sig in sig_list:
		for q in q_list:
			for s in set_args_list:
				for r in r_args_list:
					for m in m_args_list:
						for u in u_args_list:
							for k in k_args_list:
								proc_filename    = alg_loc + '/' + a 
								pattern_filename = pattern_loc + '.r' + r + '/patterns.' + s + '.' + m + '.bin'
								set_filename     = set_loc + '/' + s
								if not os.path.isfile(proc_filename):
									print "Error: The prog file not found ( "+proc_filename+")"
									exit()
								if not os.path.isfile(pattern_filename):
									print "Error: The pattern file not found ( "+pattern_filename+")"
									exit()
								if not os.path.isfile(set_filename):
									print "Error: The set file not found ( "+set_filename+")"
									exit()
								#print proc_filename, pattern_filename, m, set_filename, u, k, q, sig
								proc = subprocess.Popen([proc_filename, pattern_filename, m, set_filename, u, k, q, sig], stdout=subprocess.PIPE)
								output = proc.stdout.read()
								if tof:
									outfilename = 'out.' + r + '.' + a + '.' + s + '.' + q + '.' + m + '.' + u + '.' + k + '.txt'
									outFile = open(output_loc + "/" + outfilename, "wb")
									outFile.write(output)
									outFile.close()
								else:
									output = a + '\t' + s + '\t' + r + '\t' + q + '\t' + m + '\t' + u + '\t' + k + '\t' + output;
									sys.stdout.write(output)
									sys.stdout.flush()

# subprocess.call(['Solution\\Release\\Test.exe'])
