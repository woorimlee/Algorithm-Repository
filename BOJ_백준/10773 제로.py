#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#10773 제로
import sys
input=sys.stdin.readline

K = int(input())
num = []
for i in range(K):
    N = int(input())
    if N == 0:
        num.pop(-1)
    else:
        num.append(N)

print(sum(num))

