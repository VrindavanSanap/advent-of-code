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

  // santa coords
  int sx = 0;
  int sy = 0;

  // robo santa coords
  int rx = 0;
  int ry = 0;

  // -1 santa 1 robosanta
  bool santas_move;

  set *s = set_build(sizeof(coords), compare_coords);
  while ((ch = fgetc(file)) != EOF) {
    if (ch == '<') {
      if (santas_move) {
        sx--;
      } else {
        rx--;
      }
    }
    if (ch == '>') {
      if (santas_move) {
        sx++;
      } else {
        rx++;
      }
    }
    if (ch == '^') {
      if (santas_move) {
        sy++;
      } else {
        ry++;
      }
    }
    if (ch == 'v') {
      if (santas_move) {
        sy--;
      } else {
        ry--;
      }
    }
    if (santas_move) {
      coords c = {sx, sy};
      set_insert(s, &c);
    } else {
      coords c = {rx, ry};
      set_insert(s, &c);
    }
    santas_move = !santas_move;
  }

  n_presents = set_get_size(s);
  printf("%d", n_presents);
  fclose(file);
  return 0;
}
