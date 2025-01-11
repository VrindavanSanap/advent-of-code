import ast
import re

with open("day8.txt") as f:

  lines = f.readlines()
s = 0
s_ = 0
for line in lines:
  line = f"{line[:-1]}"
  print(line, len(line),  len(re.escape(line).replace('"', '\\"')))
  print(re.escape(line).replace('"', '\\"'))
  s += len(line)
  s_ += len(re.escape(line).replace('"', '\\"')) + 2
print(s, s_, s - s_)
