#include <stdio.h>

int main() {
  // Define a pointer for the file and open it
  FILE *file = fopen("day2.txt", "r");

  // Check if the file opened successfully
  if (file == NULL) {
    printf("Error: could not open file.\n");
    return 1;  // Exit if unable to open the file
  }

  char arr[5][5] = {{' ', ' ', '1', ' ', ' '},
                    {' ', '2', '3', '4', ' '},
                    {'5', '6', '7', '8', '9'},
                    {' ', 'A', 'B', 'C', ' '},
                    {' ', ' ', 'D', ' ', ' '}};

  int b_arr[5][5] = {
      {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1},
      {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0},
  };

  char ch;
  int x, y;
  int dx, dy;
  dx = 0;
  dy = 0;
  x = 0;
  y = 2;
  while ((ch = fgetc(file)) != EOF) {
    dx = 0;
    dy = 0;

    //    printf("(%d %d), %c \n", x, y, arr[y][x]);
    switch (ch) {
      case 'L':
        dx = -1;
        break;
      case 'R':
        dx = 1;
        break;
      case 'U':
        dy = -1;
        break;
      case 'D':
        dy = 1;
        break;

      case '\n':
        // printf("\\n \n");
        printf("(%d %d), %c \n", x, y, arr[y][x]);
        break;
    }
    if (b_arr[y + dy][x + dx] == 0) {
      dx = 0;
      dy = 0;
    }

    x += dx;
    y += dy;

    if (x < 0) {
      x = 0;
    }
    if (x > 4) {
      x = 4;
    }
    if (y > 4) {
      y = 4;
    }
    if (y < 0) {
      y = 0;
    }
  }

  // Close the file
  fclose(file);
  return 0;
}
