with open("day1.txt") as f:
  number_strings = f.readlines()

s = 0 
sum_list = []
for i in number_strings:
  if i != "\n":
    i = int(i)
    s += int(i)
  else:
    sum_list.append(s)
    s = 0 

print(((sorted(sum_list))[-3:]))
print(sum((sorted(sum_list))[-3:]))
