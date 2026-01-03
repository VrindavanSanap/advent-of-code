#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index_of_max_digit(char* given_string, int start_index, int end_index) {
  int max_digit = 0;
  int max_index = 0;
  for (int i = start_index; i <= end_index; i++) {
    if (given_string[i] > max_digit) {
      max_digit = given_string[i];
      max_index = i;
    }
  }
  return max_index;
}
long long get_max_joltage(char* bank) {
  long long max_joltage = 0;
  int last_index = strlen(bank) - 1;
  int n_batteries = 12;
  char max_joltage_str[n_batteries + 1];
  int max_digit_index = -1;
  char max_digit;
  for (int i = 0; i < n_batteries; i++) {
    max_digit_index = index_of_max_digit(bank, max_digit_index + 1,
                                         last_index - (n_batteries - i - 1));
    max_digit = bank[max_digit_index];
    max_joltage_str[i] = max_digit;
  }
  max_joltage_str[n_batteries] = '\0';
  max_joltage = atoll(max_joltage_str);
  printf("%s \n", max_joltage_str);
  return max_joltage;
}
int main() {
  char* file_name = "day3.txt";
  char* line = NULL;  // Pointer to the buffer
  size_t len = 0;     // Size of the allocated buffer
  ssize_t read;       // Number of characters read
  FILE* fp;
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  unsigned  long sum_of_joltages = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    line[strcspn(line, "\n")] = '\0';
    printf("%s \n", line);
    printf("max_joltage-> %lld \n", get_max_joltage(line)); // Changed format specifier to %lld
    sum_of_joltages += get_max_joltage(line);
  }

  free(line);
  printf("sum_of_joltages-> %lu \n", sum_of_joltages);
  fclose(fp);
  fclose(fp);

  return 0;
}
