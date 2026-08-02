#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
struct instruction {
  string opcode;
  int operand;
  bool visited;
};

void print_opcodes(vector<instruction> instructions) {
  string opcode;
  for (int j = 0; j < instructions.size(); j++) {
    opcode = instructions[j].opcode;
    cout << opcode << " ";
  }
  cout << endl;
}
tuple<bool, int> execute(vector<instruction> instructions) {
  int accumulator = 0;
  int ip = 0;
  int num_lines = instructions.size();
  while (true) {
    if (ip == num_lines) {
      return {true, accumulator};
    }
    instruction &instruction_i = instructions[ip];
    if (instruction_i.visited) {
      break;
    } else {
      instruction_i.visited = true;
    }
    if (instruction_i.opcode == "nop") {
    } else if (instruction_i.opcode == "acc") {
      accumulator += instruction_i.operand;
    } else if (instruction_i.opcode == "jmp") {
      ip += instruction_i.operand;
      continue;
    }
    ip++;
  }

  return {false, accumulator};
}
int main() {
  fstream file("2020_day8.txt");
  vector<instruction> instructions;

  string line;
  stringstream s;

  string opcode;
  int operand;
  bool visited;
  visited = false;

  while (getline(file, line)) {
    s = stringstream(line);
    s >> opcode >> operand;
    instructions.emplace_back(instruction{opcode, operand, visited});
  }

  auto [status, accumulator] = execute(instructions);
  cout << accumulator << endl;

  int i = 0;
  while (true) {
    opcode = instructions[i].opcode;
    if (opcode == "nop") {
      instructions[i].opcode = "jmp";
      auto [status, accumulator] = execute(instructions);
      instructions[i].opcode = opcode;
      if (status) {
        cout << "succ:" << accumulator << endl;
        break;
      }
      i++;

    } else if (opcode == "jmp") {
      instructions[i].opcode = "nop";
      auto [status, accumulator] = execute(instructions);
      instructions[i].opcode = opcode;
      if (status) {
        cout << "succ:" << accumulator << endl;
        break;
      }
      i++;

    } else {
      i++;
    }
  }
  return 0;
}
