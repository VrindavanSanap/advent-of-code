#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;
struct instruction {
  string opcode;
  int operand;
  bool visited;
};

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
    
  int accumulator = 0;
  int ip = 0;
  while(true){
   instruction& instruction_i=  instructions[ip];
    if (instruction_i.visited){
      break;
    }else{
      instruction_i.visited = true;
    }
    if (instruction_i.opcode == "nop"){
    }else if (instruction_i.opcode == "acc"){
      accumulator += instruction_i.operand;
    }
    else if (instruction_i.opcode == "jmp"){
      ip +=  instruction_i.operand;
      continue;
    }
    ip++;

  }
  cout << accumulator << endl;
  return 0;
}
