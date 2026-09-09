#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

int mod(int a, int n) {
  int r = a % n;
  if (r < 0) {
    r += n;
  }
  return r;
}
typedef struct {
  int x;
  int y;
} point;
int compare(const void *a, const void *b) {
  point *point_a = (point *)a;
  point *point_b = (point *)b;
  if (point_a->x != point_b->x) {
    return 1;
  }
  if (point_a->y != point_b->y) {
    return 1;
  }
  return 0;
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
  set *points = set_build(sizeof(point), compare);
  while (token != NULL) {
    if (token[0] == 'R') {
      current_dir += 1;
    } else if (token[0] == 'L') {
      current_dir -= 1;
    }
    current_dir = mod(current_dir, 4);
    int d = atoi(token + 1);
    for (int i = 0; i < d; i++) {
      x += directions[current_dir][0];
      y += directions[current_dir][1];
      point p;
      p.x = x;
      p.y = y;
      if (set_find(points, &p)) {
        int dist = abs(x) + abs(y);
        printf("%d\n", dist);
        exit(0);
      }
      set_insert(points, &p);
    }
    token = strtok(NULL, ", ");
  }
  free(data);
  fclose(file);
  return 0;
}
