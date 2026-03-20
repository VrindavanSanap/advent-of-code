#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* file = fopen("day6.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    return 1;
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    // remove newline char
    line[strcspn(line, "\n")] = 0;

    // TODO: logic here
  }

  fclose(file);
  return 0;
}
