#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mod(int a, int n) {
  int r = a % n;
  if (r < 0) {
    r += n;
  }
  return r;
}

int main() {
  FILE *file = fopen("./2016_day1.txt", "r");
  int x = 0;
  int y = 0;
  char *data = NULL;
  size_t size = 0;
  getline(&data, &size, file);
  char *token = strtok(data, ", ");
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int current_dir = 0;
  while (token != NULL) {
    if (token[0] == 'R') {
      current_dir += 1;
    } else if (token[0] == 'L') {
      current_dir -= 1;
    }
    current_dir = mod(current_dir, 4);
    int d = atoi(token + 1);
    x += directions[current_dir][0] * d;
    y += directions[current_dir][1] * d;
    token = strtok(NULL, ", ");
  }
  int dist = abs(x) + abs(y);
  printf("%d\n", dist);
  free(data);
  fclose(file);
  return 0;
}
