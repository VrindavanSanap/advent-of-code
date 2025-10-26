#!/usr/bin/python3
with open("day2.txt") as f:
  lines = f.readlines()

def result(your, their):
  results = [[0, -1, 1], # R | R P S
             [1, 0, -1], # P | R P S
             [-1, 1, 0]] # S | R P S
  return results[your][their]
total_score = 0 
count = 0 
for line in lines:
  score = 0 
  their = ord(line[0]) - 65
  your = ord(line[2]) - 65 - 26 + 3
  score += your + 1
  res = result(your, their)

  if res == 1: # you won
    score += 6

  elif res == 0:
    score += 3
  count += 1 
  print(f"shape score {your + 1} match score {score - your - 1} total score {score}")
  print(count, your, their, score)
  total_score += score
  print(total_score)
