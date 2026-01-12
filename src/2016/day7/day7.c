#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool contains_abba(char* segment) {
  size_t len = strlen(segment);
  for (size_t i = 0; i < 4; i++) {
    if (segment[i] != segment[i + 1] && segment[i] == segment[i + 3] &&
        segment[i + 1] == segment[i + 2]) {
      return true;
    }
  }
  return false;
}
bool validate_line(char* line) {
  int is_valid = false;
  size_t len = strlen(line);
  bool hypernet_seq = false;
  for (size_t i = 0; i < len - 4; i++) {
    if (line[i + 3] == '[') {
      hypernet_seq = true;
      i += 4;
    }
    if (line[i + 3] == ']') {
      hypernet_seq = false;
      i += 4;
    }
    // printf("%.*s", 4, line + i);
    if (hypernet_seq) {
      if (contains_abba(&line[i])) {
        return false;
      }

      //   printf(" hyper \n");
    } else {
      if (contains_abba(&line[i])) {
        is_valid = true;
      }

      //   printf(" nonhyper \n");
    }
  }
  return is_valid;
}
int main() {
  char* file_name = "day7.txt";
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", file_name);
    return 1;
  }
  char* line = NULL;
  size_t size = 0;

  int braket_open = 0;
  int braket_close = 0;
  int total_valid = 0;
  while (getline(&line, &size, file) != -1) {
    // printf("%s\n", line);
    total_valid += validate_line(line);
  }
  printf("%d 0", total_valid);
}