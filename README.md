# MAG for approximate pattern matching (MAGA)

## About
MAGA (MAG for approximate pattern matching) is algorithm designed for approximage pattern matching. The algorithm is based on idea of partitioning into exact pattern matching. The MAGA is based on previous work MAG (http://www.stringology.org/event/2014/p07.html) which was designed for exact multiple pattern matching. MAGA adopts the algorithm to approximate pattern matching problem.

This is a source code of MAGA that was written for research purpose and has a minimal error checking. The code may be not be very readable and comments may not be adequate. There is no warranty, your use of this code is at your own risk.

## Requirements

* C++ compiler compatible with C++11 standard
* Unix based 64-bit (should also work on 32-bit but performance is worse)
* Python 3 (for [testing](#testing))
* [Docker](#docker) (optionally)

## Compilation

To compile all variants of algorithm simply run:

```shell
git clone https://github.com/rsusik/maga maga
cd maga
make all
```

## Usage

The *make all* compilation generates multiple variants of the algorithm. All of them can be executed from command line as follows:

./program PATTERNS_FILE PATERN_SIZE TEXT_FILE U K Q_SIZE SIGMA

where:

* PATTERNS_FILE - location of file with patterns
* PATERN_SIZE - pattern size (e.g. 32)
* TEXT_FILE - text file
* U - AOSO parameter
* K - AOSO parameter
* Q_SIZE - q-gram size
* *SIGMA - deprecated (put some constant e.g. 5)*

For more details please refer to mentioned paper.

Example:
```bash
./approx_mag_l2_k1 /media/disk1/patterns.m16 16 /media/disk1/english.200MB 4 2 6 5
```
## Testing

### Scripts
* `generate_patterns.py` - generate patterns
* `test.py` - tests the algorithms

For testing purpose the `test.py` script can be used. 

**Note:** Patterns, datasets and algorithms default locations can be changed in the script file.

**Note:** The script (if possible) will automaticaly download datasets from Pizza&Chilli Corpus (english, proteins, sources, xml.dblp, dna of size 50MB, 100MB and 200MB).

Following parameters are supported by `test.py`:
```
  -h, --help           show this help message and exit
  -r R, --npatterns R  number of patterns
  -a A, --algorithm A  algorithm[s] to be tested
  -c C, --corpus C     corpus
  -m M, --length M     pattern length[s] (e.g. 8,16,32)
  -u U, --faosou U     FAOSO parameter U
  -k K, --faosok K     FAOSO parameter k
  -q Q, --q-gram Q     q-gram size
  -s S, --sigma S      dest. alph. size
```

Example:
```shell
python3 test.py -a approx_mag_l3_k1 -c english.50MB -r 100 -m 8,16,32,64 -u 8 -k 1,2 -q 2,3,4,6,8 -s 5
```

**Note:** If the set of parameters is incorrect (e.g. *q > m*) the errors will be produced in output (which can be ignored).

**Generate patterns**

The script `generate_patterns.py` may be used to generate patterns.

Example:
```shell
$ python generate_patterns.py english.10MB 100 8,16,32,64
Patterns generated to file ./patterns.r100/patterns.english.10MB.8.bin
Patterns generated to file ./patterns.r100/patterns.english.10MB.16.bin
Patterns generated to file ./patterns.r100/patterns.english.10MB.32.bin
Patterns generated to file ./patterns.r100/patterns.english.10MB.64.bin
```

The above command generates 100 patterns of length *m*={8, 16, 32, 64}.

**Note:** Please make sure the folders *patterns.r[r]* (where [r] is the number of patterns) exists (e.g. ./patterns.r100).

## Docker 
The simplest way you can test the algorithm is by using `docker`. 
All you need to do is to:
1. build the docker image or pull from repository
2. and run the docker container

* Pull or build the image:

	* Pull from repository steps:
	```
	docker pull rsusik/maga
	docker tag docker.io/rsusik/maga maga
	```

	* Build steps:
		* Clone the git repository:
		```shell
		git clone https://github.com/rsusik/maga maga
		cd maga
		```
		* Build the image:
		```shell
		docker build -t maga .
		```

* Run test with default parameters:
```
docker run maga
```

*This will execute test with default parameters and output the results.*

* Additionally you may provide all the parameters mentioned in section [Testing](#testing) as follows:
```
docker run maga -a approx_mag_l3_k1,approx_mag_l2_k1 -c english.100MB -r 10 -m 8,16,32,64 -u 8 -k 1,2 -q 2,3,4,6,8 -s 5
```

Above command supports only a mentioned Pizza&Chilli corpuses but you may provide your own 
datasets using -v parameter. Assuming you want to execute test for dataset `mydataset.5MB`
that is located in `/home/ok/mysets` you have to execute following command:
```
docker run -v /home/ok/mysets:/app/sets maga -a maga -c mydataset.5MB
```

## Citing
    @article {S17,
      author  = {R. Susik},
      title   = {Applying a $q$-gram based Multiple String Matching Algorithm for Approximate Matching},
      journal = {Informatyka, Automatyka, Pomiary w Gospodarce i Ochronie \'Srodowiska},
      volume  = {7},
      number  = {3},
      issn    = {2083-0157},
      year    = {2017},
      pages   = {47--50}
    }

