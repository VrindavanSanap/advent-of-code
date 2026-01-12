#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
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
tuple<string, int> get_first_int_int(string line) {
  int int_index = -1;
  string number_string = "";
  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      number_string += line[i];
      int_index = i;
      break;
    }
  }
  return make_tuple(number_string, int_index);
}
tuple<string, int> get_last_int_int(string line) {
  int int_index = -1;
  string number_string = "";
  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      number_string = line[i];
      int_index = i;
    }
  }
  return make_tuple(number_string, int_index);
}
tuple<string, int> get_first_string_int(string line) {
  vector<string> numbers;
  numbers.push_back("one");
  numbers.push_back("two");
  numbers.push_back("three");
  numbers.push_back("four");
  numbers.push_back("five");
  numbers.push_back("six");
  numbers.push_back("seven");
  numbers.push_back("eight");
  numbers.push_back("nine");
  int lowest_position = 100;
  int number = -1;
  for (int i = 0; i < numbers.size(); i++) {
    if (line.find(numbers[i]) != string::npos) {
      int position = line.find(numbers[i]);
      if (position < lowest_position) {
        lowest_position = position;
        number = i + 1;
      }
    }
  }

  if (lowest_position == 100) {
    number = -1;
    lowest_position = -1;
  }
  return make_tuple(to_string(number), lowest_position);
}

tuple<string, int> get_last_string_int(string line) {
  vector<string> numbers;
  numbers.push_back("one");
  numbers.push_back("two");
  numbers.push_back("three");
  numbers.push_back("four");
  numbers.push_back("five");
  numbers.push_back("six");
  numbers.push_back("seven");
  numbers.push_back("eight");
  numbers.push_back("nine");
  int heighest_position = -1;
  int number = -1;
  for (int i = 0; i < numbers.size(); i++) {
    if (line.find(numbers[i]) != string::npos) {
      string n = numbers[i];
      int position = line.rfind(n);
      if (position > heighest_position) {
        heighest_position = position;
        number = i + 1;
      }
    }
  }

  return make_tuple(to_string(number), heighest_position);
  //    return  make_tuple(to_string(number), lowest_position);
}
string get_first_number(string line) {
  string int_int;
  int int_int_index;
  string string_int;
  int string_int_index;
  tie(int_int, int_int_index) = get_first_int_int(line);
  tie(string_int, string_int_index) = get_first_string_int(line);
  if (string_int_index == -1 && int_int_index == -1) {
    return "";
  }
  if (string_int_index != -1 && int_int_index == -1) {
    return string_int;
  }
  if ((string_int_index == -1 && int_int_index != -1)) {
    return int_int;
  }
  if (string_int_index > int_int_index) {
    return int_int;
  } else {
    return string_int;
  }
}

string get_last_number(string line) {
  string int_int;
  int int_int_index;
  string string_int;
  int string_int_index;
  tie(int_int, int_int_index) = get_last_int_int(line);
  tie(string_int, string_int_index) = get_last_string_int(line);

  if (string_int_index == -1 && int_int_index == -1) {
    return "";
  }
  if (string_int_index != -1 && int_int_index == -1) {
    return string_int;
  }
  if ((string_int_index == -1 && int_int_index != -1)) {
    return int_int;
  }
  if (string_int_index > int_int_index) {
    return string_int;
  } else {
    return int_int;
  }
}
int main() {
  // string string_int;
  // int string_int_index;
  // tie(string_int, string_int_index) =
  // get_last_string_int("4nineeightseven2"); cout << "4nineeightseven2"
  //      << "-" << string_int << "-" << string_int_index << endl;

  ifstream file("day1.txt");
  vector<std::string> lines;
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  int sum = 0;
  int i = 0;
  for (const auto &l : lines) {
    string number = "";
    string n1 = get_first_number(l);
    string n2 = get_last_number(l);
    int n = stoi(n1 + n2);
    cout << i++ << "-" << l << "-" << n << endl;
    sum += n;
  }
  cout << "sum: " << sum << endl;
  return 0;
}
