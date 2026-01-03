#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strip(char* str) {
  char* start = str;
  while (*start && isspace(*start)) {
    start++;
  }
  char* end = str + strlen(str) - 1;
  while (end > start && isspace(*end)) {
    *end-- = '\0';
  }
  size_t len = end - start + 1;
  char* trimmed_str = (char*)malloc((len + 1) * sizeof(char));
  if (trimmed_str == NULL) {
    return NULL;  // Memory allocation failed
  }
  memcpy(trimmed_str, start, len);
  trimmed_str[len] = '\0';  // Null-terminate the string
  return trimmed_str;
}
char* read_file(const char* filename) {
  FILE* file = fopen(filename, "rb");  // Open the file in binary mode

  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Determine the size of the file
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char* buffer = (char*)malloc(file_size + 1);
  if (buffer == NULL) {
    fclose(file);
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  size_t bytes_read = fread(buffer, 1, file_size, file);
  if (bytes_read != file_size) {
    fclose(file);
    free(buffer);
    fprintf(stderr, "Error reading file\n");
    return NULL;
  }
  buffer[file_size] = '\0';
  fclose(file);
  return buffer;
}

int main() {
  const char* filename = "day1.txt";  // Replace with your file name
  char* file_contents = read_file(filename);
  char* file_contents_striped = strip(file_contents);
  free(file_contents);
  file_contents = file_contents_striped;
  int len = (int)strlen(file_contents);
  int half_len = len / 2;
  int sum = 0;
  if (file_contents != NULL) {
    printf("File contents: %s %d\n", file_contents, len);
    strip(file_contents);
    for (int i = 0; i < half_len; i++) {
      char a = file_contents[i];
      char b = file_contents[(i + half_len) % len];

      if (a == b) {
        char str_a[2] = {a, '\0'};
        int val_a = atoi(str_a);
        sum += val_a * 2;
      }
    }
    free(file_contents);
    printf("%d \n", sum);
  }
  return 0;
}
