import sys

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

# jump(y, x) = y, x 좌표에서 출발해 도착지에 도착할 수 있는 경우의 수.
# 도착지에 도착한 경우 한 가지 방법이 나타난 것임으로 1을 리턴하고
# 1을 리턴 받은 위치(jump 함수를 실행한 곳)에서 자신의 위치에서 도달할 수 있는 경우에 1을 더해준다.
def jump(y, x) : 
    global dp
    
    if y >= N or x >= N :
        return 0
    if y == N-1 and x == N-1 : 
        return 1
    
    if dp[y][x] != -1 :
        return dp[y][x]
    
    dp[y][x] = 0
    
    dp[y][x] += jump(y + board[y][x], x)
    dp[y][x] += jump(y, x + board[y][x])
    return dp[y][x];


N = int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]
dp = [[-1] * (N + 1) for _ in range(N + 1)]

for i in range(N) : 
    l = list(map(int, input().split()))
    for j in range(N) : 
        board[i][j] = l[j]

print(jump(0, 0))
