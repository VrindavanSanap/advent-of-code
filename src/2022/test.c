#include <stdio.h>
#include <stdlib.h>

int main() {
  char st1[] = "\n";
  char st2[] = "2\n";
  int at1 = atoi(st1);
  int at2 = atoi(st2);

  if (at1) {
    printf("--");
  }

  if (at2) {
    printf("000");
  }
}
