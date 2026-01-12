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
int get_max_joltage(char* bank) {
  int max_joltage = 0;
  int last_index = strlen(bank) - 1;

  int max_digit_index = index_of_max_digit(bank, 0, last_index);
  int second_max_digit_index;
  if (max_digit_index != last_index) {
    second_max_digit_index =
        index_of_max_digit(bank, max_digit_index + 1, last_index);
  } else {
    second_max_digit_index = index_of_max_digit(bank, 0, last_index - 1);
    int temp = max_digit_index;
    max_digit_index = second_max_digit_index;
    second_max_digit_index = temp;
  }
  char max_joltage_str[3] = {bank[max_digit_index],
                             bank[second_max_digit_index], '\0'};

  max_joltage = atoi(max_joltage_str);
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
  int sum_of_joltages = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    line[strcspn(line, "\n")] = '\0';
    printf("%s \n", line);
    printf("max_joltage-> %d \n", get_max_joltage(line));
    sum_of_joltages += get_max_joltage(line);
  }

  free(line);
  printf("sum_of_joltages-> %d \n", sum_of_joltages);
  fclose(fp);
  fclose(fp);

  return 0;
}
