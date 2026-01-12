#include <ctype.h>
#include <limits.h>  // Include limits.h for INT_MAX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
int main() {
  FILE* file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  int sum = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    // Do something with the line
    int len = (int)strlen(line);
    char* numbers;
    // printf("(%d) %s \n", len, line);
    numbers = strtok(line, "\t");
    int max = INT_MIN;
    int min = INT_MAX;

    while (numbers != NULL) {
      int num = atoi(numbers);
      if (num < min) {
        min = num;
      }
      if (num > max) {
        max = num;
      }
      numbers = strtok(NULL, "\t");
    }
    printf("max = %d min =  %d ", max, min);
    sum += (max - min);
    printf("sum = %d \n", sum);
  }

  fclose(file);
  return 0;
}
