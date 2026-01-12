#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itos = "abcdefghijklmnopqrstuvwxyz";
int stoi(char a) { return a - 'a'; }

void shift_cipher(char* str, int len, int shift_n) {
  int temp;
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i])) {
      temp = stoi(str[i]);
      temp += shift_n;
      temp = temp % 26;
      str[i] = itos[temp];
    } else {
    }
  }
}
int main() {
  FILE* file = fopen("day4.txt", "r");

  // Check if the file opened successfully
  if (file == NULL) {
    printf("Error: could not open file.\n");
    return 1;  // Exit if unable to open the file
  }
  char line[255];
  int str_len;
  int i = 0;
  char temp[255];
  char sector_id_str[4];
  int sector_id;
  int n_real = 0;
  int sector_id_sum = 0;
  while (fgets(line, sizeof(line), file)) {
    str_len = strlen(line);
    printf("%d %d", i++, str_len);
    strncpy(sector_id_str, line + str_len - 11, 3);
    sector_id_str[3] = '\0';
    int sector_id = atoi(sector_id_str);
    printf("Sector id: %d\n", sector_id);
    line[str_len - 12] = '\0';
    printf("%s \n", line);
    shift_cipher(line, str_len - 12, sector_id);
    printf("%s \n", line);
  }
  return 0;
}
