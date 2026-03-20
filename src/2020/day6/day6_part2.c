#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("day6.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    // remove newline char
    line[strcspn(line, "\n")] = 0;

    // TODO: part 2 logic here
  }

  if (line) {
    free(line);
  }

  fclose(file);
  return 0;
}
