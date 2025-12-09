#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int wrapping_ribbon_length(const int height, const int width,
                           const int length) {
  int total_perimeter = 2 * height + 2 * width + 2 * length;
  total_perimeter -= 2 * (MAX(MAX(height, width), length));
  return total_perimeter;
}

int bow_ribbon_length(const int height, const int width, const int length) {
  return height * width * length;
}

void parse_line(char buffer[], int* height, int* const width,
                int* const length) {
  int len = strlen(buffer);
  const char* delimiter = "x";
  *height = atoi(strtok(buffer, delimiter));
  *width = atoi(strtok(NULL, delimiter));
  *length = atoi(strtok(NULL, delimiter));
  int i = 0;
}

int main() {
  FILE* file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char line_buffer[32];
  int height, width, length;
  int wrapping_ribbon_length_i = 0;
  int bow_ribbon_length_i = 0;
  int total_ribbon_length_i = 0;
  int total_ribbon_length = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    parse_line(line_buffer, &height, &width, &length);
    wrapping_ribbon_length_i = wrapping_ribbon_length(height, width, length);
    bow_ribbon_length_i = bow_ribbon_length(height, width, length);
    total_ribbon_length_i = wrapping_ribbon_length_i + bow_ribbon_length_i;
    total_ribbon_length += total_ribbon_length_i;
  }
  fclose(file);
  printf("Total ribbon required = %d", total_ribbon_length);
  return 0;
}