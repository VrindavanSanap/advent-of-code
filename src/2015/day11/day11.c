#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool has_increasing_straight(const char* pass) {
  // Placeholder implementation
  int len = strlen(pass);
  for (int i = 0; i < len - 3; i++) {
    if (pass[i + 1] == pass[i] + 1 && pass[i + 2] == pass[i] + 2) {
      return true;
    }
  }
  return false;
}
bool contains_no_invalid_chars(const char* pass) {
  // Placeholder implementation
  int len = strlen(pass);
  for (int i = 0; i < len; i++) {
    if (pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'l') {
      return false;
    }
  }
  return true;
}
bool has_two_non_overlapping_pairs(const char* pass) {
  // Placeholder implementatio
  int len = strlen(pass);
  int pair_count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (pass[i] == pass[i + 1]) {
      pair_count++;
      i++;
    }
  }
  if (pair_count < 2) {
    return false;
  }
  return true;
}
bool is_valid_password(const char* pass) {
  // Placeholder implementation
  if (!has_increasing_straight(pass)) {
    return false;
  }
  if (!contains_no_invalid_chars(pass)) {
    return false;
  }
  if (!has_two_non_overlapping_pairs(pass)) {
    return false;
  }
  return true;
}

bool increment_password(char* pass, char* max_pass, size_t index) {
  // Placeholder implementation

  assert(strcmp(pass, max_pass) != 0);
  if (pass[index] == 'z') {
    pass[index] = 'a';
    return increment_password(pass, max_pass, index - 1);
  } else {
    pass[index] += 1;
  }

  return true;
}
int main() {
  char* pass = strdup("cqjxxyzz");
  size_t len = strlen(pass);

  char* max_pass = calloc(len + 1, sizeof(char));
  for (size_t i = 0; i < len; i++) {
    max_pass[i] = 'z';
  }
  max_pass[len] = '\0';

  while (true) {
    increment_password(pass, max_pass, len - 1);
    if (is_valid_password(pass)) {
      break;
    }
  }

  printf("%s\n", pass);
  free(max_pass);
}
