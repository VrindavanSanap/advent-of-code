#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <utility>

using namespace std;
int mod(int a, int n) {
  int r = a % n;
  if (r < 0) {
    r += n;
  }
  return r;
}
int main() {
  ifstream file("./2016_day1.txt");
  set<pair<int, int>> points;
  string line;
  getline(file, line);
  stringstream ss(line);
  char turn;
  char comma;
  int steps;
  int x = 0;
  int y = 0;
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int current_dir = 0;
  points.insert({0, 0});
  while (ss >> turn >> steps) {
    if (turn == 'R') {
      current_dir++;
    } else if (turn == 'L') {
      current_dir--;
    }
    current_dir = mod(current_dir, 4);
    for (int i = 0; i < steps; i++) {
      x += directions[current_dir][0];
      y += directions[current_dir][1];
      if (points.contains({x, y})) {
        int dist = abs(x) + abs(y);
        cout << dist << endl;
        return 0;
      }
      points.insert({x, y});
    }
    ss >> comma;
  }
  return 0;
}