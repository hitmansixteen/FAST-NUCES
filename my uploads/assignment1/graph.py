import matplotlib.pyplot as plt
import numpy as np


sum_times = {'int32': [0] * 6, 'float32': [0] * 6, 'int64': [0] * 6, 'float64': [0] * 6}
counts = {'int32': [0] * 6, 'float32': [0] * 6, 'int64': [0] * 6, 'float64': [0] * 6}


with open('graph.txt', 'r') as file:
    for line in file:
        parts = line.split()
        opcode = int(parts[0])
        datatype = int(parts[1])
        readtime = float(parts[2])
        calctime = float(parts[3])
        writetime = float(parts[4])
        totaltime = readtime + calctime + writetime

        
        sum_times_index = opcode - 1
        counts_index = opcode - 1
        if datatype == 1:  
            sum_times['int32'][sum_times_index] += totaltime
            counts['int32'][counts_index] += 1
        elif datatype == 2:  
            sum_times['float32'][sum_times_index] += totaltime
            counts['float32'][counts_index] += 1
        elif datatype == 3:  
            sum_times['int64'][sum_times_index] += totaltime
            counts['int64'][counts_index] += 1
        elif datatype == 4:  
            sum_times['float64'][sum_times_index] += totaltime
            counts['float64'][counts_index] += 1


average_times = {datatype: [sum_time / count if count != 0 else 0 for sum_time, count in zip(sum_times[datatype], counts[datatype])] for datatype in sum_times}


plt.figure(figsize=(10, 6))


for i, (datatype, times) in enumerate(average_times.items()):
    plt.subplot(2, 2, i+1)
    bars = plt.bar(range(1, len(times) + 1), times, label=datatype, color='skyblue')
    plt.xlabel('Opcode')
    plt.ylabel('Average Time (seconds)')
    plt.title(f'Average Time vs Opcode for {datatype} Data Type')
    plt.xticks(np.arange(1, len(times) + 1, 1))
    plt.grid(True)

    
    for bar in bars:
        height = bar.get_height()
        plt.text(bar.get_x() + bar.get_width() / 2, height, round(height, 2), ha='center', va='bottom')

plt.tight_layout()
plt.show()

