#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>



int main(){
  FILE* file = fopen("day2.txt", "r");
  if(file == NULL){
    perror("Unable to open file");
    return 1; 
  }
  char line[31];
  int n_valid;

  char pattern_1 = "[0-9]+";
  while(fgets(line, sizeof(line), file) ){
    printf("%s", line);
    regex_t regex;
    int ret;
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
      fprintf(stderr, "Could not compile regex\n");
      return 1;
    }
  }
  return 0;
}
