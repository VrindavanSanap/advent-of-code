#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int get_floor(char buffer[]) {
  int buffer_len = strlen(buffer);
  int floor = 0;
  for (int i = 0; i < buffer_len; i++) {
    if (buffer[i] == '(') {
      floor++;
    } else if (buffer[i] == ')') {
      floor--;
    }
  }
  return floor;
}

int main() {
  FILE *file = fopen("day1.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[MAX_LINE_LENGTH];
  int line_number = 0;

  int floor = 0;
  // fgets reads one line (or up to MAX_LINE_LENGTH-1 chars)
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    line_number++;
    floor += get_floor(line_buffer);
    printf("reading line %d %d bytes\n", line_number,
           (int)(strlen(line_buffer)));
  }

  if (ferror(file)) {
    perror("Error reading from file");
  }
  fclose(file);
  printf("\nFinished processing %d lines.\n", line_number);
  printf("Floor reached is %d\n", floor);
  return 0;
}