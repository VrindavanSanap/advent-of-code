#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* read_file_to_buffer(const char* filename, size_t* out_size, int* out_height, int* out_width) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  char* buffer = NULL;
  size_t size = 0;      // Current used size
  size_t capacity = 0;  // Allocated capacity
  int height = 0;
  int width = 0;

  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
      len--;
    }

    if (width == 0) width = (int)len;
    height++;
    size_t new_size = size + len;
    if (new_size + 1 > capacity) {
      size_t new_capacity = capacity == 0 ? 1024 : capacity * 2;
      while (new_size + 1 > new_capacity) {
        new_capacity *= 2;
      }
      char* new_buffer = realloc(buffer, new_capacity);
      if (new_buffer == NULL) {
        perror("Error reallocating memory");
        free(buffer);
        fclose(file);
        return NULL;
      }
      buffer = new_buffer;
      capacity = new_capacity;
    }

    memcpy(buffer + size, line, len);
    size = new_size;
    buffer[size] = '\0';
  }

  if (ferror(file)) {
    perror("Error reading file");
    free(buffer);
    fclose(file);
    return NULL;
  }

  char* final_buffer = realloc(buffer, size + 1);
  if (final_buffer != NULL) {
    buffer = final_buffer;
  }

  fclose(file);

  if (out_size) *out_size = size;
  if (out_height) *out_height = height;
  if (out_width) *out_width = width;

  return buffer;
}

int valid_coords(int row, int col, int height, int width){
  return row >= 0 && row < height && col >= 0 && col < width;
}
int count_neighbours(char* buffer, int row, int col, int height, int width){
  // returns number of neighbours for a given cell
  int num_neighbours = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      int new_row = row + i;
      int new_col = col + j;
      if (valid_coords(new_row, new_col, height, width)) {
        if (buffer[new_row * width + new_col] == '@') {
          num_neighbours++;
        }
      }
    }
  }
  return num_neighbours;
}

bool roll_accessible(char* buffer, int row, int col, int height, int width) {
  // returns true if the roll is accessible
  // ie has less than 4 neighbours
  int num_neighbours = count_neighbours(buffer, row, col, height, width);
  return num_neighbours < 4;
}
void print_buffer(char* buffer, int height, int width) {
  for (int row_i = 0; row_i < height; row_i++) {
    for (int col_j = 0; col_j < width; col_j++) {
      printf("%c", buffer[row_i * width + col_j]);
    }
    printf("\n");
  }
}
void remove_rolls(char* buffer, char* rolls_to_remove, int height, int width) {
  for (int row_i = 0; row_i < height; row_i++) {
    for (int col_j = 0; col_j < width; col_j++) {
      if (rolls_to_remove[row_i * width + col_j]) {
        buffer[row_i * width + col_j] = '.';
      }
    }
  }
}
int main() {
  size_t size;
  int height, width;
  char* rolls_of_paper= read_file_to_buffer("day4.txt", &size, &height, &width);
    char* rolls_to_remove = calloc(height * width, sizeof(bool));
  if (rolls_of_paper == NULL) {
    return EXIT_FAILURE;
  }

  int num_accessible = 1;
  printf("Width: %d, Height: %d\n", width, height);
  printf("File content without newlines (size: %zu)\n", size);
  int total_removed = 0;
  while(num_accessible > 0){
    print_buffer(rolls_of_paper, height, width);

    num_accessible = 0;
    for (int row_i = 0; row_i < height; row_i++) {
      for (int col_j = 0; col_j < width; col_j++) {
      if ((roll_accessible(rolls_of_paper, row_i, col_j, height, width)) && (rolls_of_paper[row_i * width + col_j] == '@')) {
        num_accessible++;
        rolls_to_remove[row_i*width + col_j] = true; 
        total_removed++;
      }else{

      }
    }
  }


  printf("Remove %d rolls: \n", num_accessible);
  remove_rolls(rolls_of_paper, rolls_to_remove, height, width);
}
  printf("Total removed: %d\n", total_removed);
  free(rolls_to_remove);
  free(rolls_of_paper);
  return EXIT_SUCCESS;
}