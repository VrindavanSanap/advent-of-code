#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool is_char(char c) { return (c >= 'A' && c <= 'Z'); }
int get_decompressed_length(char* str) {
  int decomp_len = 0;
  int len = strlen(str);
  for (size_t read_ptr = 0; read_ptr < len; read_ptr++) {
    char c = str[read_ptr];
    printf("char:%c\n", c);
    if (is_char(c)) {
      decomp_len++;
    } else if (c == '(') {
      int n_chars = 0;
      int multiplier = 0;
      sscanf(str + read_ptr, "(%dx%d)", &n_chars, &multiplier);
      printf("%s\n", str + read_ptr);
      printf("n_chars:%d multiplier:%d\n", n_chars, multiplier);
      decomp_len += n_chars * multiplier;
      while (str[read_ptr] != ')') {
        read_ptr++;
      }
      read_ptr += n_chars;
    }
  }
  return decomp_len;
}
int main() {
  // char *file_name = "day9.txt";
  //   FILE* file = fopen(file_name, "r");
  //   char* line = NULL;
  //   size_t size = 0;
  //   getline(&line, &size, file);
  //   fclose(file);
  char test_line[] = "X(8x2)(3x3)ABCY";
  int decomp_len = get_decompressed_length(test_line);
  printf("%d\n", decomp_len);
  //   free(line);
  //   free(test_line);
  return 0;
}
