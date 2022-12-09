import random
import string
import re

res = []
length = 102

for i in range(length):
    i = random.randint(-1000, 1000)
    if str(i) not in res :
        res.append(str(i))

print(" ".join(res))