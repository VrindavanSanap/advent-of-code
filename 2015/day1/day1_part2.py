with open("day1.txt") as f:
  data = f.read().strip()

floor_n = 0
for i, char in enumerate(data):
  if (char == "("):
    floor_n += 1
  elif (char == ")"):
    floor_n -= 1
  print(f"i={i} Floor: {floor_n}")
  if floor_n == -1:
    print(f"Reached basement!!")
    break
