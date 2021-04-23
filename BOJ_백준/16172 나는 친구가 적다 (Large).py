import sys

s = sys.stdin.readline().rstrip()
k = sys.stdin.readline().rstrip()

for x in '0123456789' :
    s = s.replace(x, '')

ans = s.find(k)
print(1 if ans > -1 else 0)
