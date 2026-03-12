#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool is_char(char c) { return (c >= 'A' && c <= 'Z'); }
char* get_decompressed(char* str) {
  char* decompressed_line = malloc(strlen(str));
  size_t decomp_len = strlen(str);
  int len = strlen(str);
  size_t write_ptr = 0;
  for (size_t read_ptr = 0; read_ptr < len; read_ptr++) {
    char c = str[read_ptr];
    // printf("char:%c\n", c);
    if (is_char(c)) {
      decompressed_line[write_ptr] = c;
      write_ptr++;
      if (write_ptr >= decomp_len) {
        decomp_len *= 2;
        decompressed_line = realloc(decompressed_line, decomp_len);
      }
    } else if (c == '(') {
      int n_chars = 0;
      int multiplier = 0;
      sscanf(str + read_ptr, "(%dx%d)", &n_chars, &multiplier);
      while (str[read_ptr] != ')') {
        read_ptr++;
      }
      //   printf("%s\n", str + read_ptr);
      //   printf("n_chars:%d multiplier:%d\n", n_chars, multiplier);
      for (int m = 0; m < multiplier; m++) {
        for (int i = 1; i <= n_chars; i++) {
          decompressed_line[write_ptr] = str[read_ptr + i];
          write_ptr++;
          if (write_ptr >= decomp_len) {
            decomp_len *= 2;
            decompressed_line = realloc(decompressed_line, decomp_len);
          }
        }
      }
      read_ptr += n_chars;
    }
  }
  return decompressed_line;
}
bool contains_marker(char* str) { return (strchr(str, '(') != NULL); }
int main() {
  char* file_name = "day9.txt";
  FILE* file = fopen(file_name, "r");
  char* line = NULL;
  size_t size = 0;
  getline(&line, &size, file);
  fclose(file);
  char* decompressed_line;
  while (contains_marker(line)) {
    decompressed_line = get_decompressed(line);
    free(line);
    line = decompressed_line;
    printf("Decompressed so far: %s %lu\n", decompressed_line,
           strlen(decompressed_line));
  }
  //   free(line);
  //   free(test_line);
  free(decompressed_line);
  return 0;
}
