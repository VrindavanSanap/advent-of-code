#include <ctype.h>
#include <limits.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {

  FILE* file = fopen("day4.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  int sum = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    // Do something with the line
    int len = (int)strlen(line);
    char* numbers;
    int n_common = 0;
    line[strlen(line)-1] = ' ';
    numbers = strtok(line, " ");
    while(numbers != NULL){
      printf("%s", numbers);
      numbers = strtok(NULL, " ");
      printf("\n");
    }
    break;
  }
}
