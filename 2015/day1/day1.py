#!/usr/bin/env python3

with open("day1.txt") as f:
  data = f.read().strip()

floor_n = 0
for char in data:
  if (char == "("):
    floor_n += 1
  elif (char == ")"):
    floor_n -= 1
  print(f"Floor no: {floor_n}")
