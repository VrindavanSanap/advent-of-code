#include <fstream>
#include <iostream>
#include <regex>
using namespace std;

int distance(int speed, int run_time, int rest_time, int time) {
  int dist = 0;
  int cycle_time = run_time + rest_time;
  int num_cycles = time / cycle_time;
  int dist_per_cycle = speed * run_time;
  dist += dist_per_cycle * num_cycles;
  int remaining_time = time % cycle_time;
  if (remaining_time <= run_time) {
    dist += remaining_time * speed;
  } else {
    dist += dist_per_cycle;
  }
  return dist;
}
int main() {
  fstream file("2015_day14.txt");
  string line;

  regex parse_line(R"((\S+).*?(\d+).*?(\d+).*?(\d+))");
  smatch matches;
  int max_dist = 0;
  while (getline(file, line)) {
    regex_search(line, matches, parse_line);
    string name = matches[0].str();
    int speed = stoi(matches[2].str());
    int run_time = stoi(matches[3].str());
    int rest_time = stoi(matches[4].str());
    int dist = distance(speed, run_time, rest_time, 2503);
    if (dist > max_dist) {
      max_dist = dist;
    }
  }
  cout << max_dist << endl;

  return 0;
}