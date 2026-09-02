#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> neighbours(int i, int j, int width, int height) {
  constexpr std::array<std::pair<int, int>, 8> offsets = {
      {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
  vector<pair<int, int>> neighbours_l;
  for (const auto &[dy, dx] : offsets) {
    int i_i = i + dx;
    int j_i = j + dy;
    if (i_i >= width || j_i >= height || i_i < 0 || j_i < 0) {
      continue;
    } else {
      neighbours_l.emplace_back(i_i, j_i);
    }
  }
  return neighbours_l;
}
int main() {
  fstream file("./2015_day18_smol.txt");
  string line;
  vector<string> data;
  vector<string> new_data;
  while (getline(file, line)) {
    data.emplace_back(line);
  }
  int height = data.size();
  int width = data[0].size();
  new_data = data;
  for (int k = 0; k < 5; k++) {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        char data_i = data[j][i];
        int num_on = 0;
        for (const auto &[dy, dx] : neighbours(i, j, width, height)) {
          char neighbour = data[dx][dy];
          if (neighbour == '#') {
            num_on++;
          }
        }
        if (data_i == '#') {
          if (num_on == 2 || num_on == 3) {
          } else {
            new_data[j][i] = '.';
          }
        } else {
          if (num_on == 3) {
            new_data[j][i] = '#';
          }
        }
      }
    }
    data = new_data;
  }
  for
}