#include <stdio.h>
#include <stdlib.h>

#define N_LINES 1000
int compare_ints(const void *num1, const void *num2) {
  int x = *(int *)num1;
  int y = *(int *)num2;
  return x - y;
}

void print_arr(int *arr, int size) {
  printf("{");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("} \n");
}

int remove_duplicates_from_sorted_array(int *arr, int size) {
  int reader = 1;
  int writer = 1;
  int prev = arr[0];
  int unique_count = 0;
  while (reader != size) {
    if (prev != arr[reader]) {
      arr[writer++] = arr[reader];
    }
    prev = arr[reader++];
  }
  return writer;
}

int find_first(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;
  int mid;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      // target found at index mid
      while (arr[--mid] == target) {
      }
      return mid + 1;
    } else if (arr[mid] < target) {
      // discard the left half, search in the right half
      low = mid + 1;
    } else {
      // discard the right half, search in the left half
      high = mid - 1;
    }
  }
  return -1;
}

int find_last(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;
  int mid;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      // target found at index mid
      while (arr[++mid] == target) {
      }
      return mid - 1;
    } else if (arr[mid] < target) {
      // discard the left half, search in the right half
      low = mid + 1;
    } else {
      // discard the right half, search in the left half
      high = mid - 1;
    }
  }
  return -1;
}

int get_freq(int arr[], int size, int target) {
  int first = find_first(arr, size, target);
  int last = find_last(arr, size, target);
  printf("%d %d \n", first, last);
  if (first == -1) {
    return 0;
  }
  return last - first + 1;
}

int main() {
  char *file_name = "day1.txt";
  char line[256];

  int n1s[N_LINES];
  int n2s[N_LINES];

  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Failed to read the file");
    return 1;
  }
  int n1;
  int n2;
  n1 = 0;
  n2 = 0;
  int i = 0;
  while (fgets(line, sizeof(line), fp)) {
    sscanf(line, "%d %d", &n1, &n2);
    n1s[i] = n1;
    n2s[i++] = n2;
  }
  int total_similarity_score = 0;
  int similarity_score;
  int dist;
  int freq;
  qsort(n2s, N_LINES, sizeof(int), compare_ints);
  print_arr(n2s, sizeof(n2s) / sizeof(n2s[0]));
  for (int i = 0; i < N_LINES; i++) {
    freq = get_freq(n2s, sizeof(n1s) / sizeof(int), n1s[i]);
    printf("N: %d ", n1s[i]);
    printf("Freq(N): %d ", freq);
    similarity_score = freq * n1s[i];
    total_similarity_score += similarity_score;
    printf("Similarity score --> %d\n", similarity_score);
  }
  printf("Total similarity score: %d \n", total_similarity_score);
}
