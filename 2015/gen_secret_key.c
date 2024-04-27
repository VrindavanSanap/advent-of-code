#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char* str = "abcdef";
  int i = 1;
  char* result = (char*)malloc(strlen(str) + 12);
  while (true) {
    sprintf(result, "%s%d", str, i);
    printf("%s \n", result);
    if (i == 100) {
      break;
    };
    i++;
  }

  return 0;
}
