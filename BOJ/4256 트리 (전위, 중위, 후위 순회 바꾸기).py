#!/usr/bin/env python
# coding: utf-8

# In[1]:


#전위 3 6 5 4 8 7 1 2
#중위 5 6 8 4 3 1 2 7
#후위 5 8 4 6 2 1 7 3

#오른쪽 subtree, 왼족 subtree, 자신
#전위의 [0]번째 = 자신
#중위의 3이 있는 곳 왼쪽 = 왼쪽 sub tree
#중위의 3이 있는 곳 오른쪽 = 오른쪽 sub tree

def postorder(p, i) :
    if not (p or i) :
        return
    node = p[0]
    node_idx = i.index(node)
    postorder(p[1:node_idx+1], i[:node_idx])
    postorder(p[node_idx+1:], i[node_idx+1:])
    print(node, end = ' ')
    

T = int(input())
for _ in range(T):
    n = int(input())
    preorder = input().split()
    inorder =  input().split()
    postorder(preorder, inorder)
    print()

