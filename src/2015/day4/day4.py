#!/usr/bin/env python3
import hashlib
import time

# Create MD5 hash
def mine(secret_key):
  i = 0 
  secret_key = secret_key.encode()
  while True:
    md5_hash = hashlib.md5(secret_key + str(i).encode()).digest()

    if (md5_hash[0] == 0 and md5_hash[1] == 0 and md5_hash[2] == 0):
      print(i)
      break
    i += 1
st = time.time()
mine("ckczppom")
et = time.time()
print(f"Time taken = {et - st} sec")

