#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split_string(char* str, char* part1, char* part2) {
    int len = strlen(str);
    int mid = len / 2;
    strncpy(part1, str, mid);
    part1[mid] = '\0';
    strncpy(part2, str + mid, len - mid);
    part2[len - mid] = '\0';
}

char find_common_chars(const char *str1, const char *str2) {
    int count1[256] = {0}; // Assuming ASCII characters
    int count2[256] = {0}; // Assuming ASCII characters
    char common;
    for(int i = 0; str1[i] != '\0'; i++) {
        count1[str1[i]]++;
    }
    for(int i = 0; str2[i] != '\0'; i++) {
        count2[str2[i]]++;
    }
    int count = 0;

    for(int i = 0; i < 256; i++) {
        if(count1[i] > 0 && count2[i] > 0) {
            common = i;
        }
    }
    return common;
}

int main(){
  FILE *file;
  char runsack[100];
  char first_comp[50];
  char second_comp[50];
  
  file = fopen("day3.txt", "r");

  if (file == NULL){
    perror("Error opening file");
    return 1;
  }
  
  while (fgets(runsack, sizeof(runsack), file)) {
    int runsack_len = strlen(runsack) - 1;
    printf("%d %s " ,runsack_len ,runsack);
    split_string(runsack, first_comp, second_comp);
    printf("%s %s " ,first_comp ,second_comp);
    char common = find_common_chars(first_comp, second_comp);
    printf("%c \n", common);
  }
}
