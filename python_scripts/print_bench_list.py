import pandas as pd
import matplotlib.pyplot as plt
import os
import sys

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.dirname(script_dir)

input_name = "print_list" #sys.argv[1]
file_name = input_name + ".txt"
input_path = os.path.join(project_dir,"input_exp")
output_path = os.path.join(project_dir,"output_exp")

# Define the path to the filelist.txt
filelist_path = os.path.join(input_path,file_name)

# Read the first column (first entry) from each line in filelist.txt
with open(filelist_path, 'r') as filelist_file:
    input_files = [line.split()[0] + '.txt' for line in filelist_file]

print(input_files)

# Initialize lists to store data
all_platforms = []
all_pmr_types = []
all_times = []

# Process data from each input file
for input_file in input_files:
    platforms = []
    pmr_types = []
    times = []

    # Read and parse the data from the current input file
    with open(os.path.join(output_path,input_file), 'r') as f:
        current_platform = None
        current_pmr_type = None
        current_time = None

        for line in f:
            line = line.strip()
            if line.startswith('[PLATFORM:'):
                current_platform = line.strip('[PLATFORM:]')
            elif line.startswith('[PMR:'):
                current_pmr_type = line.strip('[PMR: ]')
            elif line.startswith('time:'):
                current_time = int(line.strip('time: '))
                if current_pmr_type == 'pmr_no' or current_pmr_type == 'pmr_grt':
                    current_time = current_time / 40000
                elif current_pmr_type == 'pmr_tab':
                    current_time = current_time / 35000
                platforms.append(current_platform)
                pmr_types.append(current_pmr_type)
                times.append(current_time)

    all_platforms.append(platforms)
    all_pmr_types.append(pmr_types)
    all_times.append(times)

# Create subplots for each input file
num_files = len(input_files)
plt.figure(figsize=(15, 5 * num_files))  # Adjust the figure size as needed

for i in range(num_files):
    plt.subplot(num_files, 1, i + 1)

    # Create a pandas DataFrame for the current file's data
    data = {'PLATFORM': all_platforms[i], 'PMR': all_pmr_types[i], 'TIME': all_times[i]}
    df = pd.DataFrame(data)

    # Get unique platforms and PMR types
    unique_platforms = df['PLATFORM'].unique()
    unique_pmr_types = df['PMR'].unique()

    # Set up plot parameters
    num_platforms = len(unique_platforms)
    bar_width = 0.2
    x_ticks = range(num_platforms)
    pastel_colors = ['#87CEEB', '#FFD700', '#FFB6C1']  # Define your pastel colors here

    legend_labels = []  # Initialize a list to store renamed legend labels

    for j, pmr_type in enumerate(unique_pmr_types):
        pmr_data = df[df['PMR'] == pmr_type]
        time_values = [pmr_data[pmr_data['PLATFORM'] == platform]['TIME'].values[0] for platform in unique_platforms]
        if pmr_type == 'pmr_no':
            pmr_label = 'NO'
        elif pmr_type == 'pmr_tab':
            pmr_label = 'TAB'
        elif pmr_type == 'pmr_grt':
            pmr_label = 'GRT'
        else:
            pmr_label = pmr_type  # Keep the original label if it doesn't match 'pmr_no,' 'pmr_tab,' or 'pmr_grt'
        plt.bar(
            [x + j * bar_width for x in x_ticks],
            time_values,
            width=bar_width,
            label=pmr_label,  # Use the renamed label
            color=pastel_colors[j],
            edgecolor='black',  # Add black borders/margins to bars
            linewidth=1.2,  # Adjust the linewidth as needed
        )
        legend_labels.append(pmr_label)  # Store the renamed label in the legend_labels list

    # Add grid lines
    plt.grid(axis='y', linestyle='--', alpha=0.4)

    # Customize plot labels and legend
    plt.xlabel('Platform')
    plt.ylabel('Time (ms)')
    plt.title(f'{input_files[i][:-4]}')  # Truncate the last 4 characters (".txt" extension)
    plt.xticks([x + (len(unique_pmr_types) - 1) * bar_width / 2 for x in x_ticks], unique_platforms)  # Keep the labels as they are
    plt.legend(legend_labels)  # Use the renamed legend labels

plt.tight_layout()
plt.show()

