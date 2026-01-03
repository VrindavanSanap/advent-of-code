#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello, World! This is a test.";
  char *token;

  // Get the first token
  token = strtok(str, " ,.!");

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ,.!");
  }

  return 0;
}
