import hashlib
import time

# Create MD5 hash
def mine(secret_key):
  i = 0 
  while True:
    i += 1
    md5_hash = hashlib.md5((text + str(i)).encode()).hexdigest()
    if (i % 1000 == 0 ):
      pass
    if md5_hash[:6] == "000000":
      print(f"{i} Mined in {md5_hash}")
      break
# String to hash
text = "ckczppom"     

st = time.time()
mine(text)
et = time.time()
print(f"Time taken = {et - st} sec")

