#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"
bool is_aba(char aba[3]) { return (aba[0] == aba[2]) && (aba[0] != aba[1]); }
dynamic_array* get_abas(char* line) {
  dynamic_array* abas = da_build(sizeof(char[3]));
  size_t len = strlen(line);
  // returns abas outside the hypernet sequence
  int i;
  for (i = 0; i < len - 2; i++) {
    if (line[i + 2] == '[') {
      while (line[i] != ']' && i < len - 2) {
        i++;
      }
    } else {
      // printf("%c%c%c", line[i], line[i + 1], line[i + 2]);
      char aba[3] = {line[i], line[i + 1], line[i + 2]};
      if (is_aba(aba)) {
        da_insert_last(abas, &aba);
        // printf(" - aba\n");
      } else {
        // printf("\n");
      }
    }
  }
  return abas;
}
dynamic_array* get_babs(char* line) {
  dynamic_array* babs = da_build(sizeof(char[3]));
  size_t len = strlen(line);
  // returns babs inside the hypernet sequence
  bool inside = false;
  for (int i = 0; i < len - 2; i++) {
    if (inside == false) {
      if (line[i] == '[') {
        inside = true;
      }
    } else {
      if (line[i + 2] == ']') {
        inside = false;
      } else {
        char aba[3] = {line[i], line[i + 1], line[i + 2]};
        if (is_aba(aba)) {
          da_insert_last(babs, &aba);
        }
      }
    }
  }

  return babs;
}
int corresponding_abas_babs(dynamic_array* abas, dynamic_array* babs) {
  int len_abas = da_get_size(abas);
  int len_babs = da_get_size(babs);

  char aba[3];
  char bab[3];
  for (int i = 0; i < len_abas; i++) {
    da_get_at(abas, i, &aba);
    for (int j = 0; j < len_babs; j++) {
      da_get_at(babs, j, &bab);

      if (aba[0] == bab[1] && aba[1] == bab[0]) {
        return true;
      } else {
        // printf("%s %s\n", aba, bab);
      }
    }
  }
  return false;
}
bool validate_line(char* line) {
  int is_valid = false;
  // returns true if there a corresponding bab in the hypernet sequence
  // for the aba in the non hypernet sequence
  dynamic_array* abas = get_abas(line);
  dynamic_array* babs = get_babs(line);
  int len_abas = da_get_size(abas);
  int len_babs = da_get_size(babs);
  char aba[4];
  aba[3] = '\0';
  for (int i = 0; i < len_abas; i++) {
    da_get_at(abas, i, &aba);
  }
  for (int i = 0; i < len_babs; i++) {
    da_get_at(babs, i, &aba);
  }
  bool result = corresponding_abas_babs(abas, babs);
  da_free(abas);
  da_free(babs);

  return result;
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
    total_valid += validate_line(line);
  }

  printf("%d", total_valid);
}