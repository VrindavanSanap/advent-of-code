#include <fstream>
#include <iostream>
#include <set>
#include <utility>

using namespace std;
int main() {
  ifstream file("./2015_day3.txt", ios::binary);
  int ch;
  // santa coords
  int sx = 0;
  int sy = 0;

  // robo santa coords
  int rx = 0;
  int ry = 0;

  // -1 santa 1 robosanta
  bool santas_move;
  set<pair<int, int>> coords;

  while ((ch = file.get()) != EOF) {
    if (ch == '<') {
      if (santas_move) {
        sx--;
      } else {
        rx--;
      }
    }
    if (ch == '>') {
      if (santas_move) {
        sx++;
      } else {
        rx++;
      }
    }
    if (ch == '^') {
      if (santas_move) {
        sy++;
      } else {
        ry++;
      }
    }
    if (ch == 'v') {
      if (santas_move) {
        sy--;
      } else {
        ry--;
      }
    }
    if (santas_move) {
      coords.insert({sx, sy});
    } else {
      coords.insert({rx, ry});
    }
    santas_move = !santas_move;
  }
  cout << coords.size() << endl;

  return 0;
}