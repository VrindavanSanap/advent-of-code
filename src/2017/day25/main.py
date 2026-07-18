

import re
with open("./2017_day25_smol.txt", "r", encoding="utf-8") as file:
	lines = file.read().split("\n")
	

start_state = 'A'
num_steps_lines = lines[1]
num_steps = int(re.findall(r"\d+", num_steps_lines)[0])

lines = lines[3:]
for i in range(len(lines)):
	print(i, lines[i])
	pass

states = [lines[i:i+9] for i in range(0, len(lines), 10)]
transitions = {}

def parse_segment(state_name, segment):
	if not state_name in transitions:
		transitions[state_name] = {}

	current_value = int(segment[0][-2])
	write = int(segment[1][-2])
	transitions[state_name][current_value] = (write)


def parse_state(state):
	state_name = state[0][-2]
	state = state[1:]
	segments = [state[i:i+4] for i in range(0, len(state), 4)]

	for segment in segments:
		parse_segment(state_name, segment)



for state in  (states):
	parse_state(state)
print(num_steps)
print(transitions)
tape = [0]
index = 0
begin_state = 'A'

def step():
	tape[index] = transitions[begin_state][tape[index]]


	pass


for i in range(2):

	print(f"current state @ step {i}: {tape}")
	step()
