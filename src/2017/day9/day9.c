#include <stdio.h>
int main() {
  FILE *file = fopen("2017_day2.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  return 0;
}