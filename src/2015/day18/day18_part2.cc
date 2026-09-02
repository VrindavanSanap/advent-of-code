#include <array>
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
  fstream file("./2015_day18.txt");
  string line;
  vector<string> data;
  vector<string> new_data;
  while (getline(file, line)) {
    data.emplace_back(line);
  }
  int height = data.size();
  int width = data[0].size();
  new_data = data;
  data[0][0] = '#';
  data[height - 1][0] = '#';
  data[height - 1][width - 1] = '#';
  data[0][width - 1] = '#';
  for (int k = 0; k < 100; k++) {
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
    new_data[0][0] = '#';
    new_data[height - 1][0] = '#';
    new_data[height - 1][width - 1] = '#';
    new_data[0][width - 1] = '#';
    data = new_data;
  }
  int s = 0;
  for (const auto &line : data) {
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '#') {
        s++;
      }
    }
  }
  cout << s << endl;
}