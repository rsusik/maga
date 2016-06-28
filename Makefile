
approx_mag_dna_opt_l3_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l3 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_dna_opt_l3_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l3_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l3 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_dna_opt_l3_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_dna_opt_l3_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l3 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_dna_opt_l3_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l3_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l3 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_dna_opt_l3_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l3_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l3 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_dna_opt_l3_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l2_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l2 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_dna_opt_l2_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l2_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l2 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_dna_opt_l2_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_dna_opt_l2_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l2 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_dna_opt_l2_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l2_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l2 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_dna_opt_l2_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l2_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_opt_l2 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_dna_opt_l2_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l4_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_dna_l4_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l4_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_dna_l4_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_dna_l4_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_dna_l4_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l4_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_dna_l4_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l4_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_dna_l4_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l3_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_dna_l3_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l3_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_dna_l3_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_dna_l3_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_dna_l3_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l3_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_dna_l3_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l3_k1_sse: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=1 -msse3 -std=c++11 -O3 -o approx_mag_dna_l3_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l3_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_dna_l3_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l2_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_dna_l2_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l2_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_dna_l2_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_dna_l2_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_dna_l2_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l2_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_dna_l2_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_l2_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_dna_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_dna_l2_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l4_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_l4_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l4_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_l4_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_l4_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_l4_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l4_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_l4_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l4_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=4 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_l4_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l3_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_l3_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l3_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_l3_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_l3_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_l3_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l3_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_l3_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l3_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=3 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_l3_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l2_k4: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=4 -std=c++11 -O3 -o approx_mag_l2_k4 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l2_k3: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=3 -std=c++11 -O3 -o approx_mag_l2_k3 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 

approx_mag_l2_k2: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=2 -std=c++11 -O3 -o approx_mag_l2_k2 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l2_k1: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=1 -std=c++11 -O3 -o approx_mag_l2_k1 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_l2_k0: approx_mag_dyn.cpp
	g++ -D Q_GRAM_UTIL_V=q_gram_utilities_l_bits -D Q_GRAM_UTIL_NEW_L=2 -D K_DIFF=0 -std=c++11 -O3 -o approx_mag_l2_k0 approx_mag_dyn.cpp -L"./libraries/asmlib/" -laelf64 
	
approx_mag_dna_opt_l2: approx_mag_dna_opt_l2_k0 approx_mag_dna_opt_l2_k1 approx_mag_dna_opt_l2_k2 approx_mag_dna_opt_l2_k3 approx_mag_dna_opt_l2_k4

approx_mag_dna_opt_l3: approx_mag_dna_opt_l3_k0 approx_mag_dna_opt_l3_k1 approx_mag_dna_opt_l3_k2 approx_mag_dna_opt_l3_k3 approx_mag_dna_opt_l3_k4

approx_mag_dna_opt: approx_mag_dna_opt_l2 approx_mag_dna_opt_l3 

approx_mag_dna_l2: approx_mag_dna_l2_k0 approx_mag_dna_l2_k1 approx_mag_dna_l2_k2 approx_mag_dna_l2_k3 approx_mag_dna_l2_k4

approx_mag_dna_l3: approx_mag_dna_l3_k0 approx_mag_dna_l3_k1 approx_mag_dna_l3_k2 approx_mag_dna_l3_k3 approx_mag_dna_l3_k4

approx_mag_dna_l4: approx_mag_dna_l4_k0 approx_mag_dna_l4_k1 approx_mag_dna_l4_k2 approx_mag_dna_l4_k3 approx_mag_dna_l4_k4

approx_mag_dna: approx_mag_dna_l2 approx_mag_dna_l3 approx_mag_dna_l4

approx_mag_l2: approx_mag_l2_k0 approx_mag_l2_k1 approx_mag_l2_k2 approx_mag_l2_k3 approx_mag_l2_k4

approx_mag_l3: approx_mag_l3_k0 approx_mag_l3_k1 approx_mag_l3_k2 approx_mag_l3_k3 approx_mag_l3_k4

approx_mag_l4: approx_mag_l4_k0 approx_mag_l4_k1 approx_mag_l4_k2 approx_mag_l4_k3 approx_mag_l4_k4

approx_mag: approx_mag_l2 approx_mag_l3 approx_mag_l4
	
all: approx_mag approx_mag_dna approx_mag_dna_opt

clean:
	rm -f approx_mag_dna_opt_l3_k4 approx_mag_dna_opt_l3_k3 approx_mag_dna_opt_l3_k2 approx_mag_dna_opt_l3_k1 approx_mag_dna_opt_l3_k0 approx_mag_dna_opt_l2_k4 approx_mag_dna_opt_l2_k3 approx_mag_dna_opt_l2_k2 approx_mag_dna_opt_l2_k1 approx_mag_dna_opt_l2_k0 approx_mag_dna_l4_k4 approx_mag_dna_l4_k3 approx_mag_dna_l4_k2 approx_mag_dna_l4_k1 approx_mag_dna_l4_k0 approx_mag_dna_l3_k4 approx_mag_dna_l3_k3 approx_mag_dna_l3_k2 approx_mag_dna_l3_k1 approx_mag_dna_l3_k0 approx_mag_dna_l2_k4 approx_mag_dna_l2_k3 approx_mag_dna_l2_k2 approx_mag_dna_l2_k1 approx_mag_dna_l2_k0 approx_mag_l4_k4 approx_mag_l4_k3 approx_mag_l4_k2 approx_mag_l4_k1 approx_mag_l4_k0 approx_mag_l3_k4 approx_mag_l3_k3 approx_mag_l3_k2 approx_mag_l3_k1 approx_mag_l3_k0 approx_mag_l2_k4 approx_mag_l2_k3 approx_mag_l2_k2 approx_mag_l2_k1 approx_mag_l2_k0 *.exe *.pdb