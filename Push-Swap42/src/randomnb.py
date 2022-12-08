import random
import string
import re

res = []
length = 100

for i in range(length):
    i = random.randint(-1000, 1000)
    res.append(str(i))

print(" ".join(res))