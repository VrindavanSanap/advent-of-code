#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  char* file_name = "day3.txt";
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Failed to read the file %s\n", file_name);
    return 1;
  }

  // Your code here

  fclose(fp);

  return 0;
}
