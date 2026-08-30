#include <fstream>
#include <iostream>
#include <regex>
#include <unordered_map>

using namespace std;
int main() {
  unordered_map<std::string, int> gift_sue = {
      {"children", 3}, {"cats", 7},    {"samoyeds", 2}, {"pomeranians", 3},
      {"akitas", 0},   {"vizslas", 0}, {"goldfish", 5}, {"trees", 3},
      {"cars", 2},     {"perfumes", 1}};
  fstream file("./2015_day16.txt");
  string line;
  regex sue_regex(R"(Sue.(\d+))");
  regex attr_regex(R"(([a-zA-Z]+):.(\d+))");

  smatch sue_no_match;
  smatch attr_matches;
  while (getline(file, line)) {
    regex_search(line, sue_no_match, sue_regex);

    int sue_no = stoi(sue_no_match[1].str());
    auto begin = sregex_iterator(line.begin(), line.end(), attr_regex);
    auto end = sregex_iterator();
    bool matched = true;
    for (sregex_iterator it = begin; it != end; ++it) {
      smatch match = *it;
      string attr = match[1].str();
      int attr_value = stoi(match[2].str());
      if (attr == "cats" || attr == "trees") {
        if (gift_sue[attr] < attr_value) {
        } else {
          matched = false;
          break;
        }

      } else if (attr == "pomeranians" || attr == "goldfish") {
        if (gift_sue[attr] > attr_value) {
        } else {
          matched = false;
          break;
        }
      } else {
        if (gift_sue[attr] == attr_value) {
        } else {
          matched = false;
          break;
        }
      }
    }
    if (matched) {
      cout << sue_no << endl;
      break;
    }
  }
  return 0;
}