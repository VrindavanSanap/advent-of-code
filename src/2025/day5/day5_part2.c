#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

/*
    step1: sort the ranges
    step2: merge the ranges
    step3: count the number of elements inside the ranges
*/
struct range {
  uint64_t start;
  uint64_t end;
};

int compare_ranges(const void *a, const void *b) {
  struct range *ra = (struct range *)a;
  struct range *rb = (struct range *)b;
  if (ra->start < rb->start) return -1;
  if (ra->start > rb->start) return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  char *file_name = "./day5.txt";
  FILE *file = fopen(file_name, "r");
  if (!file) {
    perror("Error opening file");
    return 1;
  }
  dynamic_array *ranges_arr = da_build(sizeof(struct range));
  dynamic_array *merged_ranges_arr = da_build(sizeof(struct range));
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;
    if (strcmp(line, "") == 0) {
      break;
    }
    struct range r;
    sscanf(line, "%" SCNu64 "-%" SCNu64, &r.start, &r.end);
    da_insert_last(ranges_arr, &r);
  }

  int num_ranges = da_get_size(ranges_arr);
  printf("Number of ranges: %d\n", num_ranges);
  for (int i = 0; i < num_ranges; i++) {
    struct range r;
    da_get_at(ranges_arr, i, &r);
    printf("Range %d: %" PRIu64 "-%" PRIu64 "\n", i, r.start, r.end);
  }

  // Step 1: sort the ranges
  printf("Sorted ranges:\n");
  da_sort(ranges_arr, compare_ranges);
  for (int i = 0; i < num_ranges; i++) {
    struct range r;
    da_get_at(ranges_arr, i, &r);
    printf("%d: %" PRIu64 "-> %" PRIu64 "\n", i, r.start, r.end);
  }

  // Step 2: merge the ranges
  struct range range_i;
  struct range range_i_next;
  struct range range_last_merged;
  struct range merged_range;
  da_get_at(ranges_arr, 0, &range_i);
  da_insert_first(merged_ranges_arr, &range_i);

  int num_merged_ranges = da_get_size(merged_ranges_arr);
  for (int i = 1; i < num_ranges; i++) {
    da_get_at(ranges_arr, i, &range_i);
    num_merged_ranges = da_get_size(merged_ranges_arr);
    da_get_at(merged_ranges_arr, num_merged_ranges - 1, &range_last_merged);
    if (range_last_merged.end >= range_i.start) {
      if (range_i.end > range_last_merged.end) {
        range_last_merged.end = range_i.end;
        da_set_at(merged_ranges_arr, &range_last_merged, num_merged_ranges - 1);
      }
    } else {
      da_insert_last(merged_ranges_arr, &range_i);
    }
  }
  printf("Merged ranges:\n");
  for (int i = 0; i < num_merged_ranges; i++) {
    struct range r;
    da_get_at(merged_ranges_arr, i, &r);
    printf("%d: %" PRIu64 "->%" PRIu64 "\n", i, r.start, r.end);
  }

  // Step 3: count the number of elements inside the ranges
  uint64_t num_elements = 0;
  num_merged_ranges = da_get_size(merged_ranges_arr);
  for (int i = 0; i < num_merged_ranges; i++) {
    struct range r;
    da_get_at(merged_ranges_arr, i, &r);
    num_elements += r.end - r.start + 1;
  }
  printf("Number of elements: %" PRIu64 "\n", num_elements);
  da_free(ranges_arr);
  da_free(merged_ranges_arr);
  fclose(file);

  return 0;
}
