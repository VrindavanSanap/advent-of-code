#include <fstream>
#include <iostream>
#include <regex>
using namespace std;


int main() {
  fstream file("2015_day14_smol.txt");
  string line;

  regex parse_line(R"(((\S+).*?(\d+).*?(\d+).*?(\d+)))");
  smatch matches;
  while (getline(file, line)) {
    regex_search(line, matches, parse_line);
    string name = matches[1].str();
    int speed = stoi(matches[2].str());
    int run_time = stoi(matches[3].str());
    int rest_time = stoi(matches[4].str());
  }

  return 0;
}