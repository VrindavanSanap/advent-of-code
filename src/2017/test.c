#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *str) {
  // Trim leading spaces
  char *start = str;
  while (*start && isspace(*start)) {
    start++;
  }

  // Trim trailing spaces
  char *end = str + strlen(str) - 1;
  while (end > start && isspace(*end)) {
    *end-- = '\0';
  }

  // Calculate the length of the trimmed string
  size_t len = end - start + 1;

  // Allocate memory for the trimmed string
  char *trimmed_str = (char *)malloc((len + 1) * sizeof(char));
  if (trimmed_str == NULL) {
    return NULL;  // Memory allocation failed
  }

  // Copy the trimmed string to the newly allocated memory
  memcpy(trimmed_str, start, len);
  trimmed_str[len] = '\0';  // Null-terminate the string

  return trimmed_str;
}

int main() {
  char str[] = "   Hello, World!   ";
  printf("Before: '%s'\n", str);
  char *trimmed_str = trim(str);
  if (trimmed_str != NULL) {
    printf("After:  '%s'\n", trimmed_str);
    free(trimmed_str);  // Don't forget to free allocated memory
  } else {
    printf("Memory allocation failed!\n");
  }
  return 0;
}
