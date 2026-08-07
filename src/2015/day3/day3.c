#include <stdio.h>
#include <string.h>

#include "set.h"
typedef struct {
  int x;
  int y;
} coords;
int compare_coords(const void *cp1, const void *cp2) {
  const coords *c1 = (const coords *)cp1;
  const coords *c2 = (const coords *)cp2;

  if ((c1->x == c2->x) & (c1->y == c2->y)) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  FILE *file = fopen("2015_day3.txt", "r");
  int ch;
  int n_presents = 0;
  int x = 0;
  int y = 0;
  set *s = set_build(sizeof(coords), compare_coords);
  while ((ch = fgetc(file)) != EOF) {
    if (ch == '<') {
      x -= 1;
    }
    if (ch == '>') {
      x += 1;
    }
    if (ch == '^') {
      y += 1;
    }
    if (ch == 'v') {
      y -= 1;
    }
    coords c = {x, y};
    set_insert(s, &c);
  }

  n_presents = set_get_size(s);
  printf("%d", n_presents);
  fclose(file);
  return 0;
}
