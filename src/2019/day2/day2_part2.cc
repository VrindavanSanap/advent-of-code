#include <fstream>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream file("2019_day2.txt");
  vector<int> data;

  string line;
  getline(file, line);
  cout << line << endl;
  stringstream ss(line);
  string token;
  int num;
  while (getline(ss, token, ',')) {
    num = stoi(token);
    data.emplace_back(num);
  };
  int num_ints = data.size();
  vector<int> data_copy;
  data_copy = data;
  for (int j = 0; j < 100; j++) {
    for (int k = 0; k < 100; k++) {
      data = data_copy;
      data[1] = j;
      data[2] = k;

      for (int i = 0; i < num_ints; i += 4) {
        int opcode = data[i];
        if (opcode == 99) {
          break;
        }
        int addr_1 = data[i + 1];
        int addr_2 = data[i + 2];
        int dest = data[i + 3];
        int x = data[addr_1];
        int y = data[addr_2];
        int res = 0;
        if (opcode == 1) {
          res = x + y;
        }
        if (opcode == 2) {
          res = x * y;
        }
        data[dest] = res;
      }
      int output = data[0];
      if (output == 19690720) {
        cout << (j * 100) + k << endl;
        exit(0);
      };
    }
  }
  return 0;
}
