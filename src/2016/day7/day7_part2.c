#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
dynamic_array* get_abas(char* line){

	dynamic_array* abas = da_build(sizeof(char[3]));
	size_t len = strlen(line);
	// returns abas outside the hypernet sequence

	return abas;
}
dynamic_array* get_babs(char* line){
	dynamic_array* babs = da_build(sizeof(char[3]));
	size_t len = strlen(line);
	// returns babs inside the hypernet sequence

	return babs;
}
bool validate_line(char* line) {
  int is_valid = false;
  // returns true if there a corresponding bab in the hypernet sequence
  // for the aba in the non hypernet sequence
  dynamic_array* abas = get_abas(line);
  dynamic_array* babs = get_babs(line);
  da_free(abas);
  da_free(babs);
  return is_valid;
}
int main() {
  char* file_name = "day7.txt";
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", file_name);
    return 1;
  }
  char* line = NULL;
  size_t size = 0;

  int total_valid = 0;
  while (getline(&line, &size, file) != -1) {
    // printf("%s\n", line);
    total_valid += validate_line(line);
  }
  printf("%d 0", total_valid);
}