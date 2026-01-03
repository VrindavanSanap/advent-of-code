#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[50]; 

    file = fopen("day2.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    int n = 0;
    char c = 0;
    int depth = 0;
    int horiz = 0;
    int aim = 0;
    while (fgets(line, sizeof(line), file)) {
        int len = (int)strlen(line);
        printf("%s", line);
        n = atoi(&line[len - 2]);
        c = line[0];
        printf("%c %d\n",c ,n );
        if (c == 'f'){
          horiz += n;
          depth += aim * n;
        }else if (c == 'u'){
          aim -= n;
        }else if (c == 'd'){
          aim += n;
        }
        printf("depth: %d horiz: %d res: %d\n",depth ,horiz, depth * horiz);
    }
    fclose(file);
    return 0;
}

