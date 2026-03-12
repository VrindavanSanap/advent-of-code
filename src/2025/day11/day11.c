#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

int main(int argc, char *argv[]) {
  char *file_name = "./day11.txt";
  if (argc == 2) {
    file_name = argv[1];
  }
  FILE *file = fopen(file_name, "r");
  if (!file) {
    perror("Error opening file");
    return 1;
  }

  char *line = NULL;
  size_t line_len = 0;

  while (getline(&line, &line_len, file) != -1) {
    line[strcspn(line, "\n")] = '\0';
    printf("%s\n", line);
  }

  free(line);
  fclose(file);
  return 0;
}
