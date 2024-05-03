#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* elves_look_elves_say(const char* input_str) {

  int len = (int)strlen(input_str);


  char* output_str = (char*)malloc(sizeof(char) * (len * 2 + 1));
  char curr = input_str[0];
  int streak = 0;
  char streak_str;
  bool change = false;
  char output_i[5];
  for (int i = 0; i < len; i++) {
    if (curr == input_str[i]) {
      streak += 1;
    } else {
      if (i != 0) {
        sprintf(output_i, "%d%c",  streak, input_str[i - 1]);

        strcat(output_str, output_i);
     }
      curr = input_str[i];
      streak = 1;
    }
  }

  sprintf(output_i, "%d%c",  streak, input_str[len - 1]);
  strcat(output_str, output_i);
        
  return output_str;
}

int main() {
  char* result = "1113222113";
  for (int i = 1; i < 41; i++){

    result =  elves_look_elves_say(result);

  printf("%d %s\n",i, result);
  }
  return 0;
}
