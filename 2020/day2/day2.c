#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>
#include <assert.h>



int main(){
  FILE* file = fopen("day2_smol.txt", "r");
  if(file == NULL){
    perror("Unable to open file");
    return 1; 
  }
  char *pattern = "([0-9]+)-([0-9]+) ([a-zA-Z])";

int count;
  char line[31];
  int n_valid;
char c;
regex_t preg;
  assert(regcomp(&preg, pattern, REG_EXTENDED) == 0);
  const size_t n_match = 5; // 1 for full match + 2 for groups
  regmatch_t p_match[n_match];
int min;
   int max;



  while(fgets(line, sizeof(line), file) ){

   count = 0;
  int res = regexec(&preg, line, n_match, p_match, 0);
  int match_len;
  char buffer[20]; 

  match_len = p_match[1].rm_eo - p_match[1].rm_so;
  strncpy(buffer, line + p_match[1].rm_so, match_len);
  buffer[match_len] = '\0'; 

  min = atoi(buffer);
  printf("min : %d\n", min);

  match_len = p_match[2].rm_eo - p_match[2].rm_so;
  strncpy(buffer, line+ p_match[2].rm_so, match_len);
  max = atoi(buffer);
  printf("max: %d\n", max);


  match_len = p_match[3].rm_eo - p_match[3].rm_so;
  strncpy(buffer, line+ p_match[3].rm_so, match_len);
  buffer[match_len] = '\0'; 
  c = buffer[0];
  printf("char: %c\n", c);



 


    for (int i = 7;i< strlen(line);i++){
      printf("%c", line[i]) ;
      if (line[i] ==c){
        count ++;
      }
    }
    if (count <= max && count>= min){
      n_valid++;
      printf("count = %d \n", count);
      printf("Valid %d \n", n_valid);
    }else{

      printf("count = %d \n", count);
      printf("Invalid %d \n", n_valid);
    }

    printf("---\n");
  }
  regfree(&preg);
  return 0;
}
