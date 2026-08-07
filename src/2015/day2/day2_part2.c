#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int ribbon_requried(const int height, const int width, const int length) {
  int ribbon_len = (height + width + length) * 2;
  ribbon_len -= (MAX(MAX(height, width), length)) * 2;
  ribbon_len += (height * length * width);
  return ribbon_len;
}

int main() {
  FILE *file = fopen("2015_day2.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char line_buffer[32];
  int height = 0;
  int width = 0;
  int length = 0;
  int total_ribbon_required = 0;
  int ribbon_required_i = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    sscanf(line_buffer, "%dx%dx%d", &height, &width, &length);
    ribbon_required_i = ribbon_requried(height, width, length);
    total_ribbon_required += ribbon_required_i;
  }
  fclose(file);
  printf("Total ribbon required = %d\n", total_ribbon_required);
  return 0;
}
