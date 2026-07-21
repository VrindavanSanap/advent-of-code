with open("2019_day2.txt", "r") as f:
	data = f.read().split(',')

data = [int(i) for i in data]
print(data,  len(data))

data[1] = 12
data[2] = 2 


for i in range(0,len(data) , 4):
	opcode =   data[i]
	if opcode == 99:
		break


	x = data[i+ 1]
	y = data[i+ 2]
	d = data[i+ 3]
	print(x, y, d)
	if opcode == 1:
		res = data[x] + data[y]
		data[d] = res
	if opcode == 2:
		res = data[x] * data[y]
		data[d] = res
print(data)
