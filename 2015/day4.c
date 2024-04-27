#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif
double nanos(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

char* str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }
    MD5_Final(digest, &c);
    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }
    return out;
}
int mine(char *secret_key) {
  int i = 1;
  char *result = (char *)malloc(strlen(secret_key) + 12);
  while (true) {
    sprintf(result, "%s%d", secret_key, i);
    char *hash = str2md5(result, strlen(result));
    if (strncmp(hash, "000000", 6) == 0) {
      printf("%s %s \n", result, hash);
      printf("Mined!!.\n");
      break;
    } else {
    }
    free(hash);
    i++;
  }
  return 0;
}
int main(int argc, char **argv) {
  char *str = "ckczppom";
  double st = nanos();

  mine(str);
  double et = nanos();
  double s = ((et - st) * 1e-9);
  printf("Time taken %f secs", ( s) );

  return 0;
}

