#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_LINES 6
void print_arr(int arr[], int size) {
  printf("{");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }

  printf("}");
  printf("\n");
}

bool scrictly_increasing(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] >= arr[i]) {
      return false;
    }
  }
  return true;
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

bool safe_unsafe_strict(int level[], int size) {
  if (!strictly_inc_dec(level, size)) {
    return false;
  }
  if (!check_gap(level, size)) {
    return false;
  }

  return true;
}

void remove_elm_at_index(int arr[], int size, int index) {
  for (int i = index + 1; i < size; i++) {
    arr[i - 1] = arr[i];
  }
}

bool safe_unsafe_damp(int level[], int size) {
  if (safe_unsafe_strict(level, size)) {
    printf("Safe without returning any level");
    return true;
  }

  int *temp_level = (int *)malloc(size * sizeof(int));
  int temp_size = size - 1;
  for (int i = 0; i < size; i++) {
    memcpy(temp_level, level, size * sizeof(int));
    remove_elm_at_index(temp_level, size, i);
    if (safe_unsafe_strict(temp_level, temp_size)) {
      printf("Safe by removing level at index %d, %d", i, level[i]);
      return true;
    }
  }

  printf("Unsafe regardless of which level is removed");
  return false;
}

int main() {
  char *file_name = "day2.txt";
  FILE *fp = fopen(file_name, "r");
  int levels[8];
  char line[511];

  int total_safe = 0;
  int line_i = 0;
  int size;
  bool is_level_safe;
  while (fgets(line, sizeof(line), fp)) {
    line_i++;

    printf("%d) ", line_i);
    memset(levels, 0, sizeof(levels));
    sscanf(line, "%d %d %d %d %d %d %d %d", &levels[0], &levels[1], &levels[2],
           &levels[3], &levels[4], &levels[5], &levels[6], &levels[7]);
    size = sizeof(levels) / sizeof(levels[0]);

    for (int i = 0; i < sizeof(levels) / sizeof(levels[0]); i++) {
      if (levels[i] == 0) {
        size = i;
        break;
      }
    }

    print_arr(levels, size);

    bool are_levels_safe = safe_unsafe_damp(levels, size);

    printf("\n");

    if (are_levels_safe) {
      printf("SAFE\n");
      total_safe += 1;
    } else {
      printf("UNSAFE\n");
    }
  }

  printf("Thanks to the Problem Dampener, %d reports are actually safe! \n",
         total_safe);
  fflush(stdout);
  return 0;
}
