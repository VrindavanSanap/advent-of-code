import numpy as np

path = "R8,U5,L5,D3".split(",")
grid = np.array([[0]]);
x = 0
y = 0
for move in path:
  
  direction = move[0]
  distance = int(move[1])
  print(direction, distance)
  print(x, y)
  print(grid.shape)      
  if direction == 'R':
    new_x = distance + x
    n_expand = new_x - grid.shape[1] + 1
    if (n_expand > 0):
      grid = np.pad(grid, ((0, 0), (0, n_expand )), mode='constant', constant_values = 0)
    x = new_x
  if direction == 'D':
    new_y = distance + y
    n_expand = new_y - grid.shape[0] + 1
    if (n_expand > 0):
      grid = np.pad(grid, ((0, 0), (n_expand , 0)), mode='constant', constant_values = 0)
    y  = new_y
 
  break

