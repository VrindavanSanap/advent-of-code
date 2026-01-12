#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  char line[50];

  file = fopen("day2.txt", "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }
  int n = 0;
  char c = 0;
  int depth = 0;
  int horiz = 0;
  while (fgets(line, sizeof(line), file)) {
    int len = (int)strlen(line);
    printf("%s", line);
    n = atoi(&line[len - 2]);
    c = line[0];
    printf("%c %d\n", c, n);
    if (c == 'f') {
      horiz += n;
    } else if (c == 'u') {
      depth -= n;
    } else if (c == 'd') {
      depth += n;
    }
    printf("depth: %d horiz: %d res: %d\n", depth, horiz, depth * horiz);
  }
  fclose(file);
  return 0;
}
