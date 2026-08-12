#include <CommonCrypto/CommonDigest.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double nanos(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

int main(int argc, char **argv) {
  double st = nanos();
  const char *secret_key = "ckczppom";
  char *full_key = (char *)malloc(strlen(secret_key) + 12);
  unsigned char digest[CC_MD5_DIGEST_LENGTH];
  int i = 0;
  while (true) {
    CC_LONG length = (CC_LONG)sprintf(full_key, "%s%d", secret_key, ++i);
    CC_MD5(full_key, length, digest);
    if (digest[0] == 0 && digest[1] == 0 && digest[2] == 0) {
      printf("%s %d\n", full_key, i);
      break;
    }
  }

  double et = nanos();
  double s = ((et - st) * 1e-9);
  printf("Time taken %f secs", (s));

  free(full_key);
  return 0;
}
