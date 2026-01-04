#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

void remove_spaces(char *str) {
    int count = 0; 
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count] = str[i];
            count++;
        }
    }
    str[count] = '\0';
}

int main(int argc, char *argv[]) {
    char* file_name = "./day6.txt";
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t line_len = 0;
    char *saved_line = NULL;
    size_t saved_line_len = 0;
    dynamic_array *arr_of_arrs = da_build(sizeof(dynamic_array*));
    dynamic_array *arr_i = NULL;
    char* token;

    while (getline(&line, &line_len, file) != -1) {
        line[strcspn(line, "\n")] = 0;
        int num_i;
        if (line_len > saved_line_len) {
            saved_line_len = line_len;
            saved_line = realloc(saved_line, saved_line_len);
        }
        strcpy(saved_line, line);
        if (strpbrk(line, "0123456789") != NULL) {
            arr_i = da_build(sizeof(int));
            token = strtok(line, " ");
            while (token != NULL) {
                num_i = atoi(token);
                da_insert_last(arr_i, &num_i);
                token = strtok(NULL, " ");
            }
            da_insert_last(arr_of_arrs, &arr_i);
        }
    }

    remove_spaces(saved_line);
    saved_line_len = strlen(saved_line);
    
    int num_arrs = da_get_size(arr_of_arrs);
    int num_ints;
    da_get_at(arr_of_arrs, 0, &arr_i);
    num_ints = da_get_size(arr_i);

    assert (saved_line_len == num_ints);

    unsigned long long total_result = 0; 

    for (int j = 0; j < num_ints; j++) {
        unsigned long long result = 0; 
        char opp = saved_line[j];

        if (opp == '*') {
            result = 1;
        } else {
            result = 0;
        }
        
        for (int i = 0; i < num_arrs; i++) {
            da_get_at(arr_of_arrs, i, &arr_i); 
            int num_i;
            da_get_at(arr_i, j, &num_i);
            
            if (opp == '*') {
                result *= num_i;
            } else {
                result += num_i;
            }
        }
        printf("Result for col %d: %llu\n", j, result);
        total_result += result;
    }

    printf("Total result: %llu\n", total_result);

    /*-- DEEP FREE --*/
    for (int i = 0; i < num_arrs; i++) {
        da_get_at(arr_of_arrs, i, &arr_i); 
        if (arr_i != NULL) {
            da_free(arr_i);
        }
    }

    da_free(arr_of_arrs);
    free(line);
    free(saved_line);
    fclose(file);
    return 0;
}