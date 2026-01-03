#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = "The number is: ";
    int num = 42;
    char* result = (char*)malloc(strlen(str) + 12); // Allocate memory for result

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Use sprintf to format the integer as a string
    sprintf(result, "%s%d", str, num);

    printf("Result: %s\n", result);

    // Don't forget to free the allocated memory
    free(result);

    return 0;
}
