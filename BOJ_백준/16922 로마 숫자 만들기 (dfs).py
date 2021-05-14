import sys
sys.setrecursionlimit(10**6)

N = int(input())
visited = [False] * (50 * 20 + 1)
roma = [1, 5, 10, 50]
ans = 0
def dfs(now: int, cnt: int, num: int) :
    global ans
    if cnt == N :
        if not visited[num] :
            visited[num] = True
            ans += 1
        return

    for i in range(now, 4) :
        dfs(i, cnt + 1, num + roma[i])


dfs(0, 0, 0)
print(ans)
