#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[50]; 

    file = fopen("day1.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    int i = 0;
    int n = 0; 
    int buffer[3] = {0,0,0};
    int buffer_sum = 0;
    int prev = 0;
    int curr  = 0;
    int n_inc = -1;
    while (fgets(line, sizeof(line), file)) {
      n = atoi(line);
      buffer[i++%3] = n; 

      buffer_sum = 0;
      buffer_sum += buffer[0];
      buffer_sum += buffer[1];
      buffer_sum += buffer[2];
      prev = curr;
      curr = buffer_sum;

      if (i>=3){
        printf("%d \n", buffer_sum);
        if (curr > prev){
          n_inc++;
        }
      }
    }
    printf("%d \n" , n_inc);
    fclose(file);
    return 0;
}

