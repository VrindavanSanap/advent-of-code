with open("2019_day5.txt", "r") as f:
	data = f.read().split(',')

data = [i.zfill(5) for i in data]

i = 0
instructoin_len = 0 
while(True):
	opcode =   int(data[i][-2:])
	# input
	
	if (opcode) == 3:
		instructoin_len = 2
		d = int(data[i+1])
		data[d] = str(1).zfill(5)
		i+= instructoin_len
		continue
	if (opcode) == 4:
		instructoin_len = 2
		d = int(data[i+1])
		print(data[d])
		i+= instructoin_len
		continue


	if opcode == 99:
		break


	# mode of 1st param 
	c = int(data[i][2])
	# mode of 2nd param 
	b =int( data[i][1])
	# mode of 3rd param 
	a = int(data[i][0])


	oper_1  = int(data[i+ 1])
	oper_2 = int(data[i+ 2])
	d = int(data[i+ 3])
	if(not c):
		oper_1 = int(data[oper_1]) 
	if (not b):
		oper_2 = int(data[oper_2]) 


	if opcode == 1:
		instructoin_len = 4
		res = oper_1 + oper_2
		data[d] = str(res).zfill(5)
	if opcode == 2:
		instructoin_len = 4
		res = oper_1 * oper_2
		data[d] = str(res).zfill(5)
	i+= instructoin_len
