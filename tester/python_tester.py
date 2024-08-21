import os
import re
import sys
import random


length = int(sys.argv[1]) if len(sys.argv) == 2 else 5
int_min = -10000
int_max = 10000

makefile_cmd = 'make'
checker_path = 'checker_Mac'
push_swap_path = 'push_swap'



os.popen(makefile_cmd).read()

if not os.path.exists(push_swap_path) or not os.path.exists(checker_path):
    print(f'don\'t find {push_swap_path} or {checker_path}')
    exit()

args = ' '.join([str(i) for i in random.sample(range(int_min, int_max), k=length)])

check = os.popen(f'./{push_swap_path} {args}| ./{checker_path} {args}').read().removesuffix('\n')
commands = int(re.findall('\d+', os.popen(f'./push_swap {args}| wc -l').read())[0])

print(f'{check} - len {length} in {commands} commands | {args}')