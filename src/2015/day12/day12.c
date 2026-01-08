#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
char* read_json_file(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // 1. Get the file size
  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);

  // 2. Allocate memory (+1 for null terminator)
  char* buffer = malloc(length + 1);
  if (buffer == NULL) {
    printf("Memory allocation failed\n");
    fclose(file);
    return NULL;
  }

  // 3. Read the file into the buffer
  fread(buffer, 1, length, file);
  buffer[length] = '\0';  // Null-terminate the string

  fclose(file);
  return buffer;
}
int total_sun(cJSON* json_i) {
  int total = 0;
  if (cJSON_IsNumber(json_i)) {
    return json_i->valueint;
  } else if (cJSON_IsString(json_i)) {
    return 0;
  } else if (cJSON_IsArray(json_i)) {
    cJSON* child = NULL;
    cJSON_ArrayForEach(child, json_i) { total += total_sun(child); }
    free(child);
  } else if (cJSON_IsObject(json_i)) {
    cJSON* child = NULL;
    cJSON_ArrayForEach(child, json_i) { total += total_sun(child); }
    free(child);
  } else {
    exit(1);
  }
  return total;
}
int main() {
  const char* filename = "./day12.json";
  char* json_data = read_json_file(filename);
  if (json_data == NULL) {
    return 1;
  }
  cJSON* json = cJSON_Parse(json_data);
  free(json_data);
  if (json == NULL) {
    const char* error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      printf("Error before: %s\n", error_ptr);
    }
    free(json_data);  // Don't forget to free the raw string
    return 1;
  }
  int total = total_sun(json);
  printf("Total sum: %d\n", total);

  cJSON_Delete(json);
  return 0;
}