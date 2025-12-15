#include <stdio.h>

int main() {
  char* file_name = "day2.txt";
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Failed to read the file");
    return 1;
  }
  return 0;
}