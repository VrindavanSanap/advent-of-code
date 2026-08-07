#!/usr/bin/env python3

with open("2015_day2.txt") as f:
  data = f.read().split()

total_ribbon_size = 0
for line in data:
  ribbon_size= 0 
  dims = [int(i) for i in line.split("x")]
  s1 = dims[0] 
  s2 = dims[1]
  s3 = dims[2] 
  ribbon_size += s1 * s2 * s3
  ribbon_size += 2 * sum([s1, s2, s3])
  ribbon_size -= 2 * max(s1, s2, s3)
  total_ribbon_size +=ribbon_size 

print(total_ribbon_size)
