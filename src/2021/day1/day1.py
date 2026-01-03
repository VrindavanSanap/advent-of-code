import numpy as np

with open("day1.txt") as f:
  data = f.read().split()

data = [int(i) for i in data]
data = np.array(data)
print((data[:-1] < data[1:]).sum())
