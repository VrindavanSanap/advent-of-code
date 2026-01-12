#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

int main() {
  regex_t preg;
  assert(regcomp(&preg, "ab*", 0) == 0);

  int result = regexec(&preg, "abb", 0, NULL, 0);

  if (result == 0) {
    printf("match\n");
  } else if (result == REG_NOMATCH) {
    printf("no match\n");
  }
  regfree(&preg);
  return 0;
}
