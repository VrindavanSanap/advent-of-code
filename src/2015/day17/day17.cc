#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> combinations(vector<int> data, int num_elem) {
  // given a vector data and # elements num_elem
  // returns all the possible combinations of the data
  // containing num_elem elements









}
int main() {
  fstream file("./2015_day17.txt");
  string line;
  vector<int> s;
  while (getline(file, line)) {
    s.emplace_back(stoi(line));
  }
  for (const auto a : s) {
    cout << a << endl;
  }
  return 0;
}
