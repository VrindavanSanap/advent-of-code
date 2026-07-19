class Turing_machine:

	def __init__(self, Q, T, b, sigma, delta, q0, F):

		# finite set of states (set)
		self.Q = Q

		# finite set of tape alphabet symbols (set)
		self.T = T

		# blank symbol b ∈ T
		self.b = b

		# set of input symbol (subset of T) b ∉ Σ
		self.sigma = sigma

		# transition function 
		# δ:(Q∖F)×T→Q×T×{L,R}
		self.delta = delta

		# initial start state q0 ∈ Q
		self.q0 = q0

		# set of final/accepting states F ⊆ Q
		self.F = F


		self.current_state = q0
		self.tape = [self.b]
		self.rw_head = 0

	def step(self):
		# Execution
		# decode 
		write, move_dir, next_state = self.delta[self.current_state][self.tape[self.rw_head]]
		# Overwrite 
		self.tape[self.rw_head] = write
		# Move  
		if (move_dir == 'r'):
			if(self.rw_head == (len(self.tape) -1)):
				self.tape.append(self.b)
			self.rw_head += 1
		else:
			if (self.rw_head ==0):
				self.tape.insert(0, self.b)
			else:
				self.rw_head -= 1
		# Change state
		self.current_state = next_state
		pass
	def show_tape(self):
		print(self.tape)
	def checksum(self):
		return sum(self.tape)