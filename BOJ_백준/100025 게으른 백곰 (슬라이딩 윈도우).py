import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = [0] * 1000001

for _ in range(N):
    g, x = map(int, input().split())
    arr[x] = g

step = K * 2 + 1
temp = sum(arr[:step])
ans = temp

for i in range(step, 1000001) :
    temp += arr[i] - arr[i - step]
    ans = max(ans, temp)

print(ans)
