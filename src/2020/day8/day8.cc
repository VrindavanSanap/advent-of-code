#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

using namespace std;
int main() {
  fstream file("2020_day8.txt");
  string line;
  int accumulator = 0;
  map<int, tuple<string, bool>> lines;
  int num_lines = 0;
  while (getline(file, line)) {
    lines.emplace(num_lines, make_tuple(line, false));
    num_lines++;
  }

  int ip = 0;
  while (true) {
    auto &[line, visited] = lines[ip];
    if (visited) {
      break;
    } else {
      visited = true;
    }
    string instruction;
    int argument;
    static const regex pattern(R"(([a-zA-Z]+)\s([-+]?\d+))");
    smatch matches;
    regex_search(line, matches, pattern);
    instruction = matches[1].str();
    argument = stoi(matches[2].str());
    if (instruction == "nop") {
    } else if (instruction == "acc") {
      accumulator += argument;
    } else if (instruction == "jmp") {
      ip += argument;
      continue;
    }
    ip++;
  }
  cout << accumulator << endl;
  return 0;
}
