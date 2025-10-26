#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n_vowels(char line[]){
  int n_vowels = 0;
  size_t line_len = strlen(line);
  for (int i = 0; i < line_len; i++) {
    if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
      n_vowels++;
    }
  }
  return n_vowels; 
}

bool has_repeat_chars(char line[]){
  size_t line_len = strlen(line);
  for (int i = 0; i < line_len - 1; i++) {
    char ch1 = line[i];
    char ch2 = line[i+1];
    if (ch1 == ch2){
      return true;
    }
  }
  return false;
}
bool contains_bad_substrings(char line[]){

  char *substrings[] = {"ab", "cd", "pq","xy"};
  int num_substrings = sizeof(substrings) / sizeof(substrings[0]);
  for (int i=0;i< num_substrings;i++){
    if (strstr(line, substrings[i]) != NULL) {
      return true;       
    }
  }
  return false;
}

bool is_nice_string(char line[]){
  size_t line_len = strlen(line);
  printf("size: %zu \n" , line_len);
  int n_vowels_ = n_vowels(line);
  printf("num vowels: %d \n" , n_vowels_);
  bool has_repeat_chars_ = has_repeat_chars(line);
  printf("has repeat chars: %s \n", has_repeat_chars_  ? "true" : "false");
  bool contains_bad_substrings_ = contains_bad_substrings(line);
  printf("contains bad substrings: %s \n", contains_bad_substrings_ ? "true" : "false");
  if ((!contains_bad_substrings_ )&& has_repeat_chars_ && (n_vowels_ >=3)){
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
    int i = 0 ; 
    int total_nice_strings = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
      line[strcspn(line, "\n")] = '\0';
      printf("%s \n", line);
      bool is_nice_string_ = is_nice_string(line);
      printf("is_nice_string: %s \n", is_nice_string_ ? "true" : "false");
      total_nice_strings += is_nice_string_;
      printf("Total nice strings: %d\n", total_nice_strings);
    }
    
    fclose(file);
    return 0;
}

