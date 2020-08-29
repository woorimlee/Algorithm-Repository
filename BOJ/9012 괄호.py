#!/usr/bin/env python
# coding: utf-8

# In[26]:


import sys
input=sys.stdin.readline

def bracket(S) : 
    stack = []
    for ch in Str:
        if ch == '(':
            stack.append(ch)
        elif ch == ')':
            if not stack:
                print('NO')
                return
            stack.pop()
    if stack:
        print('NO')
    print('YES')
    return
    
for i in range(int(input())) :
    bracket(input())

