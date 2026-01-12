#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

struct person {
  char person_i[20];
  char person_j[20];
  int happiness_gain;
};
int get_happiness(dynamic_array* persons, char* person_i, char* person_j) {
  // Placeholder function to get happiness value between two persons
  int num_persons = da_get_size(persons);
  for (size_t idx = 0; idx < num_persons; idx++) {
    struct person p;
    da_get_at(persons, idx, &p);
    if (strcmp(p.person_i, person_i) == 0 &&
        strcmp(p.person_j, person_j) == 0) {
      return p.happiness_gain;
    }
  }
  return 0;
}

int calculate_total_happiness(dynamic_array* persons, char** arrangement,
                              int arrangement_size) {
  int total_happiness = 0;
  for (int i = 0; i < arrangement_size; i++) {
    char* person_i = arrangement[i];
    char* person_j = arrangement[(i + 1) % arrangement_size];
    total_happiness += get_happiness(persons, person_i, person_j);
    total_happiness += get_happiness(persons, person_j, person_i);
  }
  return total_happiness;
}

int main() {
  dynamic_array* persons = da_build(sizeof(struct person));
  char* person_names[] = {"Alice", "Bob", "Carol", "David"};

  char* filename = "day13.txt";
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return 1;
  }
  char* line = NULL;
  size_t len = 0;

  ssize_t read;
  char person_i[20];
  char person_j[20];
  char gain_or_lose[10];
  int units;
  struct person p_i;
  while ((read = getline(&line, &len, fp)) != -1) {
    // printf("Read line: %s", line);
    sscanf(line, "%s would %s %d happiness units by sitting next to %s.",
           person_i, gain_or_lose, &units, person_j);
    if (strcmp(gain_or_lose, "lose") == 0) {
      units = -units;
    }
    p_i.happiness_gain = units;
    char* dot = strchr(person_j, '.');
    if (dot) {
      *dot = '\0';
    }
    strcpy(p_i.person_i, person_i);
    strcpy(p_i.person_j, person_j);
    da_insert_last(persons, &p_i);
  }
  fclose(fp);
  free(line);

  int num_persons = da_get_size(persons);
  da_get_at(persons, 0, &p_i);
  printf("First entry: %s %s %d\n", p_i.person_i, p_i.person_j,
         p_i.happiness_gain);
  int total_happiness = calculate_total_happiness(persons, person_names, 4);
  printf("Total happiness: %d\n", total_happiness);
  da_free(persons);
  return 0;
}