#!/usr/bin/env python3
import ast

with open("2015_day8.txt") as f:

  lines = f.readlines()
s = 0
s_ = 0
for line in lines:
  line = line[:-1]
  print(line, len(line), len(ast.literal_eval(line)))
  s += len(line)
  s_ += len(ast.literal_eval(line))
print(s - s_)
