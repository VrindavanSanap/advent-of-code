#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int surface_area(const int height, const int width, const int length) {
  int side_1 = height * width;
  int side_2 = height * length;
  int side_3 = width * length;
  int cuboid_area = 2 * (side_1 + side_2 + side_3);
  int slack = MIN(MIN(side_1, side_2), side_3);
  cuboid_area += slack;
  return cuboid_area;
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
  int total_surface_area = 0;
  int surface_area_i = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    sscanf(line_buffer, "%dx%dx%d", &height, &width, &length);
    surface_area_i = surface_area(height, width, length);
    total_surface_area += surface_area_i;
  }
  fclose(file);
  printf("Total wrapping paper required = %d\n", total_surface_area);
  return 0;
}
