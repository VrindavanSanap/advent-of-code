#!/usr/bin/env python3

with open("2015_day1.txt") as f:
  data = f.read().strip()

floor_n = 0
for i, char in enumerate(data):
  if (char == "("):
    floor_n += 1
  elif (char == ")"):
    floor_n -= 1
  if floor_n == -1:
    print(f"Reached basement at character position {i + 1}!!")
    break
