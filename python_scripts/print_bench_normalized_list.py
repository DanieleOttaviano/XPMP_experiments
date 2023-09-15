import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import os
import sys

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.dirname(script_dir)

input_name = "bench_list" #sys.argv[1]
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
                if current_pmr_type == 'pmr_no':
                    pmr_no_time = current_time
                    current_time /= pmr_no_time
                elif current_pmr_type == 'pmr_tab':
                    if pmr_no_time is not None:
                        current_time = (current_time/pmr_no_time)*(40000/35000)
                elif current_pmr_type == 'pmr_grt':
                    if pmr_no_time is not None:
                        current_time /= pmr_no_time 
                platforms.append(current_platform)
                pmr_types.append(current_pmr_type)
                times.append(current_time)

    all_platforms.append(platforms)
    all_pmr_types.append(pmr_types)
    all_times.append(times)

# Get the number of input files
num_files = len(input_files)

# Define the number of rows and columns for the grid
num_rows = num_files // 4  # You can adjust the number of rows as needed
num_columns = 4

# Create a figure and subplots
fig, axes = plt.subplots(num_columns, num_rows, figsize=(2 * num_rows,5))

max_time = {}
min_time = {}

for i in range(num_files):
    # Determine the row and column index for the current subplot
    col_idx = i // num_columns
    row_idx = i % num_columns

    # Get the current subplot axis
    ax = axes[row_idx, col_idx]

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
    pastel_colors = ['#D8F2E9','#87CEEB', '#AFCAE6', '#9592AD']  # Define your pastel colors here
    
    # Set up labels for the legend
    legend_labels = []
    legend_labels.append('NO')
    legend_labels.append('TABLE')

    # Retrieve only GRT data
    for j, platform in enumerate(unique_platforms):
        pmr_data = df[df['PMR']=='pmr_grt']
        platform_data = pmr_data[pmr_data['PLATFORM'] == platform]
        time_values = platform_data['TIME'] 
        ax.bar(
            [j * bar_width],
            time_values,
            width=bar_width,
            label='PLATFORM',  # Use the platform as the legend label
            color=pastel_colors[j],
            edgecolor='black',
            linewidth=2,
        )

    platform_lables=['S','MS','MD','L']
    for label in platform_lables:
        legend_labels.append(label) 


    # Define custom y-tick positions and their attributes
    custom_lines = [
        {'position': 1, 'label': 'NO', 'color': '#FFD700', 'linestyle': '-', 'alpha': 1, 'linewidth': 2},
        {'position': 1.1428571429, 'label': 'TAB', 'color': '#f20a0a', 'linestyle': '-', 'alpha': 1, 'linewidth': 2},
    ]
    # Loop through each custom line and add it to the plot
    for line_attrs in custom_lines:
        position = line_attrs['position']
        label = line_attrs['label']
        color = line_attrs['color']
        linestyle = line_attrs['linestyle']
        alpha = line_attrs['alpha']
        linewidth = line_attrs['linewidth']
        # Customize the appearance of the custom y-tick line
        ax.axhline(position, color=color, linestyle=linestyle, alpha=alpha, linewidth=linewidth)
    
    # Control the standard gridlines
    ax.yaxis.grid(True, linestyle='--', alpha=0.5)  # Customize standard gridlines here
    grid_positions = [1, 1.5, 2, 2.5]
    ax.set_yticks(grid_positions)

    # Customize subplot titles
    ax.set_title(f'{input_files[i][:-4]}')  # Truncate the last 4 characters (".txt" extension)
    
    ax.set_xticks([])
    ax.set_ylim(0.5,2.7)

    for platform in unique_platforms:       
        # Filter the DataFrame for the 'pmr_grt' with the current platform
        pmr_data = df[(df['PMR'] == 'pmr_grt') & (df['PLATFORM'] == platform)]

        if not pmr_data.empty:
            # Calculate and store the maximum and minimum times for the current platform
            if platform not in max_time:
                max_time[platform] = [pmr_data['TIME'].max()]
                min_time[platform] = [pmr_data['TIME'].min()]
            else:
                max_time[platform].append(pmr_data['TIME'].max())
                min_time[platform].append(pmr_data['TIME'].min())

# Calculate and print the maximum and minimum times for each platform across all input files
for platform, max_values in max_time.items():
    min_values = min_time[platform]
    overall_max_time = max(max_values)
    overall_min_time = min(min_values)
    print(f"Platform: {platform}\n Overall Max Overhead: {overall_max_time}\n Overall Min Overhead: {overall_min_time}")

# Add a legend
fig.legend(legend_labels, loc='upper right')

# Adjust the figure boundaries
fig.subplots_adjust(left=0.04, right=0.94)

# Add common x and y labels for the entire figure
#fig.text(0.5, 0.02, 'Platform', ha='center', va='center')
fig.text(0.02, 0.5, 'Normalized Execution Time', ha='center', va='center', rotation='vertical')

# Adjust the layout and display the figure
plt.tight_layout()
plt.show()
