import sys
import os

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.dirname(script_dir)


file_name = "bench_list.txt"
file_path = os.path.join(project_dir,"input_exp",file_name)

# Read the data from the text file and store it in a dictionary
data_dict = {}
with open(file_path, "r") as file:
    for line in file:
        columns = line.strip().split()  # Split each line into columns
        if len(columns) == 2:
            key, value = columns
            data_dict[key] = value

# Input the value you want to look up
input_key = sys.argv[1] #input("Enter a value from the first column: ")

# Look up the corresponding value in the second column
if input_key in data_dict:
    result = data_dict[input_key]
    print(f"{result}")
else:
    print("Value not found in the first column.")

