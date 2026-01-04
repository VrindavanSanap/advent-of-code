#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
    char* file_name = "./day6_smol.txt";
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        
    }

    fclose(file);
    return 0;
}
