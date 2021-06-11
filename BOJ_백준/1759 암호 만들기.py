import sys
from itertools import combinations

input = sys.stdin.readline

L, C = map(int,input().split())
candidate = sorted(list(input().split()))

combs = list(combinations(candidate, L))
# print(combs)

for comb in combs :
    cnt_v = 0
    cnt_c = 0
    for c in comb :
        if c in "aeiou":
            cnt_v += 1
        else:
            cnt_c += 1
    
    if cnt_v >=1 and cnt_c>=2:
        print(''.join(comb))
