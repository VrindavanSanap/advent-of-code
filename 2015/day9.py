with open("day9_smol.txt", "r") as f:
  lines = f.readlines()

graph = {}
for line in lines:
  line = line[:-1]
  print(line)
  line = line.split()
  city1 = line[0]
  city2 = line[2]
  dist = line[4]
  
  print(f"City1 = {city1}, City2 = {city2}, dist = {dist}")
  break
