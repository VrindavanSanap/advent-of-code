#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_md5(const char *data, unsigned char *md5_result) {
  // Compute the MD5 hash
  MD5((unsigned char *)data, strlen(data), md5_result);
}

char *byte_to_str(unsigned char *md5_result) {
  // Print the MD5 hash in hexadecimal format
  static char hex_res[MD5_DIGEST_LENGTH * 2 + 1];
  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    sprintf(&hex_res[i * 2], "%02x", md5_result[i]);
  }
  return hex_res;
}
int main() {
  char *test_door_id = "ojvtpuvg";
  char full_test_door_id[63];
  char int_str[31];
  const char *five_zeros = "00000";
  unsigned char md5_result[MD5_DIGEST_LENGTH];
  int password_char_count = 0;
  char password[9] = "--------";
  password[8] = '\0';
  for (int i = 3 * 10e5; i < 4 * 10e7; i++) {
    if(password_char_count == 8){
      break;

    }
    sprintf(int_str, "%d", i);
    strcat(full_test_door_id, test_door_id);
    strcat(full_test_door_id, int_str);
    compute_md5(full_test_door_id, md5_result);
    char *md5_res_str = byte_to_str(md5_result);

    if(!strncmp(md5_res_str, five_zeros, 5)){
     char pos = md5_res_str[5] - '0';
     char pass_chr = md5_res_str[6];
     if(pos < 8 & pos  >= 0){
        if (password[pos]== '-' ){
          printf("%s \n", md5_res_str);
          printf("%s, Pos: %d Chr: %c \n", full_test_door_id, pos, pass_chr);
          password[pos] = pass_chr;
          printf("Password: %s\n", password);
          password_char_count++;
        }
     }
    }
    if (i % 100000 == 0) {
//      printf("%s \n", full_test_door_id);
    }
    full_test_door_id[0] = '\0';
  }
  printf("%s \n", password);
  return 0;
}
