#include <fstream>
#include <iostream>

#include "max_pq_class.cpp"

using namespace std;
int main() {
  Max_pq pq;

  ifstream inputFile("day1.txt");

  if (inputFile.is_open()) {
    string calorie_string;
    int total_elf_calories = 0;
    int calorie_int = 0;
    int elf_no = 1;
    while (getline(inputFile, calorie_string)) {
      if (calorie_string.empty()) {
        calorie_int = 0;
        cout << "Total of elf " << elf_no++ << " = " << total_elf_calories
             << endl;
        cout << "-\n";
        pq.add_node(total_elf_calories);
        pq.display();
        total_elf_calories = 0;
      } else {
        calorie_int = stoi(calorie_string);
        total_elf_calories += calorie_int;
      }
    }
    inputFile.close();
  } else {
    cerr << "Error opening the file." << endl;
  }
  pq.display();
  cout << "Sum: " << pq.sum() << endl;

  return 0;
}
