#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "HelloWorld";
    char part1[20];
    char part2[20];
    
    splitString(str, part1, part2);
    
    printf("Part 1: %s\n", part1);
    printf("Part 2: %s\n", part2);
    
    return 0;
}

