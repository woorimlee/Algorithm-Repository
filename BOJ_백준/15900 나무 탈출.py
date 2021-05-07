import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

def dfs(n, depth):
    global cnt
    visited[n] = True

    if n != 1 and len(tree[n]) == 1 :
        if depth % 2 == 1 :
            cnt += 1
            return
    
    for i in tree[n]:
        if not visited[i] :
            dfs(i, depth + 1)

n=int(input())
tree=[[] for _ in range(n + 1)]
visited=[False] * (n + 1)
cnt=0

for _ in range(n - 1):
    a, b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

dfs(1,0)
print('Yes' if cnt % 2 == 1 else 'No')
