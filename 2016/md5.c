
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <openssl/md5.h>

void compute_md5(const char *data, unsigned char *md5_result) {
    // Compute the MD5 hash
    MD5((unsigned char *)data, strlen(data), md5_result);
}

char* byte_to_str (unsigned char *md5_result) {
    // Print the MD5 hash in hexadecimal format
    static char hex_res[MD5_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&hex_res[i * 2], "%02x", md5_result[i]);
    }
    return hex_res;
}

int main() {
    const char *text = "abc5357525";
    const char *five_zeros = "00000";
    unsigned char md5_result[MD5_DIGEST_LENGTH];

    compute_md5(text, md5_result);

    printf("MD5 hash of '%s': ", text);
    char* md5_res_str = byte_to_str(md5_result);
    printf("%s", md5_res_str);
    if(!strncmp(md5_res_str, five_zeros, 5)){
      printf("Success");
    }else{

      printf("Fail");
    };

    return 0;
}

