import time
import copy

with open("2020_day8.txt", "r") as f:
	lines = f.read().split("\n")

num_lines = len(lines)
print(num_lines)
def get_acc(lines, visited):
	global num_lines
	accumulator = 0
	ip = 0
	while True:
		if ip == num_lines:
			return True, accumulator
		if visited[ip] == True:break
		visited[ip] = True
		line = lines[ip]
		instruction = line[0]
		arguemnt =int(line[1])
		if (instruction == "nop"):
			pass
		elif(instruction == "acc"):
			accumulator += arguemnt
		elif(instruction == "jmp"):
			ip += arguemnt
			continue

		ip+= 1

	return False, accumulator

visited = [False for line in lines]
lines = [line.split() for line in lines]
i = 0
temp_lines = copy.deepcopy(lines)
temp_visited = copy.deepcopy(visited)
print(lines)
while i<num_lines:
	
	lines = copy.deepcopy(temp_lines)
	visited = copy.deepcopy(temp_visited)


	while i<num_lines:
		if (lines[i][0] == 'nop'):
			lines[i][0] = 'jmp'
			i+=1
			status, acc = get_acc(lines, visited)

			if(status):
				print("Success:", acc)
				exit(0)
			break

		elif (lines[i][0] == 'jmp'):
			lines[i][0] = 'nop'
			i+=1
			status, acc = get_acc(lines, visited)

			if(status):
				print("Success:", acc)
				exit(0)

			break
	
		else:
			i+=1
