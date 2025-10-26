#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    return 1;
  }
  char *pattern = "([0-9]+)-([0-9]+) ([a-zA-Z])";

  int count;
  char line[31];
  int n_valid;
  char c;
  regex_t preg;
  assert(regcomp(&preg, pattern, REG_EXTENDED) == 0);
  const size_t n_match = 5; // 1 for full match + 2 for groups
  regmatch_t p_match[n_match];
  int pos1;
  int pos2;

  while (fgets(line, sizeof(line), file)) {

    count = 0;
    int res = regexec(&preg, line, n_match, p_match, 0);
    int match_len;
    char buffer[20];

    int len = 0;
    match_len = p_match[1].rm_eo - p_match[1].rm_so;
    strncpy(buffer, line + p_match[1].rm_so, match_len);
    buffer[match_len] = '\0';

    pos1 = atoi(buffer);
    printf("pos1: %d\n", pos1);
    len += match_len + 1;
    match_len = p_match[2].rm_eo - p_match[2].rm_so;
    strncpy(buffer, line + p_match[2].rm_so, match_len);
    pos2 = atoi(buffer);
    printf("pos2: %d\n", pos2);

    len += match_len + 1;
    match_len = p_match[3].rm_eo - p_match[3].rm_so;
    strncpy(buffer, line + p_match[3].rm_so, match_len);
    buffer[match_len] = '\0';
    c = buffer[0];
    printf("char: %c\n", c);
    len += match_len + 1;

    printf("pos1: %c \n", line[len+pos1]);
    printf("pos2: %c \n", line[len+pos2]);
    int is_valid = false;

    if ((line[len+pos1] == c)^(line[len+pos2]==c)) {
      n_valid++;
      printf("Valid %d \n", n_valid);
    } else {

      printf("Invalid %d \n", n_valid);
    }

    printf("---\n");
  }

  regfree(&preg);
  return 0;
}
