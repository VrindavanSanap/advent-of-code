#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  file = fopen("day1.txt", "r");
  int m;
  int counter = 0;
  while ((m = fgetc(file)) != EOF) {
    if (m == ',') {
      counter++;
    }
  }
  counter++;  // 1 more for the last number
  int n[counter] = {0};

  fseek(file, 0L, SEEK_SET);

  for (int i = 0; i < counter; i++) {
    if (fscanf(file, "%d,", &n[i]) != 1) {
      break;
    }
  }
  for (int a = 0; a < counter; a++) {
    printf("%d ", n[a]);
  }
}
