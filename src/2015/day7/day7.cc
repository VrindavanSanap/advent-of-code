#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <regex>
#include <string>

using namespace std;

bool is_number(string s) {
  if (s.empty()) {
    return false;
  }
  for (char c : s) {
    if (isdigit(c)) {
    } else {
      return false;
    }
  }
  return true;
}

class Wire;
map<string, Wire> wires;

class Wire {
 public:
  string label;

  optional<string> op;
  optional<string> left;
  optional<string> right;

  optional<uint16_t> out;

  Wire() = default;

  /*
    For binary ops
  */
  Wire(string label, string op, string l_label, string r_label)
      : label(label), op(op), left(l_label), right(r_label) {

        };
  /*
    For NOT and assignment
  */
  Wire(string label, string op, string l_label)
      : label(label), op(op), left(l_label) {

        };
  uint16_t resolve(string label) {
    if (is_number(label)) {
      return static_cast<uint16_t>(stoi(label));
    } else {
      return wires[label].out_();
    }
  }
  uint16_t out_() {
    if (out.has_value()) {
      return out.value();
    }

    if (op == "OR") {
      out = resolve(left.value()) | resolve(right.value());
    }
    if (op == "AND") {
      out = resolve(left.value()) & resolve(right.value());
    }
    if (op == "LSHIFT") {
      out = resolve(left.value()) << resolve(right.value());
    }
    if (op == "RSHIFT") {
      out = resolve(left.value()) >> resolve(right.value());
    }
    if (op == "NOT") {
      out = ~resolve(left.value());
    }
    if (op == "->") {
      out = resolve(left.value());
    }
    return out.value();
  };
};

int main() {
  ifstream file("2015_day7.txt");
  string line;
  regex binary_op(R"((\w+)\s(AND|OR|[LR]SHIFT)\s(\w+)\s->\s(\w+))");
  regex not_op(R"((NOT)\s(\w+)\s->\s(\w+))");
  regex ass_op(R"((\w+)\s(->)\s(\w+))");
  smatch matches;
  while (getline(file, line)) {
    /*
      five possible operations
      Assignment OP
        123 -> x

      binary OPs
        AND
          x AND y -> d
        OR
          x OR y -> e
        LSHIFT
          x LSHIFT 2 -> f
        RSHIFT
          y RSHIFT 2 -> g

      Unary OP
        NOT
          NOT x -> h

    */
    if (regex_match(line, matches, binary_op)) {
      string op = matches[2];
      string l_label = matches[1];
      string r_label = matches[3];
      string label = matches[4];
      wires[label] = Wire(label, op, l_label, r_label);
    } else if (regex_match(line, matches, not_op)) {
      string op = matches[1];
      string l_label = matches[2];
      string label = matches[3];
      wires[label] = Wire(label, op, l_label);

    } else if (regex_match(line, matches, ass_op)) {
      string l_label = matches[1];
      string op = matches[2];
      string label = matches[3];
      wires[label] = Wire(label, op, l_label);
    } else {
      cout << "CATESOTPIHC FAIL\n";
      break;
    }
  }
  auto a = wires["a"].out_();
  cout << a << endl;

  for (auto &[key, value] : wires) {
    if (value.op.has_value()) {
      value.out.reset();
    }
  }
  wires["b"].op.reset();
  wires["b"].out = a;

  a = wires["a"].out_();
  cout << a << endl;

  return 0;
}