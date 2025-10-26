with open("day3.txt") as f:
  data = f.read().strip()

floor_n = 0
visited = set()
x = 0 
y = 0 

for char in data:

  if char == "<":
      x -= 1
  elif char == ">":
      x += 1  
  elif char == "^":
      y += 1
  elif char == "v":
      y -= 1
  else:
    print(f"invalid char {char}")
  visited.add((x, y))

  print(f"{char} {x, y} n_visited = {len(visited)}")

