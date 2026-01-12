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
  if (file == NULL) {
    printf("Error: could not open file.\n");
    return 1;  // Exit if unable to open the file
  }
  char test_str[] = "hel--loz";
  printf("%s \n", test_str);
  shift_cipher(test_str, strlen(test_str), 1);
  printf("%s \n", test_str);

  return 0;
}
