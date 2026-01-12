#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_line(char* line) {
  int chunk_size = 4;
  char chunk[chunk_size];
  int line_len = strlen(line);
  // The loop condition and increment might need adjustment depending on the
  // exact logic desired, but assuming standard 4-char sliding window or chunks:
  int i;
  for (i = 0; i <= line_len - chunk_size; i += chunk_size) {
    strncpy(chunk, line + i, chunk_size);
    chunk[chunk_size] = '\0';
    printf("%s\n", chunk);
  }
}

int main() {
  FILE* fp;
  char buffer[1024];

  fp = fopen("day6.txt", "r");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }

  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, fp)) != -1) {
    line[strcspn(line, "\n")] = 0;
    printf("%s\n", line);
    process_line(line);
    break;
  }

  if (line) free(line);

  fclose(fp);
  return 0;
}
