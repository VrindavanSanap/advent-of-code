#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char line[100];  // Assuming the line length won't exceed 100 characters

  printf("Enter a line with numbers separated by spaces: ");
  fgets(line, sizeof(line), stdin);  // Read a line from the user

  char *token = strtok(line, " ");  // Tokenize the line based on spaces

  while (token != NULL) {
    int num = atoi(token);  // Convert the token to an integer
    printf("Number: %d\n", num);
    token = strtok(NULL, " ");  // Get the next token
  }

  return 0;
}
