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

  // Restore "1202 program alarm" state before running
  data[1] = 12;
  data[2] = 2;

  println("{}", data);
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

  cout << output << endl;
  return 0;
}
