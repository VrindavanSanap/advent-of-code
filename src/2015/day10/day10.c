#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* look_and_say(char* num) {
  char* output_num = malloc(2 * strlen(num) + 1);
  strcpy(output_num, num);
  int num_len = strlen(num);
  int i = 0;
  int count = 1;
  char current_char = ' ';
  int write_ptr = 0;
  for (i = 1; i < num_len; i++) {
    if (num[i] == num[i - 1]) {
      count++;
    } else {
      output_num[write_ptr++] = '0' + count;
      output_num[write_ptr++] = num[i - 1];
      count = 1;
    }
  }
  output_num[write_ptr++] = '0' + count;
  output_num[write_ptr++] = num[num_len - 1];
  output_num[write_ptr] = '\0';
  return output_num;
}

int main() {
  char* current_str = strdup("1113222113");
  int iterations = 50;

  printf("%s\n", current_str);
  for (int i = 0; i < iterations; i++) {
    char* next_str = look_and_say(current_str);
    // printf("%s\n", next_str);
    printf("After iteration %d: length = %zu\n", i + 1, strlen(next_str));
    free(current_str);
    current_str = next_str;
  }
  printf("Final length: %zu\n", strlen(current_str));
  free(current_str);

  return 0;
}