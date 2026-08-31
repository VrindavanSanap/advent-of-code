#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  fstream file("./2015_day17.txt");
  string line;
  vector<int> s;
  while (getline(file, line)) {
    s.emplace_back(stoi(line));
  }
  
  return 0;
}
