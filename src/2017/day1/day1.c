#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file_pointer;
  char filename[] = "day1.txt";
  char buffer[2];

  file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    printf("error opening the file.\n");
    return 1;
  }
  int i = 0;
  int sum = 0;
  int first_num;
  int prev = 0;
  int curr = 0;
  while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
    size_t buffer_size = strlen(buffer);
    if (i++ == 0) {
      first_num = atoi(&buffer[0]);
    }
    if (buffer[0] == ' ' || buffer[0] == '\n') {
      prev = first_num;
      if (prev == curr) {
        sum += prev;
      }
      printf("%d) %d%d %d\n", i, prev, curr, sum);
      break;
    }

    prev = curr;
    curr = atoi(&buffer[0]);
    if (prev == curr) {
      sum += prev;
    }
    printf("%d) %d%d %d\n", i, prev, curr, sum);
  }
  fclose(file_pointer);
  return 0;
}
