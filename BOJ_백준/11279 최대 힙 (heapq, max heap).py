#!/usr/bin/env python
# coding: utf-8

# In[35]:


import sys
import heapq
input = sys.stdin.readline

N = int(input())
heap = []

for _ in range(N):
    x = int(input())
    if x != 0:
        heapq.heappush(heap, (-x, x))
    else:
        if not heap :
            print(0)
        else :
            print(heapq.heappop(heap)[1])


# In[ ]:




