#include <stdio.h>
#include <string.h>

int main() {
  // IMPORTANT: strtok modifies the string, so we use a char array.
  // If your string was a const literal like char *str = "...",
  // you would need to copy it to a mutable buffer first.
  char str[] = "hello,world,from,c";
  const char *delimiter = ",";

  // Get the first token
  char *token = strtok(str, delimiter);

  // Loop through the other tokens
  while (token != NULL) {
    printf("'%s'\n", token);
    // Get the next token. Note the NULL first argument.
    token = strtok(NULL, delimiter);
  }

  return 0;
}
