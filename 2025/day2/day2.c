#include <stdio.h>
#include <stdbool.h>
#include <math.h>
unsigned long long count_digits(unsigned long long num){
  unsigned long long count = 0;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}
unsigned long long ipow(unsigned long long num, unsigned long long power){
  unsigned long long result = 1;
  for (unsigned long long i = 0; i < power; i++) {
    result *= num;
  }
  return result;

}

bool check_valid(unsigned long long num){
  /*
  Returns true if num is valid 
  Returns false if num is invalid
  */
  int num_digits = count_digits(num);
  if ((num_digits%2)==1){
    return true;
  }

  unsigned long long divisor = ipow(10, (num_digits / 2));
  unsigned long long first = num / divisor;
  unsigned long long second = num % divisor;
  if (first == second){
    return false;
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

  int n_invalid = 0;
  unsigned long long invalid_sum = 0ULL;
  while ((buffer_size = getdelim(&buffer, &len, ',', fp)) != -1) {
    // buffer[buffer_size - 1] = '\0';
    printf("%s\n", buffer);
    unsigned long long start_num;
    unsigned long long end_num;
    if (sscanf(buffer, "%llu-%llu", &start_num, &end_num) == 2) {
      printf("%llu --> %llu\n", start_num, end_num);
    } else {
      printf("Parsing failed.\n");
    }
    for (unsigned long i = start_num; i <= end_num; i++) {
      bool is_not_valid = !check_valid(i);
      if (is_not_valid){
        invalid_sum += i;
        n_invalid++;
        printf("%lu -> Invalid\n", i);
      }else{
        // printf("%d -> Valid\n", i);
      }
    }
    printf("Number of invalid IDs = %d \n", n_invalid);
    printf("Sum of invalid IDs = %llu\n", invalid_sum);
  }
  fclose(fp);

  return 0;
}