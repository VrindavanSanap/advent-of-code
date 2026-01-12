#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minmax.h"

int main() {
  FILE *file;
  char calorie_string[100];

  file = fopen("day1.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int most_calories = 0;
  int total_elf_calories = 0;
  int elf_number = 1;
  while (fgets(calorie_string, sizeof(calorie_string), file) != NULL) {
    printf("%s", calorie_string);
    int calorie_int = atoi(calorie_string);
    total_elf_calories += calorie_int;
    if (!calorie_int) {
      most_calories = max(total_elf_calories, most_calories);
      printf("Elf %d, Total calories %d, Most calories %d \n", elf_number,
             total_elf_calories, most_calories);
      printf("------\n");
      total_elf_calories = 0;
      elf_number += 1;
    }
  }
  fclose(file);
  return 0;
}
