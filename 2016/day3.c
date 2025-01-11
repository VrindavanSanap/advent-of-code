#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool valid_triangle(int side_a, int side_b, int side_c){
  if (side_a + side_b <= side_c){
    return false;
  }
  if (side_b + side_c <= side_a){
    return false;
  }
  if (side_c + side_a <= side_b){
    return false;
  }
  return true;
}
int main(){


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
  while(fgets(line, sizeof(line), file)){
    int result = sscanf(line, "%d %d %d", &side_a, &side_b, &side_c);
    printf("%d ", i++);
    printf("%d %d %d ", side_a, side_b, side_c);
    if (valid_triangle(side_a, side_b, side_c)){
      printf("VALID ");
      n_valid++;
    }

    printf("%d \n", n_valid);
  }
  return 0;

}
