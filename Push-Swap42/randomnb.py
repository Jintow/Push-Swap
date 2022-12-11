import random
import string
import re

res = []
length = 510

for i in range(length):
    i = random.randint(-10000, 10000)
    if str(i) not in res :
        res.append(str(i))

print(" ".join(res))