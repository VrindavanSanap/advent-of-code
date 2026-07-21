#include <stdio.h>

#include "dynamic_array.h"

int main() {
  char *file_name = "2019_day2.txt";
  FILE *file = fopen(file_name, "r");
  char *line = NULL;

  int value;
  dynamic_array *da = da_build(sizeof(int));

  while (fscanf(file, " %d ,", &value) == 1) {
    da_insert_last(da, &value);
  }
  int a = 12;
  int b = 2;
  da_set_at(da, &a, 1);
  da_set_at(da, &b, 2);

  int size = da_get_size(da);
  for (int i = 0; i < size; i += 4) {
    int opcode;
    da_get_at(da, i, &opcode);

    if (opcode == 99) {
      break;
    }
    int addr_1;
    da_get_at(da, i + 1, &addr_1);
    int addr_2;
    da_get_at(da, i + 2, &addr_2);
    int dest_addr;
    da_get_at(da, i + 3, &dest_addr);
    int x;
    da_get_at(da, addr_1, &x);
    int y;
    da_get_at(da, addr_2, &y);
    int res;
    if (opcode == 1) {
      res = x + y;
    }
    if (opcode == 2) {
      res = x * y;
    }
    da_set_at(da, &res, dest_addr);
  }
  int output;
  da_get_at(da, 0, &output);
  printf("%d", output);
  return 0;
}
