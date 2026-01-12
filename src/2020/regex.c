#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *test_str = "15-16 v: vvvvvvvvnvvvvcvvvvgv";
  char *pattern = "([0-9]+)-([0-9]+) ([a-zA-Z])";

  regex_t preg;
  assert(regcomp(&preg, pattern, REG_EXTENDED) == 0);
  const size_t n_match = 5;  // 1 for full match + 2 for groups
  regmatch_t p_match[n_match];
  int res = regexec(&preg, test_str, n_match, p_match, 0);
  int match_len;
  char buffer[20];

  match_len = p_match[1].rm_eo - p_match[1].rm_so;
  strncpy(buffer, test_str + p_match[1].rm_so, match_len);
  buffer[match_len] = '\0';
  printf("Min: %s\n", buffer);

  match_len = p_match[2].rm_eo - p_match[2].rm_so;
  strncpy(buffer, test_str + p_match[2].rm_so, match_len);
  buffer[match_len] = '\0';
  printf("Max: %s\n", buffer);

  match_len = p_match[3].rm_eo - p_match[3].rm_so;
  strncpy(buffer, test_str + p_match[3].rm_so, match_len);
  buffer[match_len] = '\0';
  printf("Chr: %s\n", buffer);

  regfree(&preg);
  return 0;
}
