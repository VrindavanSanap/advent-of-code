#include <stdio.h>
int main() {
  FILE *file = fopen("day9.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  return 0;
}