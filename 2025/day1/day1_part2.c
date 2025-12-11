#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int mod(int a, int n) {
  int r = a % n;
  if (r < 0) {
    r += n;
  }
  return r;
}
bool valid_pos(int given_postion) {
  if (given_postion >= 0 && given_postion < 100) {
    return true;
  } else {
    return false;
  }
}
int count_crossing(int position, int new_position, int distance) {
  int n_crossings = 0;
  if (new_position == 0 || new_position == 100) {
    return 1;
  }
  if (valid_pos(new_position)) {
    return 0;
  }
  n_crossings = abs(new_position / 100);
  if (new_position < 0) {
    n_crossings += 1;
  }
  if (position == 0) {
    return n_crossings - 1;
  }
  return n_crossings;
}

int main() {
  char* file_name = "day1.txt";
  FILE* fp = fopen(file_name, "r");
  char line[256];
  char direction;
  int distance;
  int position = 50;
  if (fp == NULL) {
    printf("Failed to read the file");
    return 1;
  }
  int sum = 0;
  int new_postion;
  while (fgets(line, sizeof(line), fp)) {
    // printf("%s", line);
    // parse line into direction and distance
    direction = line[0];
    distance = atoi(&line[1]);
    printf("%02d +  %c%02d -->", position, direction, distance);
    if (direction == 'L') {
      new_postion = position - distance;
    } else if (direction == 'R') {
      new_postion = position + distance;
    }
    sum += count_crossing(position, new_postion, distance);
    position = mod(new_postion, 100);
    printf(" %02d %d \n", position, sum);
  }
  printf("sum = %d\n", sum);
  fclose(fp);
  return 0;
}