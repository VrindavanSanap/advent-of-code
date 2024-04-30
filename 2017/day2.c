#include <ctype.h>
#include <limits.h>  // Include limits.h for INT_MAX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
char* strip(char* str) {
  char* start = str;
  while (*start && isspace(*start)) {
    start++;
  }
  char* end = str + strlen(str) - 1;
  while (end > start && isspace(*end)) {
    *end-- = '\0';
  }
  size_t len = end - start + 1;
  char* trimmed_str = (char*)malloc((len + 1) * sizeof(char));
  if (trimmed_str == NULL) {
    return NULL;  // Memory allocation failed
  }
  memcpy(trimmed_str, start, len);
  trimmed_str[len] = '\0';  // Null-terminate the string
  return trimmed_str;
}
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
    printf("max = %d min =  %d ", max ,min);
    sum += (max - min);
    printf("sum = %d \n", sum);

  }

  fclose(file);
  return 0;
}
