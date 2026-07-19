#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

#include "turing_machine.h"
using namespace std;
using namespace TM;


int main() {
  string smol_file = "2017_day25_smol.txt";
  string file = "2017_day25.txt";
  ifstream inputFile(file);

  if (!inputFile.is_open()) {
    std::cerr << "Error: Could not open the file." << std::endl;
    return 1;
  }

  string line;
  for (int i = 0; i < 2; i++) {
    getline(inputFile, line);
    cout << i << " " << line << endl;
  }
  vector<string> lines;
  while (getline(inputFile, line)) {
    lines.push_back(line);
  }
  cout << lines.size() << endl;

  int num_states = lines.size() / 10;
  transition_data transitions;
  for (int i = 0; i < num_states; i++) {
    int state_start_index = i * 10 + 1;
    string state_line = lines[state_start_index];
    char state_i = state_line[state_line.size() - 2];
    state_data state_data_i;
    for (int j = 0; j < 2; j++) {
      // index 2-5
      string value_line = lines[state_start_index + (j * 4) + 2];
      string direction_line = lines[state_start_index + (j * 4) + 3];
      string state_line = lines[state_start_index + (j * 4) + 4];
      int value_i = value_line[value_line.size() - 2] - '0';
      char direction_i = direction_line[27];
      char state_i = state_line[state_line.size() - 2];
      step_data step_i = {value_i, direction_i, state_i};
      state_data_i.insert({j, step_i});
    }
    transitions.insert({state_i, state_data_i});
  }
  print_transition_data(transitions);

  set<char> Q;
  set<int> T;
  int b = 0;
  set<int> sigma;
  char q0 = 'A';
  set<char> F;

  Turing_machine my_machine(Q, T, b, sigma, transitions, q0, F);
  for (int i = 0; i < 12261543; i++) {
    //  my_machine.show_tape();
    my_machine.step();
  }
  cout << my_machine.checksum() << endl;
  inputFile.close();
  return 0;
}