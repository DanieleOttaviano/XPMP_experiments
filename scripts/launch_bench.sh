#!/bin/bash

script_dir=$(dirname -- "$( readlink -f -- "$0"; )";)
date_exp_dir=$(dirname "$script_dir")
project_dir=$(dirname "$date_exp_dir")

PLATFORM_vector=("Small" "Medium_static" "Medium_dynamic" "Large")
PMR_vector=("no" "tab" "grt")

# Check if at least BENCHNAME was provided
if [ $# -lt 1 ]; then
	echo "Usage: $0 <benchmark_name> (see ../input_exp/bench_list.txt)"
	exit 1
fi

BENCHNAME="$1"

SIM_CYCLES=$(python3 ${date_exp_dir}/python_scripts/take_sim_cycles.py ${BENCHNAME})

echo EXPERIMENT
echo Benchmark: ${BENCHNAME} 
echo sim_cycles: ${SIM_CYCLES}

# Save old results
cp $date_exp_dir/output_exp/${BENCHNAME}.txt $date_exp_dir/output_exp/${BENCHNAME}_old.txt
sed -i '1,$d' $date_exp_dir/logs/*_log.txt
sed -i '1,$d' $date_exp_dir/output_exp/${BENCHNAME}.txt

# For each PLATFORM 
for PLATFORM in "${PLATFORM_vector[@]}"; do
	echo "[PLATFORM: ${PLATFORM}]" >> $date_exp_dir/output_exp/${BENCHNAME}.txt
	
	# For each PMR technique
	for PMR_TYPE in "${PMR_vector[@]}"; do
		echo "[PMR: pmr_${PMR_TYPE}]" >>  $date_exp_dir/output_exp/${BENCHNAME}.txt	
		
		echo Compiling the platform [${PLATFORM}] [PMR = ${PMR_TYPE}] ...
		cp $date_exp_dir/platforms/cv32e41s_core_pmr_${PMR_TYPE}.sv $project_dir/rtl/cv32e41s_core/cv32e41s_core.sv
		cp $date_exp_dir/platforms/cv32e41s_demo_system_memless_${PLATFORM}.sv $project_dir/rtl/demo_system/cv32e41s_demo_system_memless.sv
		make -C $project_dir >> $date_exp_dir/logs/platform_log.txt 

		echo Compiling the binary ...
		make -C $date_exp_dir/code clean >> $date_exp_dir/logs/clean_log.txt
		make -C $date_exp_dir/code BENCH=${BENCHNAME} PMR=${PMR_TYPE} PLATFORM=${PLATFORM} >> $date_exp_dir/logs/binary_log.txt
		
		echo Launching the simulation ...
		# Launch the test and save results
		yes "" | $project_dir/uCup_top_run bin_path "$date_exp_dir/code/bin/xpmp_test.bin" sim_cycles ${SIM_CYCLES}  mem_size 1048576 terminal_show | grep time  | tee -a $date_exp_dir/output_exp/${BENCHNAME}.txt 
	done
done

echo Printing Result ...
cat ${date_exp_dir}/output_exp/${BENCHNAME}.txt
python3 ${date_exp_dir}/python_scripts/print_bench_normalized.py ${BENCHNAME}
