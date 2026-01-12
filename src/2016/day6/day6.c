#include <stdio.h>
#include <stdlib.h>
int main() {
  char* file_name = "day6.txt";
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", file_name);
    return 1;
  }
  char* line = NULL;
  size_t len = 0;
  int freq[26][8] = {0};
  while (getline(&line, &len, fp) != EOF) {
    for (int i = 0; i < 8; i++) {
      freq[line[i] - 'a'][i]++;
    }
  }
  for (int i = 0; i < 8; i++) {
    int min = 999;
    int min_index = 0;
    for (int j = 0; j < 26; j++) {
      if (freq[j][i] < min) {
        min = freq[j][i];
        min_index = j;
      }
    }
    printf("%c", min_index + 'a');
  }
  free(line);
  fclose(fp);
}