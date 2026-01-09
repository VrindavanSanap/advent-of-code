#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
    char* file_name = "./day9.txt";
    if (argc > 1) {
        file_name = argv[1];
    }

    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t line_len = 0;

    while (getline(&line, &line_len, file) != -1) {
        line[strcspn(line, "\n")] = '\0';
        
        // TODO: Implement logic here
    }

    free(line);
    fclose(file);
    return 0;
}
