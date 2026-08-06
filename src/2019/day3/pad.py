import numpy as np

# Original grid
grid = np.array([[1, 2], 
                 [3, 4]])

columns_to_add = 2 

expanded_grid = np.pad(grid, ((0, 0), (0, columns_to_add)), mode='constant', constant_values=0)


print(expanded_grid)

