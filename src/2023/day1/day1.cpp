#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int get_number(string line) {
  string number_string = "";
  for (char c : line) {
    if (isdigit(c)) {
      number_string += c;
    }
  }
  string output = "";
  output += number_string[0];
  output += number_string[number_string.length() - 1];
  return stoi(output);
};
int main() {
  ifstream file("day1.txt");
  vector<std::string> lines;
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  int sum = 0;
  for (const auto &l : lines) {
    int n = get_number(l);
    cout << l << " " << n << endl;
    sum += n;
  }
  cout << "sum" << sum << endl;
  return 0;
}
