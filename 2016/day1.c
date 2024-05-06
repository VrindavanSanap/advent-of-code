#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE* fptr; 
  fptr = fopen("day1.txt", "r");
  int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  char *step;
  token = strtok(str, ",");
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ",");
  }
  return 0;
}
