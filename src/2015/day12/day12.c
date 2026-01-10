#include <assert.h>
#include <cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
bool contians_red(cJSON* json_i) {
  assert(cJSON_IsObject(json_i));
  cJSON* child = NULL;
  cJSON_ArrayForEach(child, json_i) {
    if (cJSON_IsString(child) && strcmp(child->valuestring, "red") == 0) {
      return true;
    }
  }
  return false;
}
int total_sum(cJSON* json_i) {
  int total = 0;
  if (cJSON_IsNumber(json_i)) {
    return json_i->valueint;
  } else if (cJSON_IsString(json_i)) {
    return 0;
  } else if (cJSON_IsArray(json_i)) {
    cJSON* child = NULL;
    cJSON_ArrayForEach(child, json_i) { total += total_sum(child); }
  } else if (cJSON_IsObject(json_i)) {
    cJSON* child = NULL;
    if (!contians_red(json_i)) {
      cJSON_ArrayForEach(child, json_i) { total += total_sum(child); }
    }
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
  int total = total_sum(json);
  printf("Total sum: %d\n", total);

  cJSON_Delete(json);
  return 0;
}
