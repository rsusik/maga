# MAG for approximate pattern matching (MAGA)

## About
MAGA (MAG for approximate pattern matching) is algorithm designed for approximage pattern matching. The algorithm is based on idea of partitioning into exact pattern matching. The MAGA is based on previous work MAG (http://www.stringology.org/event/2014/p07.html) which was designed for exact multiple pattern matching. MAGA adopts the algorithm to approximate pattern matching problem.

This is a source code of MAGA that was written for research purpose and has a minimal error checking. The code may be not be very readable and comments may not be adequate. There is no warranty, your use of this code is at your own risk.

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

