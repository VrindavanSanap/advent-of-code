import json
with open ('./day12.json') as f:
		data = json.load(f)

def total_sum(data):
	if type(data) == int:
		return data
	elif type(data) == list:
		return sum(total_sum(item) for item in data)
	elif type(data) == dict:
		return sum(total_sum(value) for key, value in data.items())
	else:
		return 0
print(total_sum(data))
