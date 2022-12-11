import random
import string
import re

res = []
length = 100

for i in range(length):
    i = random.randint(-100000, 100000)
    if str(i) not in res :
        res.append(str(i))

print(" ".join(res))