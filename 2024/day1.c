#include <stdio.h>
#include <stdlib.h>

#define N_LINES 1000
int compare_ints(const void *num1, const void *num2) {
  int x = *(int *)num1;
  int y = *(int *)num2;
  return x - y;
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
  qsort(n1s, N_LINES, sizeof(int), compare_ints);
  qsort(n2s, N_LINES, sizeof(int), compare_ints);
  int total_dist = 0;
  for (int i = 0; i < N_LINES; i++) {
    int dist = abs(n1s[i] - n2s[i]);
    total_dist += dist;
    printf("%d %d %d\n", n1s[i], n2s[i], dist);
  }
  printf("Total dist: %d \n", total_dist);
}
