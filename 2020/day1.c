#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  FILE* file_pointer;
  char filename[] = "day1.txt";
  char buffer[20];
  int total_fuel = 0;
  file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
    int len = (int)strlen(buffer);
    int mass = atoi(buffer);
    int fuel = mass_to_fuel(mass);
    printf("%d \n", fuel);
    total_fuel += fuel;
    printf("Total fuel %d \n", total_fuel);
  }

  fclose(file_pointer);
  printf("Total fuel = %d", total_fuel);
  return 0;
}
