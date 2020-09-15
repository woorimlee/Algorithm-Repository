#!/usr/bin/env python
# coding: utf-8

# In[9]:


import sys
input = sys.stdin.readline

def find_path(i) :
    path = [0]*N
    que = [i]
    
    while que :
        node = que.pop(0)
        for index, vertex in enumerate(graph[node]) :
            if vertex == '1' and path[index] == 0 :
                path[index] = 1
                que.append(index)
    return path

N = int(input())
graph = [ input().split() for _ in range(N)]
ans = []
for i in range(N) :
    ans.append(find_path(i))
for i in ans :
    print(*i)


# In[ ]:




