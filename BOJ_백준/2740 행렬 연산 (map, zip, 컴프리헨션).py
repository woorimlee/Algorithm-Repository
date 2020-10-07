#!/usr/bin/env python
# coding: utf-8

# In[13]:


N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
M, K = map(int, input().split())
B = list(zip(*[list(map(int, input().split())) for _ in range(M)]))

C = []
for i in A :
    temp = []
    for j in B :
        temp.append(sum([i[k]*j[k] for k in range(M)]))
    C.append()        

for ans in C : 
    print(*ans)

