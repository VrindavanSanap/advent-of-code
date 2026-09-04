#include <fstream>
#include <iostream>
#include <set>

using namespace std;
int main() {
  ifstream file("./2015_day3.txt");
  char ch;
  int x;
  int y;
  set<pair<int, int>> coords;
  while ((ch = file.get()) != EOF) {
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