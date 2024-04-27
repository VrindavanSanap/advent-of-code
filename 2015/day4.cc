#include <stdio.h>
#include <string.h>

#include <CommonCrypto/CommonDigest.h>

int main()
{
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    const char string[] = "pqrstuv1048970";

    CC_MD5_CTX context;
    CC_MD5_Init(&context);
    CC_MD5_Update(&context, string, (CC_LONG)strlen(string));
    CC_MD5_Final(digest, &context);

    for (size_t i=0; i<1; ++i)
        printf("%.2x", digest[i]);
    fputc('\n', stdout);
    return 0;
}

