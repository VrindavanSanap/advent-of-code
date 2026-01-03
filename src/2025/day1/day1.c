#include <stdio.h>
#include <stdlib.h>
int mod(int a, int n) {
  int r = a % n;
  if (r < 0) {
    r += n;
  }
  return r;
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
  while (fgets(line, sizeof(line), fp)) {
    // printf("%s", line);
    // parse line into direction and distance
    direction = line[0];
    distance = atoi(&line[1]);
    printf("direction = %c distance = %d position = %d\n", direction, distance,
           position);
    if (direction == 'L') {
      position -= distance;
      position = mod(position, 100);
    } else if (direction == 'R') {
      position += distance;
      position = mod(position, 100);
    }
    if (position == 0) {
      sum++;
    }
    printf("updated position = %d\n", position);
  }
  printf("sum = %d\n", sum);
  fclose(fp);
  return 0;
}