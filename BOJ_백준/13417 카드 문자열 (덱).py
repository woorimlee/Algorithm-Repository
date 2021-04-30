import sys
from collections import deque

input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    card = deque(input().split())
    que = deque(card.popleft())
    
    while card :
        c = card.popleft()
        if c <= que[0] :
            que.appendleft(c)
        else :
            que.append(c)
    print(''.join(que))
