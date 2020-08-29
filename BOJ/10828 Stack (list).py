#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import sys
input=sys.stdin.readline

S=[]
for i in range(int(input())) :
    c = input().split()
    if c[0]=="push": 
        S.append(c[1])
    elif c[0]=="size": 
        print(len(S)) 
    elif c[0]=="pop": 
        print(S.pop() if S else -1)
    elif c[0]=="empty": 
        print( 0 if S else 1)
    elif c[0]=="top": 
        print(S[-1] if S else -1)

