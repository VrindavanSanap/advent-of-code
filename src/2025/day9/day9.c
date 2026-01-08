#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "dynamic_array.h"
#include <math.h>
struct point {
    int x;
    int y;
};
uint64_t area_rect(struct point p1, struct point p2){
    return (uint64_t)(abs(p1.x - p2.x) + 1) * (abs(p1.y - p2.y) + 1);
}
int main(int argc, char *argv[]) {
    char* file_name = "./day9.txt";
    if (argc == 2) {
        file_name = argv[1];
    }
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t line_len = 0;

    struct point point_i; 
    struct point point_j; 
    dynamic_array* points = da_build(sizeof(struct point));
    while (getline(&line, &line_len, file) != -1) {
        line[strcspn(line, "\n")] = '\0';
        printf("%s\n", line); 
        sscanf(line, "%d,%d", &point_i.x, &point_i.y);
        da_insert_last(points, &point_i);
    }
    int num_points = da_get_size(points);
    uint64_t max_area = 0;
    for (size_t i = 0; i < num_points; i++) {
        for (size_t j = i + 1; j < num_points; j++) {
            da_get_at(points, i, &point_i);
            da_get_at(points, j, &point_j);
            uint64_t area = area_rect(point_i, point_j);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    printf("Max area: %llu\n", max_area);
    da_free(points);
    free(line);
    fclose(file);
    return 0;
}

