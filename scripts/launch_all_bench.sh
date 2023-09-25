#!/bin/bash

script_dir=$(dirname -- "$( readlink -f -- "$0"; )";)
date_exp_dir=$(dirname "$script_dir")
code_dir=$(dirname "$date_exp_dir")
extern_dir=$(dirname "$code_dir")
project_dir=$(dirname "$extern_dir")

PLATFORM_vector=("Small" "Medium_static" "Medium_dynamic" "Large")
PMR_vector=("no" "tab" "grt")

# Check if the input file exists
input_file="${date_exp_dir}/input_exp/bench_list.txt"

if [ ! -f "$input_file" ]; then
    echo "Input file '$input_file' not found."
    exit 1
fi

# For each Benchmark
while read -r -a columns; do
	BENCHNAME="${columns[0]}"
	echo "BENCHNAME: $BENCHNAME"
	# Save old results
	cp $date_exp_dir/output_exp/${BENCHNAME}.txt $date_exp_dir/output_exp/${BENCHNAME}_old.txt
	sed -i '1,$d' $date_exp_dir/output_exp/${BENCHNAME}.txt
done < "$input_file"
sed -i '1,$d' $date_exp_dir/logs/*_log.txt

echo EXPERIMENT START ...

# For each PLATFORM 
for PLATFORM in "${PLATFORM_vector[@]}"; do	
	# For each PMR technique
	for PMR_TYPE in "${PMR_vector[@]}"; do
		# Compile the platform
		echo Compiling the platform [${PLATFORM}] [PMR = ${PMR_TYPE}] ...
		cp $date_exp_dir/platforms/cv32e41s_core_pmr_${PMR_TYPE}.sv $project_dir/rtl/cv32e41s_core/cv32e41s_core.sv
		cp $date_exp_dir/platforms/cv32e41s_demo_system_memless_${PLATFORM}.sv $project_dir/rtl/demo_system/cv32e41s_demo_system_memless.sv
		make -C $project_dir >> $date_exp_dir/logs/platform_log.txt 

		# For each Benchmark
		while read -r -a columns; do
			BENCHNAME="${columns[0]}"
			SIM_CYCLES=$(python3 ${date_exp_dir}/python_scripts/take_sim_cycles.py ${BENCHNAME})

			echo "[PLATFORM: ${PLATFORM}]" >> $date_exp_dir/output_exp/${BENCHNAME}.txt
			echo "[PMR: pmr_${PMR_TYPE}]" >>  $date_exp_dir/output_exp/${BENCHNAME}.txt	
			
			echo Compiling the binary for ${BENCHNAME} ...
			make -C $date_exp_dir/code clean >> $date_exp_dir/logs/clean_log.txt
			make -C $date_exp_dir/code BENCH=${BENCHNAME} PMR=${PMR_TYPE} PLATFORM=${PLATFORM} >> $date_exp_dir/logs/binary_log.txt
		
			echo Launching the simulation for ${SIM_CYCLES} cycles ...
			# Launch the test and save results
			yes "" | $project_dir/uCup_top_run bin_path "$date_exp_dir/code/bin/xpmp_test.bin" sim_cycles ${SIM_CYCLES}  mem_size 1048576 terminal_show | grep time  | tee -a $date_exp_dir/output_exp/${BENCHNAME}.txt 

		done < "$input_file"
	done
done
