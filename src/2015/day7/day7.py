#!/usr/bin/env python3

wires = {}
class Wire:
  def __init__(self, label = '', op=None, l_label=None, r_label=None):
    self.left = l_label 
    self.right = r_label 
    self.label = label
    self.out = None
    self.op = op

  @staticmethod
  def resolve(label):
    if (label.isdigit()):
      return int(label)
    else:
      return wires[label].out_()

  def out_(self):
    if self.out is not None:
      return self.out

    if self.op == None:
      self.out = self.resolve(self.label)
 
    if self.op == "OR":
      self.out = self.resolve(self.left) | self.resolve(self.right)

    if self.op == "AND":
      self.out = self.resolve(self.left) & self.resolve(self.right)

    if self.op == "LSHIFT":
      self.out = (self.resolve(self.left) << self.resolve(self.right)) % 65536

    if self.op == "RSHIFT":
      self.out = self.resolve(self.left) >> self.resolve(self.right)

    if self.op == "NOT":
      self.out =(~(self.resolve( self.left) ))%65536

    if self.op == "->":
      self.out = self.resolve(self.left)

    return self.out

  def __repr__(self):
    return (f"{self.label} = {self.out_()}")

with open("2015_day7.txt", "r") as f:
  lines = f.read().split('\n')

for line in lines: 
  wire_str = line.split()

  if wire_str[0] == "NOT":
    wires[wire_str[3]] = Wire(label=wire_str[3], op=wire_str[0], l_label=wire_str[1])

  elif wire_str[1] in ("RSHIFT", "LSHIFT", "OR", "AND"):
    wires[wire_str[4]] = Wire(label=wire_str[4], op=wire_str[1], l_label=wire_str[0], r_label=wire_str[2])

  elif wire_str[1] == "->":
    wires[wire_str[2]] = Wire(label=wire_str[2], op=wire_str[1], l_label=wire_str[0])

  else:
    print("error")
    break

a = wires['a'].out_()
print(a)

for wire in wires:
  if wires[wire].op is not None:
    wires[wire].out = None

wires['b'].op = None
wires['b'].out = a

print(wires['a'].out_())