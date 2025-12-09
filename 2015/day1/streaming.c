#include <stdio.h>
#include <stdlib.h>

// We define a reasonable max line length.
// For truly arbitrary line lengths, a dynamic approach is needed.
#define MAX_LINE_LENGTH 1024

int main() {
  FILE *file = fopen("day1.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[MAX_LINE_LENGTH];
  unsigned long line_number = 0;

  // The core streaming loop.
  // fgets reads one line (or up to MAX_LINE_LENGTH-1 chars)
  // and returns NULL at the end of the file.
  while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    line_number++;
    // --- Process the line here ---
    // For this example, we'll just print lines containing "ERROR"
    printf("%lu : %s", line_number, line_buffer);
    // -----------------------------
  }

  // Check if the loop ended because of a read error
  if (ferror(file)) {
    perror("Error reading from file");
  }

  fclose(file);
  printf("\nFinished processing %lu lines.\n", line_number);
  return 0;
}