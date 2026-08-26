#include <fstream>
#include <iostream>
#include <map>
#include <regex>
using namespace std;

class Reindeer {
  int speed;
  int run_time;
  int rest_time;
  int time_step = 0;
  int position = 0;
  int cycle_time = 0;
  int time = 0;
  bool is_running = true;

 public:
  int points = 0;
  int dist = 0;
  Reindeer(int speed, int run_time, int rest_time)
      : speed(speed), run_time(run_time), rest_time(rest_time) {
    cycle_time = run_time + rest_time;
  }
  void step() {
    if (is_running) {
      dist += speed;
    }
    time++;
    time = time % cycle_time;
    if (time < run_time) {
      is_running = true;
    } else {
      is_running = false;
    }
  }
  void give_point(int max_dist) {
    if (max_dist <= dist) {
      points++;
    }
  }
};

class Reindeers {
  map<string, Reindeer> reindeers;

 public:
  Reindeers() {}
  void add_reindeer(string name, int speed, int run_time, int rest_time) {
    Reindeer r(speed, run_time, rest_time);
    reindeers.insert({name, r});
  }
  void step() {
    for (auto &[_, reindeer] : reindeers) {
      reindeer.step();
    }
  }
  void give_points() {
    int max_dist = 0;

    for (auto &[_, reindeer] : reindeers) {
      if (reindeer.dist > max_dist) {
        max_dist = reindeer.dist;
      }
    }

    for (auto &[_, reindeer] : reindeers) {
      reindeer.give_point(max_dist);
    }
  }
  int winner() {
    int max_points = 0;
    for (auto &[_, reindeer] : reindeers) {
      if (reindeer.points > max_points) {
        max_points = reindeer.points;
      }
    }
    return max_points;
  }
};

int main() {
  fstream file("2015_day14.txt");
  string line;

  regex parse_line(R"((\S+).*?(\d+).*?(\d+).*?(\d+))");
  smatch matches;
  Reindeers rs;
  while (getline(file, line)) {
    regex_search(line, matches, parse_line);
    string name = matches[1].str();
    int speed = stoi(matches[2].str());
    int run_time = stoi(matches[3].str());
    int rest_time = stoi(matches[4].str());
    rs.add_reindeer(name, speed, run_time, rest_time);
  }
  for (int i = 0; i < 2503; i++) {
    rs.step();
    rs.give_points();
  }
  cout << rs.winner() << endl;
  return 0;
}