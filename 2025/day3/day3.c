#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  char* file_name = "day3_smol.txt";
  char* line = NULL;  // Pointer to the buffer
  size_t len = 0;     // Size of the allocated buffer
  ssize_t read;       // Number of characters read
  FILE* fp;
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    printf("%s", line);
  }

  free(line);
  fclose(fp);
  fclose(fp);

  return 0;
}
