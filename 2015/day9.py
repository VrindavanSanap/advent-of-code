from copy import deepcopy
with open("day9_smol.txt", "r") as f:
  lines = f.readlines()
print(lines)
graph = {}
for line in lines:
  line = line[:-1]
  print(line)
  line = line.split()
  city1 = line[0]
  city2 = line[2]
  dist = line[4]
  if city1 in graph:
    graph[city1].append((city2, int(dist)))
  else:
    graph[city1] = [((city2, int(dist)))]


  if city2 in graph:
    graph[city2].append((city1, int(dist)))
  else:
    graph[city2] = [((city1, int(dist)))]

 
graph_copy = deepcopy(graph)

for g in (graph):
  print(g, graph[g])

graph_copy['London'].pop()



