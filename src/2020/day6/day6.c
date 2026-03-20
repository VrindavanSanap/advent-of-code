#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

int compare_chars(const void *a, const void *b) {
  char char_a = *(const char *)a;
  char char_b = *(const char *)b;
  return (char_a > char_b) - (char_a < char_b);
}

int main() {
  FILE *file = fopen("2020_day6_smol.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    // line[strcspn(line, "\n")] = 0;
    if (strcmp(line, "\n") == 0) {
      printf("--\n");
    } else {
      // remmove the newline a tthe end
      line[strcspn(line, "\n")] = 0;
      printf("%s\n", line);
    }
  }

  if (line) {
    free(line);
  }

  fclose(file);
  return 0;
}
