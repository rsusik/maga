# MAG for approximate pattern matching (MAGA)

## About

This is a source code of MAG for approximate pattern matching (MAGA). It was written for research purpose and has a minimal error checking. The code may be not very readable and comments may not be adequate. There is no warranty, your use of this code is at your own risk. MAGA is based on MAG algorithm (http://www.stringology.org/event/2014/p07.html).

There are multiple variants of MAG algorithm, please refer to mentioned article for more details about each of them.

## Requirements

* C++ compiler compatible with C++11 standard
* Unix based 64-bit (should also work on 32-bit but performance is worse)

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

*For testing purpose mag_test.py can be used.*

## Authors
* Robert Susik

