#include <stdio.h>
int main() {
  FILE *file = fopen("2015_day1.txt", "r");
  int floor = 0;
  int ch;
  while ((ch = getc(file)) != EOF) {
    if (ch == '(') {
      floor++;
    } else if (ch == ')') {
      floor--;
    }
  }

  fclose(file);
  printf("Floor reached is %d\n", floor);
  return 0;
}
