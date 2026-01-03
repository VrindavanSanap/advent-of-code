#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include <stdint.h>
#include <inttypes.h>

struct range {
    uint64_t start;
    uint64_t end;
};

int main(int argc, char *argv[]) {
    char* file_name = "./day5.txt";
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    dynamic_array *ranges_arr = da_build(sizeof(struct range));
    dynamic_array *ids_arr = da_build(sizeof(uint64_t));
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "") == 0) {
            break;
        }
        struct range r;
        sscanf(line, "%" SCNu64 "-%" SCNu64, &r.start, &r.end);
        da_insert_last(ranges_arr, &r);
    }
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        uint64_t id_i;
        if (sscanf(line, "%" SCNu64, &id_i) == 1) {
            da_insert_last(ids_arr, &id_i);
        }
    }

    int num_ranges = da_get_size(ranges_arr);
    int num_ids = da_get_size(ids_arr);
    int total_valid_ids = 0;
    for (int i = 0; i < num_ids; i++) {
        uint64_t id_i;
        da_get_at(ids_arr, i, &id_i);
        for (int j = 0; j < num_ranges; j++) {
            struct range r;
            da_get_at(ranges_arr, j, &r);
            if (id_i >= r.start && id_i <= r.end) {
                printf("id: %" PRIu64 " is in range %" PRIu64 "->%" PRIu64 "\n", id_i, r.start, r.end);
                total_valid_ids++;
                break;
            }
        }
        printf("id: %" PRIu64 "\n", id_i);
    }
    printf("Total valid ids: %d\n", total_valid_ids);

    da_free(ranges_arr);
    da_free(ids_arr);
    fclose(file);

    return 0;
}
