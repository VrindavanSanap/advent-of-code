#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int valid_triangle(int side_a, int side_b, int side_c) {
  if (side_a + side_b <= side_c) {
    return false;
  }
  if (side_b + side_c <= side_a) {
    return false;
  }
  if (side_c + side_a <= side_b) {
    return false;
  }

  return true;
}
int main() {

  FILE *file = fopen("day3.txt", "r");

  // Check if the file opened successfully
  if (file == NULL) {
    printf("Error: could not open file.\n");
    return 1; // Exit if unable to open the file
  }
  char line[255];
  int side_a, side_b, side_c;
  int i = 0;
  int n_valid = 0;
  int sides[3][3];
  char *res;
  while (true) {
    for (int j = 0; j < 3; j++) {
      res = fgets(line, sizeof(line), file);
      if (!res) {
        break;
      }
 
      int result = sscanf(line, "%d %d %d", &side_a, &side_b, &side_c);

      sides[j][0] = side_a;
      sides[j][1] = side_b;
      sides[j][2] = side_c;


   }
    if (!res) {
      break;
    }


    for (int j = 0; j < 3; j++) {
      side_a = sides[0][j];
      side_b = sides[1][j];
      side_c = sides[2][j];
      printf("%d ", i++);
      printf("%d %d %d ", side_a, side_b, side_c);
      if (valid_triangle(side_a, side_b, side_c)) {
        printf("VALID %d \n", ++n_valid);
      }
    }


  }
  return 0;
}
