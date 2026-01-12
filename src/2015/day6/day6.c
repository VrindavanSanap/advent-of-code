#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("day5.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char line[100];
  int i = 0;
  int total_nice_strings = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
  }
}
