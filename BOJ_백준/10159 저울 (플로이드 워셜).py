import sys
input = sys.stdin.readline

def floyd_warshall() -> None:
    for k in range(N) : # 비교
        for i in range(N) :
            for j in range(N) :
                if scale[i][k] and scale[k][j] : # 같은 방향 검사
                    scale[i][j] = 1

N = int(input())
M = int(input())

scale = [[0] * N for _ in range(N)]
    
for _ in range(M):
    s1, s2 = map(int,input().split())
    scale[s1 - 1][s2 - 1] = 1

floyd_warshall()

for i in range(N):
    ans = 0
    for j in range(N):
        if i == j:
            continue
        if not scale[i][j] and not scale[j][i]:
            ans += 1
    print(ans)
    
