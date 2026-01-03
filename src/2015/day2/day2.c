#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int surface_area(const int height, const int width, const int length) { 

  int cuboid_area = 2*height*width + 2*height*length + 2*width*length;
  int slack = MIN(MIN(height*width, height*length), width*length);
  cuboid_area += slack;

  return cuboid_area;
}


void parse_line(char buffer[], int* height, int* const width, int* const length){
  int len = strlen(buffer);
  const char* delimiter = "x";
  *height= atoi(strtok(buffer, delimiter));
  *width = atoi(strtok(NULL, delimiter));
  *length= atoi(strtok(NULL, delimiter));
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
  int total_surface_area = 0;
  int surface_area_i = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
  
    parse_line(line_buffer, &height, &width, &length);
    surface_area_i = surface_area(height, width, length);
    total_surface_area  += surface_area_i;
  }
  fclose(file); 
  printf("Total wrapping paper required = %d", total_surface_area);
  return 0;
}