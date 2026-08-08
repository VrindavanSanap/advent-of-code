#include <fstream>
#include <iostream>
#include <set>
#include <utility>

using namespace std;
int main() {
  ifstream file("./2015_day3.txt", ios::binary);
  int ch;
  int x;
  int y;
  set<pair<int, int>> coords;
  while ((ch = file.get()) != EOF) {
    char c = static_cast<char>(ch);
    if (ch == '<') {
      x -= 1;
    }
    if (ch == '>') {
      x += 1;
    }
    if (ch == '^') {
      y += 1;
    }
    if (ch == 'v') {
      y -= 1;
    }
    coords.insert({x, y});
  }
  cout << coords.size() << endl;

  return 0;
}