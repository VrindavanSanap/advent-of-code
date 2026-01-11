#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_BITS 12
int main() {
  char* file_name = "day3.txt";
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", file_name);
    return 1;
  }
  int bits_frequency[NUM_BITS] = {0};
  char* line = NULL;
  size_t len;
  while (getline(&line, &len, file) != -1) {
    // remove new line character if present
    line[strcspn(line, "\n")] = 0;
    printf("Read line: %s \n", line);

    for (int i = 0; i < NUM_BITS; i++) {
      if (line[i] == '1') {
        bits_frequency[i]++;
      } else {
        bits_frequency[i]--;
      }
    }
  }
unsigned  int sum = 0;
unsigned  int sum_inv = 0;
  unsigned int mask = (1U << NUM_BITS) - 1;
  for (int i = 0; i < NUM_BITS; i++) {
    bool is_one = bits_frequency[i] > 0;
    sum += is_one << (NUM_BITS - 1 - i);
    printf("%d", is_one);
  }
  sum_inv = (~sum) & mask;
  printf("\nSum: %d\n", sum);
  printf("Sum Inverse: %d\n", sum_inv);
  printf("final result: %d\n", sum * sum_inv);
  free(line);
  fclose(file);
  return 0;
}
