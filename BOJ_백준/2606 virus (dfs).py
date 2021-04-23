import sys

def dfs(i):
    global ans
    visit[i] = True
    for i in graph[i]:
        if visit[i] == False :
            dfs(i)
            ans += 1

com = int(sys.stdin.readline())
net = int(sys.stdin.readline())

graph = [[] for _ in range(com + 1)]
visit = [False] * (com + 1)
ans = 0

for _ in range(net):
    n1, n2 = map(int, sys.stdin.readline().split())
    graph[n1].append(n2)
    graph[n2].append(n1)


dfs(1)
print(ans)
