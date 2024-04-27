with open("day3.txt") as f:
  data = f.read().strip()

floor_n = 0
visited = set()

x1 = 0 
y1 = 0 
x2 = 0 
y2 = 0 

# -1 santa 1 robosanta
move = -1
visited.add((0,0))
for char in data:
  
  if char == "<":
    if move == -1:
      x1 -= 1
    elif move == 1:
      x2 -= 1

  elif char == ">":
    if move == -1:
      x1 += 1
    elif move == 1:
      x2 += 1

  elif char == "^":
    if move == -1:
      y1 += 1
    elif move == 1:
      y2 += 1


  elif char == "v":
    if move == -1:
      y1 -= 1
    elif move == 1:
      y2 -= 1

  else:
    print(f"invalid char {char}")

  if move == -1: 
    visited.add((x1, y1))
  else:
    visited.add((x2, y2))

  print(f"{'S ' if move==-1 else 'R '}{char} {x1, y1} { x2, y2 } n_visited = {len(visited)}")

  move *= -1
