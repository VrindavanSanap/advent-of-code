#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

void process_line(char *line, const char *prev_line) {
  int line_size = strlen(line);
  for (int i = 1; i < line_size - 1; i++) {
    if ((prev_line[i] == '|') && (line[i] == '^')) {
      line[i - 1] = '|';
      line[i + 1] = '|';
    }

    if ((prev_line[i] == '|') && (line[i] != '^')) {
      line[i] = '|';
    }
  }
  if ((prev_line[0] == '|') && (line[0] != '^')) {
    line[0] = '|';
  }
  if ((prev_line[line_size - 1] == '|') && (line[line_size - 1] != '^')) {
    line[line_size - 1] = '|';
  }

  if ((line[0] == '^') && (prev_line[0] == '|')) {
    line[1] = '|';
  }
  if ((line[line_size - 1] == '^') && (prev_line[line_size - 1] == '|')) {
    line[line_size - 2] = '|';
  }
}
int count_splits(const char *line, const char *prev_line) {
  int count = 0;
  for (int i = 0; i < strlen(line); i++) {
    if ((prev_line[i] == '|') && (line[i] == '^')) {
      count++;
    }
  }
  return count;
}
int main(int argc, char *argv[]) {
  char *file_name = "./day7.txt";
  FILE *file = fopen(file_name, "r");
  if (!file) {
    perror("Error opening file");
    return 1;
  }

  char *line = NULL;
  char *prev_line = NULL;
  size_t line_len = 0;

  prev_line = (char *)malloc(line_len * sizeof(char));
  getline(&prev_line, &line_len, file);
  prev_line[strcspn(prev_line, "\n")] = '\0';
  int total_splits = 0;
  int splits_i = 0;
  while (getline(&line, &line_len, file) != -1) {
    line[strcspn(line, "\n")] = '\0';
    int line_size = strlen(line);
    process_line(line, prev_line);
    // printf("%s %d\n", line, line_size);
    total_splits += count_splits(line, prev_line);
    free(prev_line);
    prev_line = line;
    line = NULL;
    line_len = 0;
  }
  printf("%d\n", total_splits);
  free(line);
  fclose(file);
  return 0;
}
