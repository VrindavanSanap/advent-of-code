#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>

using namespace std;

map<pair<string, string>, int> distances;
int distance(vector<string> routes) {
  int dist = 0;
  for (int i = 0; i < routes.size() - 1; i++) {
    string origin = routes[i];
    string destination = routes[i + 1];
    dist += distances[minmax(origin, destination)];
  }
  return dist;
};
int main() {
  fstream file("./2015_day9.txt");
  string line;
  smatch matches;
  regex path_regex(R"((\S+) to (\S+) = (\d+))");
  set<string> cities;
  while (getline(file, line)) {
    regex_match(line, matches, path_regex);
    string origin = matches[1];
    string destination = matches[2];
    int distance = stoi(matches[3].str());
    cities.insert(origin);
    cities.insert(destination);
    distances[minmax(origin, destination)] = distance;
  }

  vector<string> cities_vector(cities.begin(), cities.end());
  int least_distance = INT_MAX;
  int max_distance = INT_MIN;
  do {
    int dist = distance(cities_vector);
    if (dist < least_distance) {
      least_distance = dist;
    };
    if (dist > max_distance) {
      max_distance = dist;
    }

  } while (next_permutation(cities_vector.begin(), cities_vector.end()));
  cout << least_distance << " " << max_distance << endl;
  return 0;
}
