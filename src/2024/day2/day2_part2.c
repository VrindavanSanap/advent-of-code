#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_LINES 1000
int damp_increasing(int arr[], int size) {
  // --
  // returns index of element which when removed will make the array
  // strictly increasing
  // --
  // if no such element exits will return 0
  // --
  // if more than one such elements exist will return -1
  //

  int n_fails = 0;
  int wrong_index = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] >= arr[i]) {
      wrong_index = i - 1;
      n_fails++;
    }
  }
  if (n_fails == 0) {
    return 0;
  }
  if (n_fails == 1) {
    return wrong_index;
  }
  return -1;
}

bool scrictly_decreasing(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] <= arr[i]) {
      return false;
    }
  }

  return true;
}
bool strictly_inc_dec(int arr[], int size) {
  if (scrictly_increasing(arr, size) || scrictly_decreasing(arr, size)) {
    return true;
  } else {
    return false;
  }
}
bool check_gap(int arr[], int size) {
  int gap;
  for (int i = 1; i < size; i++) {
    gap = abs(arr[i - 1] - arr[i]);
    if (gap < 1) {
      return false;
    }
    if (gap > 3) {
      return false;
    }
  }
  return true;
}

bool safe_unsafe(int level[], int size) {
  if (!strictly_inc_dec(level, size)) {
    return false;
  }
  if (!check_gap(level, size)) {
    return false;
  }

  return true;
}

int main() {
  char *file_name = "day2_smol.txt";
  FILE *fp = fopen(file_name, "r");
  int level[8];
  char line[511];

  int total_safe = 0;
  int i = 0;
  int size;

  while (fgets(line, sizeof(line), fp)) {
    i++;
    printf("%d ", i);
    memset(level, 0, sizeof(level));
    sscanf(line, "%d %d %d %d %d %d %d %d", &level[0], &level[1], &level[2],
           &level[3], &level[4], &level[5], &level[6], &level[7]);
    for (int i = 0; i < size; i++) {
      printf("%d, ", level[i]);
      if (level[i] == 0) {
        size = i;
        break;
      }
    }
    bool is_level_safe = safe_unsafe(level, size);

    if (is_level_safe) {
      printf("safe \n");
      total_safe += 1;
    } else {
      printf("unsafe \n");
    }
  }

  printf("%d", total_safe);
  fflush(stdout);
  return 0;
}
