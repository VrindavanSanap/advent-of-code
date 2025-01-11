#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void extract_numbers(const char *input) {
    regex_t regex;
    regmatch_t matches[1];
    const char *pattern = "[0-9]+";

    // Compile the regex
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    const char *p = input;
    while (regexec(&regex, p, 1, matches, 0) == 0) {
        // Print the matched number
        int start = matches[0].rm_so; // Start index of match
        int length = matches[0].rm_eo - matches[0].rm_so; // Length of match
        char number[length + 1]; // +1 for null terminator

        strncpy(number, p + start, length);
        number[length] = '\0'; // Null-terminate the string

        printf("Found number: %s\n", number);

        // Move the pointer forward
        p += start + length;
    }

    // Free compiled regular expression
    regfree(&regex);
}

int main() {
    const char *input_str = "abc12def334hjdsk7438dbds3y388";
    extract_numbers(input_str);
    return 0;
}
