#include <stdio.h>
#include <string.h>

int main() {
    char digest[] = "aabbccddeeff"; // Example digest array, replace with your actual array
    int firstFiveZero = 1; // Assume the first 5 characters are all '0'

    // Check if the first 5 characters of digest are all '0'
    for (size_t i = 0; i < 5; ++i) {
        if (printf("%.2x", digest[i]) != '0') {
            firstFiveZero = 0; // If any character is not '0', set the flag to 0
            break; // No need to continue the loop if we found a non-zero character
        }
    }

    if (firstFiveZero) {
        printf("The first 5 characters are '00000'\n");
    } else {
        printf("The first 5 characters are not '00000'\n");
    }

    return 0;
}

