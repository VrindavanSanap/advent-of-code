#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int get_floor_delta(char buffer[], size_t num_floors) {
  int floor_delta = 0;
  for (int i = 0; i < num_floors; i++) {
    if (buffer[i] == '(') {
      floor_delta++;
    } else if (buffer[i] == ')') {
      floor_delta--;
    }
  }
  return floor_delta;
}

int main() {
  FILE *file = fopen("2015_day1.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char buffer[MAX_LINE_LENGTH];
  int line_number = 0;

  int floor = 0;
  size_t num_floors = 0;
  while (num_floors = fread(buffer, sizeof(char), sizeof(buffer), file)) {
    line_number++;
    floor += get_floor_delta(buffer, num_floors);
    printf("reading line %d %lu bytes\n", line_number, num_floors);
  }

  if (ferror(file)) {
    perror("Error reading from file");
  }
  fclose(file);
  printf("\nFinished processing %d lines.\n", line_number);
  printf("Floor reached is %d\n", floor);
  return 0;
}