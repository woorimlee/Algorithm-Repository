import sys
import collections

input = sys.stdin.readline
N = int(input())
que = collections.deque(map(int, input().split()))
st = collections.deque()

i = 1
while que:
    if que[0] == i:
        que.popleft()
        i += 1
    else:
        st.append(que.popleft())
    while st and st[-1] == i:
        st.pop()
        i += 1
        
print("Nice" if not st else "Sad")
