#include <iostream>
#include <set>
using namespace std;

int main() {
  FILE* file_pointer;
  char filename[] = "day1.txt";
  char buffer[20];
  int sum = 0;
  set<int> visited;
  visited.insert(sum);
  bool found = false;
  while (!found) {
    file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
      printf("Unable to open file.\n");
      return 1;
    }

    while (fgets(buffer, sizeof(buffer), file_pointer) != NULL && !found) {
      int len = (int)strlen(buffer);
      char sign = buffer[0];
      int value = atoi(buffer);
      sum += value;
      std::cout << "sum = " << sum << std::endl;
      int sum2 = sum;
      auto it = visited.find(sum2);
      if (it != visited.end()) {
        std::cout << "Element " << sum << " exists in the set." << std::endl;
        found = true;
      } else {
        cout << sum << endl;
      }
      visited.insert(sum);
    }

    std::fclose(file_pointer);
  }
  return 0;
}
