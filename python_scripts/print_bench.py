import pandas as pd
import matplotlib.pyplot as plt
import os
import sys

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.dirname(script_dir)

input_name = sys.argv[1]
file_name = input_name + ".txt"
file_path = os.path.join(project_dir,"output_exp",file_name)

print(file_path)

# Initialize lists to store data
platforms = []
pmr_types = []
times = []

# Read and parse the data from the current input file
with open(file_path, 'r') as f:
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
            current_time = float(line.strip('time: '))
            if current_pmr_type == 'pmr_no' or current_pmr_type == 'pmr_grt':
                current_time = current_time / 40000
            elif current_pmr_type == 'pmr_tab':
                current_time = current_time / 35000

            platforms.append(current_platform)
            pmr_types.append(current_pmr_type)
            times.append(current_time)

    
# Create a pandas DataFrame for the current file's data
data = {'PLATFORM': platforms, 'PMR': pmr_types, 'TIME': times}
df = pd.DataFrame(data)

# Get unique platforms and PMR types
unique_platforms = df['PLATFORM'].unique()
unique_pmr_types = df['PMR'].unique()

# Set up plot parameters
num_platforms = len(unique_platforms)
bar_width = 0.2
x_ticks = range(num_platforms)
pastel_colors = ['#87CEEB', '#FFD700', '#FFB6C1']  
legend_labels = [] 

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
        pmr_label = pmr_type 
    plt.bar(
        [x + j * bar_width for x in x_ticks],
        time_values,
        width=bar_width,
        label=pmr_label,  
        color=pastel_colors[j],
        edgecolor='black',  
        linewidth=1.2,  
    )
    legend_labels.append(pmr_label)

# Add grid lines
plt.grid(axis='y', linestyle='--', alpha=0.4)

# Customize plot labels and legend
plt.xlabel('Platform')
plt.ylabel('Time (ms)')
plt.title(input_name)  # Truncate the last 4 characters (".txt" extension)
plt.xticks([x + (len(unique_pmr_types) - 1) * bar_width / 2 for x in x_ticks], unique_platforms)  # Keep the labels as they are
plt.legend(legend_labels)  # Use the renamed legend labels

plt.tight_layout()
plt.show()

