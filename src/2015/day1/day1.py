#!/usr/bin/env python3

with open("./day1.txt") as f:
  data = f.read().strip()

floor_n = 0
floor_n += data.count("(")
floor_n -= data.count(")")
print(f"Floor no: {floor_n}")
