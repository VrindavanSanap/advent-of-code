#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <print>
#include <regex>
#include <set>
#include <string>

using namespace std;
map<pair<string, string>, int> happiness_deltas;
int get_happiness_delta(vector<string> names_vector) {
  int delta = 0;
  size_t size = names_vector.size();
  for (int i = 0; i < size; i++) {
    string origin = names_vector[i];
    string destination = names_vector[(i + 1) % size];

    delta += happiness_deltas[pair(origin, destination)];
    delta += happiness_deltas[pair(destination, origin)];
  }
  return delta;
};
int main() {
  fstream file("./2015_day13.txt");

  regex parse_line(
      R"((\w+) would (gain|lose) (\d+) happiness units by sitting next to (\w+))");
  string line;
  smatch matches;

  set<string> names;
  while (getline(file, line)) {
    regex_search(line, matches, parse_line);
    string name_a = matches[1].str();
    string name_b = matches[4].str();
    int happiness_delta = stoi(matches[3].str());
    if (matches[2].str() == "lose") {
      happiness_delta *= -1;
    }
    happiness_deltas[pair(name_a, name_b)] = happiness_delta;
    names.insert(name_a);
    names.insert(name_b);
  }
  vector<string> names_vector(names.begin(), names.end());
  int max_group_happiness = INT_MIN;
  do {
    int group_happiness = get_happiness_delta(names_vector);
    if (group_happiness > max_group_happiness) {
      max_group_happiness = group_happiness;
    }
  } while (next_permutation(names_vector.begin(), names_vector.end()));
  cout << max_group_happiness << endl;
  return 0;
}