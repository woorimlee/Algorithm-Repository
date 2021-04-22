import sys

string = sys.stdin.readline().rstrip()
bomb = list(sys.stdin.readline().rstrip())
bomb_len = len(bomb)

ans = []
for c in string : 
    ans += c
    if c == bomb[-1] : 
        if ans[-bomb_len:] == bomb[-bomb_len:] :
            del ans[-bomb_len:]

if ans : 
    print(''.join(ans))
else : 
    print("FRULA")
    
