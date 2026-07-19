// turing_machine.h
#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include <deque>
#include <map>
#include <set>
#include <tuple>

namespace TM {
using value = int;
using direction = char;
using state = char;

// Explicit std:: scoping is required in header files
using step_data = std::tuple<value, direction, state>;
using state_data = std::map<value, step_data>;
using transition_data = std::map<state, state_data>;
class Turing_machine {
 private:
  char current_state;
  std::deque<int> tape;
  int rw_head;
  std::set<char> Q;
  std::set<int> T;
  int b;
  std::set<int> sigma;
  char q0;
  std::set<char> F;
  transition_data transitions;

 public:
  Turing_machine(std::set<char> Q, std::set<int> T, int b, std::set<int> sigma,
                 transition_data transitions, char q0, std::set<char> F);

  void step();
  void show_tape();
  int checksum();
};

}  // namespace TM

#endif