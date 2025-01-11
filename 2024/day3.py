import re
regex_pattern = r"(mul\(\-?\d+,\-?\d+\))"
with open("day3.txt", "r") as f:
  corrupted_memory = f.read()

print(corrupted_memory)
matches = re.finditer(regex_pattern, corrupted_memory)
total_sum = 0
for match in matches:
  mul_ins = (match.group())
  numbers = [int(n) for n in (re.findall(r"[\d]+", mul_ins))]
  total_sum += numbers[0] * numbers[1]
  print(total_sum)
