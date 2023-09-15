# XPMP Experiments Repository 


****

> **Engineers:** 
> > Daniele Ottaviano ([daniele.ottaviano@unina.it](mailto:daniele.ottaviano@unina.it)) 
> 
> > Stefano Mercogliano ([stefano.mercogliano@unina.it](mailto:stefano.mercogliano@unina.it))
>
> **University:** University of Naples, Federico II
>
>  <img src="https://upload.wikimedia.org/wikipedia/commons/a/a1/Napoli_university_logo.svg" alt="University Logo" width="50"/>

****

> [!WARNING]
> This repository is intended to be a subdirectory of the project [Granp4sso/cv32e41s\_SoC\_env](https://github.com/Granp4sso/cv32e41s_SoC_env).

****


**This repository aims is to replicate the experiments on XPMP as shown in the associated paper: [Link to the Paper](https://your-paper-url.com)**

## How to Use

To run a test of the xpmp on a single benchmark run:

```
./scripts/launch_bench.sh <benchmark name>
```

To execute all the benchmarks with one command launch (WARNING: it may take a while):

```
./script/launch_all_bench.sh
```

To visualize the results (saved in the folder ./output_exp) you can run these python scripts:

```
python3 ./python_scripts/print_bench.py <benchmark name>
python3 ./python_scripts/print_bench_normalized.py <benchmark name>
```

To visualize the results of a group of benchmarks you can modify the file __./input_exp/print\_list__ adding the benchmark to be visualized then launch:

```
python3 ./python_scripts/print_bench_list.py
```

To visualize the normalized values of all the benchmarks (as shown in the paper) run:

```
python3 ./python_scripts/print_bench_normalized_list.py
```



If you want to manually compile the binary you must provide a value for the variables **BENCH**, **PMP** and **PLATFORM**:

```
make -c ./code BECH=<banhmark> PMR=<pmr mechanism> PLATFORM=<platform>
```


These are the valid values:

```
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
```

## Supported Benchmarks

The list of the supported benchmarks:

```
adpcm_dec      
adpcm_enc      
anagram        
binarysearch   
bitcount       
bitonic        
bsort          
cjpeg_transupp 
cjpeg_wrbmp    
countnegative  
cover          
fac            
g723_enc       
gsm_dec        
gsm_enc        
h264_dec       
huff_dec       
huff_enc       
insertsort     
jfdctint       
lift           
matrix1        
ndes           
petrinet       
powerwindow    
prime          
readwrite      
recursion      
rijndael_dec   
rijndael_enc   
sha            
statemate       
```

