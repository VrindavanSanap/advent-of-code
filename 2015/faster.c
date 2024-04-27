#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(__APPLE__)
#define COMMON_DIGEST_FOR_OPENSSL
#include <CommonCrypto/CommonDigest.h>
#define SHA1 CC_SHA1
#else
#include <openssl/md5.h>
#endif

#define NUM_THREADS 4

typedef struct {
  char *secret_key;
  int start;
  int end;
  bool found;
} ThreadData;

double nanos(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

char *str2md5(const char *str, int length) {
  int n;
  MD5_CTX c;
  unsigned char digest[16];
  char *out = (char *)malloc(33);

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
    snprintf(&(out[n * 2]), 16 * 2, "%02x", (unsigned int)digest[n]);
  }
  return out;
}

void *mine_thread(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  char *result = (char *)malloc(strlen(data->secret_key) + 12);

  for (int i = data->start; i <= data->end && !data->found; ++i) {
    sprintf(result, "%s%d", data->secret_key, i);
    char *hash = str2md5(result, strlen(result));
    if (strncmp(hash, "000000", 6) == 0) {
      printf("%s %s\n", result, hash);
      printf("Mined!!.\n");
      data->found = true;
    }
    free(hash);
  }
  free(result);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  char *str = "ckczppom";
  double st = nanos();
  pthread_t threads[NUM_THREADS];
  ThreadData thread_data[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; ++i) {
    thread_data[i].secret_key = str;
    thread_data[i].start = i * (10000000 / NUM_THREADS) + 1;
    thread_data[i].end = (i + 1) * (10000000 / NUM_THREADS);
    thread_data[i].found = false;
    pthread_create(&threads[i], NULL, mine_thread, (void *)&thread_data[i]);
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  double et = nanos();
  double s = ((et - st) * 1e-9);
  printf("Time taken %f secs\n", s);

  return 0;
}
