#include "turing_machine.h"

#include <iostream>
#include <numeric>
namespace TM {

Turing_machine::Turing_machine(std::set<char> Q, std::set<int> T, int b,
                               std::set<int> sigma, transition_data tranistions,
                               char q0, std::set<char> F) {
  this->Q = Q;
  this->T = T;
  this->b = b;
  this->sigma = sigma;
  this->q0 = q0;
  this->F = F;
  this->current_state = q0;
  this->rw_head = 0;
  this->transitions = tranistions;
  this->tape.push_back(this->b);
};
void Turing_machine::step() {
  step_data current_step = transitions.at(current_state).at(tape.at(rw_head));

  // decode
  auto [write, move_dir, next_state] = current_step;

  // overwrite
  auto it = tape.begin() + rw_head;

  tape.at(rw_head) = write;
  // move
  if (move_dir == 'r') {
    if (rw_head == tape.size() -1) {
      tape.push_back(b);
    }
    rw_head++;
  } else {
    if (rw_head == 0) {
      tape.push_front(b);
    } else {
      rw_head--;
    }
  }
  // change state
  this->current_state = next_state;
}  // namespace TM
void Turing_machine::show_tape() {
  auto it = tape.begin();
  auto end = tape.end();

  std::cout << "[";
  if (it != end) {
    std::cout << *it;
    ++it;
  }
  for (; it != end; ++it) {
    std::cout << " " << *it;
  }
  std::cout << "]\n";
}
int Turing_machine::checksum() {
  return std::accumulate(tape.begin(), tape.end(), 0);
}
}  // namespace TM
