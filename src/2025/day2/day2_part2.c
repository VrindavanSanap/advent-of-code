#include <math.h>
#include <stdbool.h>
#include <stdio.h>
unsigned long long count_digits(unsigned long long num) {
  unsigned long long count = 0;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}
unsigned long long ipow(unsigned int num, unsigned int power) {
  unsigned long long result = 1;
  for (unsigned long long i = 0; i < power; i++) {
    result *= num;
  }
  return result;
}

bool check_valid_num_repeat(unsigned long long num, unsigned int num_digits,
                            unsigned int num_repeat) {
  unsigned long long divisor;
  int pattern_len = num_digits / num_repeat;

  unsigned long long divisor_num = ipow(10, (pattern_len * num_repeat)) - 1;
  unsigned long long divisor_den = ipow(10, (pattern_len)) - 1;
  divisor = divisor_num / divisor_den;
  if ((num % divisor) == 0) {
    printf("div-> %llu\n", divisor);
    return false;
  }
  return true;
}
bool check_valid(unsigned long long num) {
  /*
  Returns true if num is valid
  Returns false if num is invalid
  */
  unsigned int num_digits = count_digits(num);
  for (unsigned n_repeat_i = 2; n_repeat_i <= num_digits; n_repeat_i++) {
    if ((num_digits % n_repeat_i) == 0) {
      unsigned int n_repeat = n_repeat_i;
      if (!check_valid_num_repeat(num, num_digits, n_repeat)) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  char* file_name = "day2.txt";
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Failed to read the file");
    return 1;
  }

  char* buffer = NULL;
  ssize_t buffer_size;
  size_t len;
  unsigned long long invalid_sum = 0ULL;
  while ((buffer_size = getdelim(&buffer, &len, ',', fp)) != -1) {
    printf("%s\n", buffer);
    unsigned long long start_num;
    unsigned long long end_num;
    if (sscanf(buffer, "%llu-%llu", &start_num, &end_num) == 2) {
      printf("%llu --> %llu\n", start_num, end_num);
    } else {
      printf("Parsing failed.\n");
    }
    for (unsigned long long i = start_num; i <= end_num; i++) {
      bool is_not_valid = !check_valid(i);
      if (is_not_valid) {
        invalid_sum += i;
        printf("%llu -> Invalid\n", i);
      } else {
      }
    }
    printf("Sum of invalid IDs = %llu\n", invalid_sum);
  }
  fclose(fp);

  return 0;
}