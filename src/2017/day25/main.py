from turing_machine import Turing_machine 
from tqdm import tqdm

import re
with open("./2017_day25.txt", "r", encoding="utf-8") as file:
	lines = file.read().split("\n")
	

num_steps_lines = lines[1]
num_steps = int(re.findall(r"\d+", num_steps_lines)[0])

lines = lines[3:]
states = [lines[i:i+9] for i in range(0, len(lines), 10)]
transitions = {}

def parse_segment(state_name, segment):
	if not state_name in transitions:
		transitions[state_name] = {}

	current_value = int(segment[0][-2])
	write = int(segment[1][-2])
	move_dir = segment[2][27]
	next_state = segment[3][-2]
	transitions[state_name][current_value] = (write, move_dir, next_state)


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


q0 = 'A'
Q= ['A', 'B']
T = [0, 1]
b = 0 
sigma = [0, 1]
F = None
my_machine = Turing_machine(Q, T, b, sigma, transitions, q0, F)
for i in tqdm(range(num_steps)):
	my_machine.step()
print(my_machine.checksum())



