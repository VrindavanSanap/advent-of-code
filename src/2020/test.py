with open ("day3.txt", "r") as f:
  s = f.read()
  s = s.split()
l = len(s)
i = 0
count = 0
for  j in range (l):
  i_ = (j*3)%(len(s[0]))
  if (s[j][i_] == '#'): 
    print("x")
    count+=1
  else:
    print("o")

print(count)
