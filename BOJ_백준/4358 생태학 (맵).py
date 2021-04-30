import sys
from collections import defaultdict

input = sys.stdin.read

trees = input().split('\n')

dic = defaultdict(int)
cnt = 0

for tree in trees[:-1] :
    dic[tree] += 1
    cnt += 1

sorted_dic = sorted(dic.keys())
for name in sorted_dic :
    print(f'{name} {dic[name]/cnt*100:.4f}')
