#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <regex>
#include <string>

using namespace std;

map<string, Wire> wires;
class Wire {
 public:
  string label;

  optional<string> left;
  optional<string> right;

  uint16_t value;
  optional<uint16_t> out;
  optional<string> op;

  Wire() = default;

  /*
    For binary ops
  */
  Wire(string label, string op, string l_label, string r_label)
      : label(label), left(l_label), right(r_label) {

        };
  /*
    For NOT and assignment
  */
  Wire(string label, string op, string l_label)
      : label(label), op(op), left(l_label) {

        };
  /*
    For nums

  */
  Wire(string label, uint16_t value) : label(label), value(value) {};

  uint16_t out_() {
    if (out.has_value()) {
      return out.value();
    }
    if (left.has_value() && (!wires.contains(left.value()))) {
      wires[left.value()] = Wire(left.value(), out.value());
    }
    if (right.has_value() && (!wires.contains(right.value()))) {
      wires[right.value()] = Wire(right.value(), out.value());
    }
    if (!op.has_value()) {
      return value;
    }

    return 0;
  };
};
int main() {
  ifstream file("2015_day7_smol.txt");
  string line;
  regex binary_op(R"((\w+)\s(AND|OR|[LR]SHIFT)\s(\w+)\s->\s(\w+))");
  regex not_op(R"((NOT)\s(\w+)\s->\s(\w+))");
  regex ass_op(R"((\w+)\s(->)\s(\w+))");
  smatch matches;
  while (getline(file, line)) {
    cout << line << endl;

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
    cout << line;
    if (regex_match(line, matches, binary_op)) {
      cout << " BINARY OP\n";
      string op = matches[2];
      cout << op << endl;

      string l_label = matches[1];
      cout << l_label << endl;

      string r_label = matches[3];
      cout << r_label << endl;

      string label = matches[4];
      cout << label << endl;
      wires[label] = Wire(label, op, l_label, r_label);
    } else if (regex_match(line, matches, not_op)) {
      cout << " NOT OP\n";
      string op = matches[1];
      cout << op << endl;

      string l_label = matches[2];
      cout << l_label << endl;

      string label = matches[3];
      cout << label << endl;
      wires[label] = Wire(label, op, l_label);

    } else if (regex_match(line, matches, ass_op)) {
      cout << " ASS OP\n";

      string l_label = matches[1];
      cout << l_label << endl;

      string op = matches[2];
      cout << op << endl;

      string label = matches[3];
      cout << label << endl;
      wires[label] = Wire(label, op, l_label);
    } else {
      cout << "CATESOTPIHC FAIL\n";
      break;
    }
  }
  return 0;
}