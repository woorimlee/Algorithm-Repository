#!/usr/bin/env python
# coding: utf-8

# In[4]:


import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

N, M = map(int, input().split())

graph = [ [] for _ in range(N+1) ]

for i in range(M) :
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
    
    
def linked_graph(node) :
    visited[node] = True
    for i in graph[node] :
        if visited[i] == False :
            linked_graph(i)
    
    
visited = [False for _ in range(N+1)]

count = 0
for i in range (1, N+1) :
    if visited[i] == False :
        linked_graph(i)
        count += 1
        
print(count)


# In[ ]:




