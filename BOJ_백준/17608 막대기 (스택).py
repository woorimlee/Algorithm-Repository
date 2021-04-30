import sys
input = sys.stdin.readline

N = int(input())
st = [int(input()) for _ in range(N)]
max_num = 0
cnt = 0

while st :
    if max_num < st[-1] :
        cnt += 1
        max_num = st[-1]
    st.pop()

print(cnt)
