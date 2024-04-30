#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  FILE* file_pointer;
  char filename[] = "day1.txt";
  char buffer[20];
  int sum = 0;
  file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
    int len = (int)strlen(buffer);
    char sign = buffer[0];
    int value = atoi(buffer);
    sum += value;
  }

  fclose(file_pointer);
  printf("sum = %d", sum);
  return 0;
}
