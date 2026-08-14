#include <ATen/ATen.h>

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
int main() {
  auto opts = at::TensorOptions().dtype(at::kBool);
  at::Tensor lights = at::zeros({1000, 1000}, opts);
  ifstream file("2015_day6.txt");
  if (!file.is_open()) {
    cerr << "Error: could not open file" << endl;
    return 1;
  }
  string line;
  regex pattern(R"((on|off|toggle)\s(\d+),(\d+)\D+(\d+),(\d+))");

  smatch matches;

  while (getline(file, line)) {
    regex_search(line, matches, pattern);
    int x1 = stoi(matches[2]);
    int y1 = stoi(matches[3]);
    int x2 = stoi(matches[4]);
    int y2 = stoi(matches[5]);
    if (matches[1] == "toggle") {
      lights.slice(0, x1, x2 + 1).slice(1, y1, y2 + 1) =
          ~lights.slice(0, x1, x2 + 1).slice(1, y1, y2 + 1);
    }
    if (matches[1] == "on") {
      lights.slice(0, x1, x2 + 1).slice(1, y1, y2 + 1).fill_(1);
    }
    if (matches[1] == "off") {
      lights.slice(0, x1, x2 + 1).slice(1, y1, y2 + 1).fill_(0);
    }
  }

  file.close();
  int total = lights.sum().item<int>();
  cout << total << endl;

  return 0;
}
