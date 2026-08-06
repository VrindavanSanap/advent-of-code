#include <stdio.h>
int main() {
  FILE *file = fopen("2015_day1.txt", "r");
  int floor = 0;
  int ch;
  int pos = 0;
  while ((ch = getc(file)) != EOF) {
    pos++;
    if (ch == '(') {
      floor++;
    } else if (ch == ')') {
      floor--;
    }
    if (floor == -1){
      printf("Basement reached at char position %d\n", pos);
      break;
    }
  }

  fclose(file);
  return 0;
}
