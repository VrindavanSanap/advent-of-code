#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEIGHT 50
#define WIDTH 50 
void print_screen(bool screen[WIDTH][HEIGHT]) {
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++) {
      if (screen[w][h]) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}
void create_rect(bool screen[WIDTH][HEIGHT], int a, int b) {
  for (int h = 0; h < b; h++) {
	for (int w = 0; w < a; w++) {
	  screen[w][h] = true;
	}
  }
}
void rotate_row(bool screen[WIDTH][HEIGHT], int row, int by) {
	bool new_row[WIDTH];
	for(int w = 0; w < WIDTH; w++){
		new_row[(w + by) % WIDTH] = screen[w][row];
	}
	for(int w = 0; w < WIDTH; w++){
		screen[w][row] = new_row[w];
	}
}
void rotate_column(bool screen[WIDTH][HEIGHT], int column, int by) {
	bool new_column[HEIGHT];
	for(int h = 0; h < HEIGHT; h++){
		new_column[(h + by) % HEIGHT] = screen[column][h];
	}
	for(int h = 0; h < HEIGHT; h++){
		screen[column][h] = new_column[h];
	}
}
void exec_instruction(bool screen[WIDTH][HEIGHT], char* instruction_line) {
	if(strstr(instruction_line, "rect") != NULL){
		int a, b;
		sscanf(instruction_line, "rect %dx%d", &a, &b);
		create_rect(screen, a, b);
	}else if(strstr(instruction_line, "rotate row") != NULL){
		int row, by;
		sscanf(instruction_line, "rotate row y=%d by %d", &row, &by);
		rotate_row(screen, row, by);
		
	}else if(strstr(instruction_line, "rotate column") != NULL){
		int column, by;
		sscanf(instruction_line, "rotate column x=%d by %d", &column, &by);
		rotate_column(screen, column, by);
	}
  
}
int count_lit_pixels(bool screen[WIDTH][HEIGHT]) {
  int count = 0;
  for (int h = 0; h < HEIGHT; h++) {
	for (int w = 0; w < WIDTH; w++) {
	  if (screen[w][h]) {
		count++;
	  }
	}
  }
  return count;
}
int main() {
  char* file_name = "day8.txt";
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", file_name);
    return 1;
  }
  bool screen[WIDTH][HEIGHT];
  memset(screen, 0, sizeof(screen));
  char* instruction_line = NULL;
  size_t size = 0;
  while (getline(&instruction_line, &size, file) != -1) {
    //
    printf("%s \n", instruction_line);
    exec_instruction(screen, instruction_line);
    print_screen(screen);
	printf("------------------\n");
  }
  int lit_pixels = count_lit_pixels(screen);
  printf("Lit pixels: %d\n", lit_pixels);
  free(instruction_line);
  fclose(file);
}