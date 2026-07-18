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
