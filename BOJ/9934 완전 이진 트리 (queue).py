#!/usr/bin/env python
# coding: utf-8

# In[18]:


K = int(input())
Building = input().split()
que = [len(Building)//2]

while K :
    size = len(que)
    for _ in range(size) :
        index = que.pop(0)
        print(Building[index], end =' ')
        if K != 1 :
            que.append(index - (2**(K-2)-1) - 1)
            que.append(index + (2**(K-2)-1) + 1)
    K -= 1
    print()
    
"""
입력 : 
5
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
출력 : 
5 
4 4 
3 3 3 3 
2 2 2 2 2 2 2 2 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
"""

