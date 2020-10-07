#!/usr/bin/env python
# coding: utf-8

# In[1]:


import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(V):
    visit[V] = 1
    result1.append(V)
    for i in graph[V]:
        if visit[i] == 0:
            visit[i] = 1
            dfs(i)

def bfs(V):
    visit[V] = 0
    result2.append(V)
    que = [V]
    while que:
        node = que.pop(0)
        for i in graph[node]:
            if visit[i] == 1:
                result2.append(i)
                que.append(i)
                visit[i] = 0
        
N, M, V = map(int, input().split())

graph = [[] for _ in range(N + 1)]

for _ in range(M):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)
for i in range(len(graph)):
    graph[i].sort()
    
visit = [0] * (N + 1)
result1 = []
result2 = []
dfs(V)
bfs(V)
print(*result1)
print(*result2)


# In[ ]:




