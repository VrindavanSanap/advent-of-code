#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_vowels(char line[]) {
  int n_vowels = 0;
  size_t line_len = strlen(line);
  for (int i = 0; i < line_len; i++) {
    if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' ||
        line[i] == 'u') {
      n_vowels++;
    }
  }
  return n_vowels;
}

bool has_repeat_chars(char line[]) {
  size_t line_len = strlen(line);
  for (int i = 0; i < line_len - 1; i++) {
    char ch1 = line[i];
    char ch2 = line[i + 1];
    if (ch1 == ch2) {
      return true;
    }
  }
  return false;
}
bool contains_bad_substrings(char line[]) {
  size_t line_len = strlen(line);
  for (int i = 0; i+1 < line_len ; i++) {
    char ch1 = line[i];
    char ch2 = line[i + 1];
    if ((ch1 == 'a' && ch2 == 'b') || (ch1 == 'c' && ch2 == 'd') ||
        (ch1 == 'p' && ch2 == 'q') || (ch1 == 'x' && ch2 == 'y')) {
      return true;
    }
  }
  return false;
}

bool is_nice_string(char line[]) {
  size_t line_len = strlen(line);
  int n_vowels_ = n_vowels(line);
  bool does_have_repeat_char = has_repeat_chars(line);
  bool does_contain_bad_substrings = contains_bad_substrings(line);
  if ((!does_contain_bad_substrings) && does_have_repeat_char && (n_vowels_ >= 3)) {
    return true;
  }
  return false;
}

int main() {
  FILE *file = fopen("2015_day5.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char *line = NULL;
  int i = 0;
  int total_nice_strings = 0;
  size_t buf_size = 0;
  ssize_t n_read;
  while ((n_read = getline(&line, &buf_size, file)) != -1) {
    line[strcspn(line, "\n")] = '\0';
    bool is_nice_string_ = is_nice_string(line);
    total_nice_strings += is_nice_string_;
  }
  free(line);
  printf("Total nice strings: %d\n", total_nice_strings);
  fclose(file);
  return 0;
}
