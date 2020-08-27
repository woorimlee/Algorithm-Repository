#!/usr/bin/env python
# coding: utf-8

# In[9]:


for i in range(int(input())) :
    print('Distances: ', end='')
    X,Y = input().split()
    Z = zip(X, Y)
    for S in Z :
        x = ord(S[0]) - ord('A') + 1
        y = ord(S[1]) - ord('A') + 1
        if x <= y :
            print(y-x, end= ' ')
        else :
            print((y+26)-x, end=' ')
    print()

