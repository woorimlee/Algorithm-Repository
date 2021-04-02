import sys
import collections

N, M = map(int, input().split())
name_list = sys.stdin.read().splitlines()

emeqh = collections.defaultdict(bool)
for name in name_list :
    if emeqh[name] : 
        emeqh[name] = False
    else :
        emeqh[name] = True

emeqh = sorted(emeqh.items())
ans = [name[0] for name in emeqh if not name[1]]

print(len(ans))
for a in ans : 
    print(a)
