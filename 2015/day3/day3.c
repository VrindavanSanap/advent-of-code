#include <stdio.h>
#include <string.h>
int process_line(char buffer[]) {
  int len = strlen(buffer);
  for (int i = 0; i < len; i++) {
    printf("%c", buffer[i]);
  }
  printf("\n");
  return 0;
}
int main() {
  FILE* file = fopen("day3.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char line_buffer[256];
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    printf("%s %d \n", line_buffer, (int)strlen(line_buffer));
  }
  fclose(file);
  return 0;
}
