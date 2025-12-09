#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

bool reached_basement(const char buffer[], int* const char_index,
                      int* const current_floor) {
  int buffer_len = strlen(buffer);
  for (int i = 0; i < buffer_len; i++) {
    if (buffer[i] == '(') {
      (*current_floor)++;
    } else if (buffer[i] == ')') {
      (*current_floor)--;
    }
    if (*current_floor == -1) {
      return true;
    }

    (*char_index)++;
  }
  return false;
}

int main() {
  FILE* file = fopen("day1.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[MAX_LINE_LENGTH];
  int line_number = 0;

  int char_index = 0;
  int current_floor = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    printf("reading line %d %d bytes\n", line_number,
           (int)(strlen(line_buffer)));

    if (reached_basement(line_buffer, &char_index, &current_floor)) {
      printf("Floor reached is %d at char pos %d\n", current_floor, char_index + 1);
      break;
    }
    line_number++;
  }

  if (ferror(file)) {
    perror("Error reading from file");
  }
  fclose(file);
  printf("\nFinished processing %d lines.\n", line_number + 1);
  return 0;
}