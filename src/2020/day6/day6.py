file_data= ""

with open("./2020_day6.txt") as f:
	file_data = f.read()
f.close()

groups = file_data.split("\n\n")
s = 0
for group in groups:
	group = group.replace("\n", "")
	s+= (len(set(group)))
print(s)

