#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    line[strcspn(line, "\n")] = 0;

    printf("%s \n", line);
  }

  if (line) {
    free(line);
  }

  fclose(file);
  return 0;
}
