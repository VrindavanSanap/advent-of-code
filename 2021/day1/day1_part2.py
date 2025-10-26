import numpy as np

with open("day1.txt") as f:
  data = f.read().split()


data = np.array(data, dtype=float)

rolling_sum = np.convolve(data, np.ones(3), mode='valid')
num_inc_rolling_sum = (rolling_sum[:-1] < rolling_sum[1:]).sum()
print(num_inc_rolling_sum) 
