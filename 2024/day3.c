#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(){
  regex_t regex;
  regmatch_t matches[1];
//  const char *pattern = "(mul\\(\\-?\\d+,\\-?\\d+\\))";
//const char *pattern = "\\b(mul\\()[0-9]";
const char *pattern = "[a-zA-Z]*mul\\(\\-?[0-9]+,\\-?[0-9]+\\)";

//const char *pattern = "(mul\\(\\-?\\d+,\\-?\\d+\\))";
//const char *pattern = "[0-9]+";
  char *filename = "day3_smol.txt";
  FILE *fp = fopen(filename, "r");
  char cm_chunk[255];
  if (fp == NULL){
    printf("Could not opem %s", filename);
  }
  int i =0; 
  while (fgets(cm_chunk, sizeof(cm_chunk), fp) != NULL) {
    // Print each line read from the file
        printf("Corrupted Memory: %s", cm_chunk);
  }
 
 // compile the regex
 const char *p = cm_chunk;
 if(regcomp(&regex, pattern, REG_EXTENDED) != 0){
    fprintf(stderr, "Could not compiel regex \n");
    return 0; 
 }
  printf("--\n");
  while(regexec(&regex, p, 1, matches, 0)== 0) {
 
    int start = matches[0].rm_so; // start index of match
    int length = matches[0].rm_eo - matches[0].rm_so;
    char number[length + 1]; // +1 for null terminator 
    strncpy(number, p + start, length);
    number[length] = '\0'; // null terminate;
    printf("Found number %s \n", number);
    p += start + length;

  }
  regfree(&regex);
  return 0;

}
