with open("day2.txt") as f:
  data = f.read().split()

total_paper_size = 0
for line in data:
  paper_size = 0 
  dims = [int(i) for i in line.split("x")]
  s1 = dims[0] 
  s2 = dims[1]
  s3 = dims[2] 
  paper_size += s1 * s2 * s3
  paper_size += 2 * sum([s1, s2, s3])
  paper_size -= 2 * max(s1, s2, s3)
  total_paper_size += paper_size 

  print(f"{line} {paper_size} {total_paper_size}")
