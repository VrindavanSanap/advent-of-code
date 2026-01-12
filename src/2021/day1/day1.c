#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char line[50];

  file = fopen("day1.txt", "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }
  int i = 0;
  int prev = 0;
  int curr = 0;
  int num_inc = -1;
  while (fgets(line, sizeof(line), file)) {
    prev = curr;
    curr = atoi(line);
    if (curr > prev) {
      num_inc += 1;
    }
  }
  printf("%d \n", num_inc);
  fclose(file);
  return 0;
}
