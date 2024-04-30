with open("day2.txt") as f:
    data = f.read().split("\n")

data = [[int(i) for i in row.split('\t')] for row in data]
final_ans = sum([max(row)-min(row) for row in data])
print(final_ans)
