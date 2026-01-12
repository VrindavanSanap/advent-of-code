#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* file_name = "day4.txt";
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  FILE* fp;
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    line[strcspn(line, "\n")] = '\0';
    printf("%s\n", line);
  }

  free(line);
  fclose(fp);

  return 0;
}
