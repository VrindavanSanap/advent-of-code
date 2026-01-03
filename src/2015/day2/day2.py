with open("day2.txt") as f:
  data = f.read().split()

total_paper_size = 0
for line in data:
  paper_size = 0 
  dims = [int(i) for i in line.split("x")]
  s1 = dims[0] * dims[1]
  s2 = dims[1] * dims[2]
  s3 = dims[2] * dims[0]
  paper_size += 2 * s1
  paper_size += 2 * s2
  paper_size += 2 * s3
  paper_size += min(s1, s2, s3)
  total_paper_size += paper_size 

  print(f"{line} {paper_size} {total_paper_size}")
