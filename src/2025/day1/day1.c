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
  char* file_name = "2025_day1.txt";
  FILE* fp = fopen(file_name, "r");
  char line[32];
  char direction;
  int distance;
  int position = 50;
  if (fp == NULL) {
    printf("Failed to read the file\n");
    return 1;
  }
  int sum = 0;
  while (fgets(line, sizeof(line), fp)) {
    direction = line[0];
    distance = atoi(&line[1]);
    if (direction == 'L') {
      position = mod(position - distance, 100);
    } else if (direction == 'R') {
      position = mod(position + distance, 100);
    }
    if (position == 0) {
      sum++;
    }
  }
  printf("%d\n", sum);
  fclose(fp);
  return 0;
}