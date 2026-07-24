with open("2020_day8.txt", "r") as f:
	lines = f.read().split("\n")

print(lines[:5])
accumulator = 0
visited = [False for line in lines]
lines = [line.split() for line in lines]
ip = 0
while True:
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

print(accumulator)
