import sys
input=sys.stdin.readline

Q = []
for i in range(int(input())) :
    c = input().split()
    if c[0] == "push": 
        Q.append(c[1])
    elif c[0] == "pop" :
        print(Q.pop(0) if Q else -1)
    elif c[0] == "size": 
        print(len(Q))
    elif c[0] == "empty": 
        print(0 if Q else 1)
    elif c[0] == "front": 
        print(Q[0] if Q else -1)
    elif c[0] == "back": 
        print(Q[-1] if Q else -1)
