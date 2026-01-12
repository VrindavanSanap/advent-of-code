#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool letter_repeat_with_gap(char line[]) {
  size_t line_len = strlen(line);
  for (int i = 0; i < line_len - 2; i++) {
    char ch1 = line[i];
    char ch2 = line[i + 2];
    if (ch1 == ch2) {
      return true;
    }
  }
  return false;
}
bool contains_bad_substrings(char line[]) {
  char *substrings[] = {"ab", "cd", "pq", "xy"};
  int num_substrings = sizeof(substrings) / sizeof(substrings[0]);
  for (int i = 0; i < num_substrings; i++) {
    if (strstr(line, substrings[i]) != NULL) {
      return true;
    }
  }
  return false;
}

bool contains_non_overlaping_repeat_bigram(char line[]) {
  size_t line_len = strlen(line);

  for (int i = 0; i < line_len - 3; i++) {
    char *bigram = (char *)malloc(3);
    char *remaining = (char *)malloc(line_len);
    strncpy(bigram, line + i, 2);
    strncpy(remaining, line + i + 2, line_len - i - 2);
    strcat(bigram, "\0");
    strcat(remaining, "\0");
    if (strstr(remaining, bigram) != NULL) {
      return true;
    }
  }
  return false;
}

bool is_nice_string(char line[]) {
  size_t line_len = strlen(line);
  printf("%s s: %zu \n", line, line_len);
  bool letter_repeat_with_gap_ = letter_repeat_with_gap(line);
  printf("letter_repeat_with_gap_ %d \n", letter_repeat_with_gap_);
  bool contains_non_overlaping_repeat_bigram_ =
      contains_non_overlaping_repeat_bigram(line);
  printf("contains_non_overlaping_repeat_bigram_ %d \n",
         contains_non_overlaping_repeat_bigram_);
  if (letter_repeat_with_gap_ && contains_non_overlaping_repeat_bigram_) {
    return true;
  }
  return false;
}

int main() {
  FILE *file = fopen("day5.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char line[100];
  int i = 0;
  int total_nice_strings = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    bool is_nice_string_ = is_nice_string(line);
    printf("is_nice_string_ %s \n", is_nice_string_ ? "true" : "false");
    total_nice_strings += is_nice_string_;
    printf("Total nice strings: %d\n", total_nice_strings);
    printf("---\n");
  }

  fclose(file);
  return 0;
}
