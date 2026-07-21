import copy
with open("2019_day2.txt", "r") as f:
	data = f.read().split(',')

data = [int(i) for i in data]
og_data = copy.deepcopy(data)
for j in range(100):
	for k in range(100):
		data = copy.deepcopy(og_data)
		data[1] = j
		data[2] = k


		for i in range(0,len(data) , 4):
			opcode =   data[i]
			if opcode == 99:
				break


			x = data[i+ 1]
			y = data[i+ 2]
			d = data[i+ 3]
			if opcode == 1:
				res = data[x] + data[y]
				data[d] = res
			if opcode == 2:
				res = data[x] * data[y]
				data[d] = res
				
		if (data[0] == 19690720):
			print(j, k)
			print(100*j+ k)
			break

