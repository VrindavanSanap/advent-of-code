#include <CommonCrypto/CommonDigest.h>

#include <iostream>
#include <string>
double nanos(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}
using namespace std;
int main() {
  double st = nanos();
  unsigned char digest[CC_MD5_DIGEST_LENGTH];
  int i = 0;
  while (true) {
    string secret_key = "ckczppom";
    secret_key += to_string(i);
    CC_LONG len = (CC_LONG)secret_key.size();
    CC_MD5(secret_key.c_str(), len, digest);
    if (digest[0] == 0 && digest[1] == 0 && digest[2] == 0) {
      cout << i << endl;
      break;
    }
    i++;
  }
  double et = nanos();
  double s = ((et - st) * 1e-9);
  printf("Time taken %f secs", (s));

  return 0;
}
