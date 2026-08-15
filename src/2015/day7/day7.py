#!/usr/bin/env python3

wires = {}
class Wire:
  global wires
  def __init__(self, label = '', op=None, l_label=None, r_label=None, value = None):
    self.left = l_label 
    self.right = r_label 
    self.label = label
    self.value = value
    self.out = None
    if label == '':
      label =(self.value)
    self.op = op
  """

  Five ops:
    OR
    AND
    RSHIFT
    LSHIFT
    -->
  """

  def out_(self):
    if self.out is not None:
      return self.out

    if self.op == None:
      self.out = self.value
    if self.left:
      if not self.left in wires:
        wires[self.left] = Wire(label=self.left, value=int(self.left))
    if self.right:
      if not self.right in wires:
        wires[self.right] = Wire(label=self.right, value=int(self.right))

 
    if self.op == "OR":
      self.out = wires[self.left].out_() | wires[self.right].out_()

    if self.op == "AND":
      self.out = wires[self.left].out_() & wires[self.right].out_()

    if self.op == "LSHIFT":
      self.out = (wires[self.left].out_() << wires[self.right].out_()) % 65536

    if self.op == "RSHIFT":
      self.out = wires[self.left].out_() >> wires[self.right].out_()

    if self.op == "NOT":
      self.out = ~wires[self.left].out_() %65536

    if self.op == "->":
      self.out = wires[self.left].out_()

    return self.out

  def __repr__(self):
    temp = (f"{self.label} = {self.out_()}")
    return temp        

"""
wires["x"] = Wire("x", value = 123)
wires["y"] =  Wire("y", value = 456)
wires["d"]= Wire("d", "AND", "x", "y")
wires["e"] = Wire("e", "OR", "x", "y")
wires["f"] = Wire("f", "LSHIFT", "x", 2)
wires["g"] = Wire("g", "RSHIFT", "y", 2)
wires["h"] = Wire("h", "NOT", "x")
wires["i"]= Wire("i", "NOT", "y")
"""


with open("2015_day7.txt", "r") as f:
  lines = f.read().split('\n')

for line in lines: 
  print(line)
  wire_str = line.split()

  if (wire_str[0] == "NOT"):
    op = wire_str[0]
    l_label = wire_str[1]
    label = wire_str[3]
    wires[label] = Wire(label, op=op, l_label=l_label)

  elif (wire_str[1] == "RSHIFT"):
    op = wire_str[1]
    label = wire_str[4]
    l_label = wire_str[0]
    r_label = wire_str[2]
    wires[label] = Wire(label, op=op, l_label=l_label ,r_label=r_label)

  elif (wire_str[1] == "LSHIFT"):
    op = wire_str[1]
    label = wire_str[4]
    l_label = wire_str[0]
    r_label = wire_str[2]
    wires[label] = Wire(label, op=op, l_label=l_label ,r_label=r_label)


  elif  (wire_str[1] == "OR"):
    op = wire_str[1]
    l_label = wire_str[0]
    r_label = wire_str[2]
    label = wire_str[4]
    wires[label] = Wire(label, op=op, l_label=l_label , r_label=r_label)

  elif  (wire_str[1] == "AND"):
    op = wire_str[1]
    l_label = wire_str[0]
    r_label = wire_str[2]
    label = wire_str[4]
    wires[label] = Wire(label, op=op, l_label=l_label , r_label=r_label)


  elif (wire_str[1] == "->"):
    op = wire_str[1]
    label = wire_str[2]
    l_label = wire_str[0]
    wires[label] = Wire(label, op=op, l_label=l_label )
  else:
    print("error")
    break

a = wires['a'].out_()
print(a)
for wire in wires:
  wires[wire].out = None

wires['b'].op = None
wires['b'].value = a

print(wires['a'].out_())