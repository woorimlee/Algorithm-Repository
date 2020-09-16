#!/usr/bin/env python
# coding: utf-8

# In[19]:


import sys
input = sys.stdin.readline

def bfs() :
    next_color = RED
    que = []
    for i in range(1, V+1) :
        if visited[i] == 0 :
            que.append(i)
            visited[i] = RED
            while que :
                node = que.pop(0)
                if visited[node] == RED :
                    next_color = BLUE
                elif visited[node] == BLUE :
                    next_color = RED
                for j in graph[node] :
                    if visited[j] == 0 :
                        visited[j] = next_color
                        que.append(j)
                    elif visited[j] == visited[node] :
                        return False
    return True
    
K = int(input())
RED = 1
BLUE = 2

for _ in range(K) :
    V, E = map(int, input().split())
    graph = [[] for _ in range(V+1)]

    for i in range(E) :
        node1, node2 = map(int, input().split())
        graph[node1].append(node2)
        graph[node2].append(node1)
    visited = [0] * (V+1)
    if bfs() :
        print("YES")
    else :
        print("NO")

