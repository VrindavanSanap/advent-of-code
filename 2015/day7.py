
wires = {}
class Wire:
  global wires
  def __init__(self, label = '', op=None, left=None, right=None, value = None):
    self.left = left
    self.right = right
    self.label = label
    self.value = value
    self.out = None
    if label == '':
      label =(self.value)
    self.op = op
  """

  Four ops:
    OR
    AND
    RSHIFT
    LSHIFT
  """

  def out_(self):
    print(self.label)    
    if self.out:
      return self.out
    if self.op == None:
      self.out = self.value
    if self.op == "OR":
      self.out = wires[self.left].out_() | wires[self.right].out_()
    if self.op == "AND":
      self.out = wires[self.left].out_() & wires[self.right].out_()

    if self.op == "LSHIFT":
      self.out = wires[self.left].out_() << self.right

    if self.op == "RSHIFT":
      self.out = wires[self.left].out_() >> self.right

    if self.op == "NOT":
      self.out = ~wires[self.left].out_() %65536
    if self.op == "->":
      self.out = wires[self.left].out_()
    return self.out

  def __repr__(self):
    temp = (f"{self.label} = {self.out_()}")
    try:
      temp = (f"{self.label} = {self.out_()}")
      if self.left:
        temp += (f"{wires[self.left].label} = {wires[self.left].out_()}")
      if self.right:
        temp += (f"{wires[self.right].label} = {wires[self.right].out_()}")


    except:
      if self.right:
        temp = (f"{self.left} {self.op} {self.right} --> {self.label}")
      else:
        temp = (f"{self.left} {self.op} --> {self.label}")
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
with open("day7.txt", "r") as f:
  lines = f.readlines()
for line in lines: 
  line = line[:-1]
  wire_str =line.split()
  if (wire_str[0] == "NOT"):
    op = wire_str[0]
    l_label = wire_str[1]
    label = wire_str[3]
    wires[label] = Wire(label, op, l_label )

  elif (wire_str[1] == "RSHIFT"):
    op = wire_str[1]
    label = wire_str[4]
    l_label = wire_str[0]
    shift_int = int(wire_str[2])
    wires[label] = Wire(label, op, l_label ,shift_int )

  elif (wire_str[1] == "LSHIFT"):
    op = wire_str[1]
    label = wire_str[4]
    l_label = wire_str[0]
    shift_int = int(wire_str[2])
    wires[label] = Wire(label, op, l_label ,shift_int )


  elif  (wire_str[1] == "OR"):
    op = wire_str[1]
    l_label = wire_str[0]
    r_label = wire_str[2]
    label = wire_str[4]
    wires[label] = Wire(label, op, l_label , r_label)

  elif  (wire_str[1] == "AND"):
    op = wire_str[1]
    l_label = wire_str[0]
    r_label = wire_str[2]
    label = wire_str[4]
    wires[label] = Wire(label, op, l_label , r_label)


  elif (wire_str[1] == "->"):
    op = wire_str[1]
    label = wire_str[2]
    l_label = wire_str[0]
    wires[label] = Wire(label, op, l_label )
  else:
    print("error")
    break

wires["c"] = Wire("c", value = 0)
wires["b"] = Wire("b", value = 1674)
wires["1"] = Wire("1", value = 1)
print([wires['a']])
wires["b"] = Wire("b", value = 46065)
for wire in wires: 
  wires[wire].out = None
print([wires['a']])
