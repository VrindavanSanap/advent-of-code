#include <ctype.h>
#include <limits.h> // Include limits.h for INT_MAX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define N_NUMS 16 
int main() {
  FILE *file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  int sum = 0;
    int sum_ = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    // Do something with the line
    //    printf("%s", line);
    int len = (int)strlen(line);
    char *numbers;
    char *delimiter = "\t";
    numbers = strtok(line, delimiter);
    int i = 0;
    int nums[16];
    while (numbers != NULL) {
      int n = atoi(numbers);
//      printf("%d \n", n);
      nums[i++] = n;
      numbers = strtok(NULL, delimiter);

    }

  for(int i = 0 ; i< N_NUMS;i++){
    for(int j= 0 ; j< N_NUMS;j++){
      if (i!= j){
        if(nums[i]%nums[j] == 0) {
          int s_ = nums[i] / nums[j];
          printf("%d / %d = %d \n", nums[i], nums[j], 
          s_
          );
          sum_ += s_;
        }

      }
    }
  }

  }

  printf("%d", sum_);
  fclose(file);
  return 0;
}
