
#####################################################################
#                                                                   #
#   Engineer:   Daniele Ottaviano   daniele.ottaviano@unina.it      #
#               Stefano Mercogliano stefano.mercogliano@unina.it    #
#                                                                   #
#               University of Naples, Federico II                   #
#               July 2023                                           #
#                                                                   #
#####################################################################


This directory can be used to replicate the experiments on xpmp shown in the paper: "" 

The list of the supported benchmarks that can be executed in simulation is in the text file: 
#cat ./input_exp/bench_list.txt


To execute the test on a single benchmark run:
#./scripts/launch_bench.sh <benchmark name>

To execute all the benchmarks with one command launch (WARNING: it may take a while):
#./script/launch_all_bench.sh


To visualize the results (saved in the folder ./output_exp) you can run these python scripts:
#python3 ./python_scripts/print_bench.py <benchmark name>
#python3 ./python_scripts/print_bench_normalized.py <benchmark name>

To visualize the results of a group of benchmarks you can modify the file ./input_exp/print_list adding the benchmark to be visualized then launch:
#python3 ./python_scripts/print_bench_list.py

To visualize the normalized values of all the benchmarks run: 
#python3 ./python_scripts/print_bench_normalized_list.py


WARNING: If you want to manually compile the binary with the make command you must provide a value the following variables: BENCH PMP PLATFORM
e.g.,:
make -c ./code BECH=bsort PMR=grt PLATFORM=Small

These are the valid values:
PMR = ['no','tab','grt']
PLATFOR = ['Small','Medium_static','Medium_dynamic','Large'] 
BENCH =['adpcm_dec', 'adpcm_enc', 'anagram', 'binarysearch', 
        'bitcount', 'bitonic', 'bsort', 'cjpeg_transupp', 
        'cjpeg_wrbmp', 'countnegative', 'cover', 'fac', 
        'g723_enc', 'gsm_dec', 'gsm_enc', 'h264_dec', 
        'huff_dec', 'huff_enc', 'insertsort', 'jfdctint', 
        'lift', 'matrix1', 'ndes', 'petrinet', 
        'powerwindow', 'prime', 'readwrite', 'recursion', 
        'rijndael_dec', 'rijndael_enc', 'sha', 'statemate'] 