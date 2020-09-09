#!/usr/bin/env python
# coding: utf-8

# In[12]:


#Node 클래스는 자기 자신의 값과 왼쪽, 오른쪽 자식의 값을 저장할 수 있다.
class Node :
    def __init__(self, name) :
        self.name = name
        self.left = None
        self.right = None

def insert_node(cur, target, left, right) :
    if not cur :
        return
    if cur.name == target :
        if left != '.' :
            cur.left = Node(left)
        if right != '.' :
            cur.right = Node(right)
        return
    insert_node(cur.left, target, left, right)
    insert_node(cur.right, target, left, right)
    
def inorder(n) :
    if not n :
        return
    inorder(n.left)
    print(n.name, end='')
    inorder(n.right)
    
def preorder(n) :
    if not n :
        return
    print(n.name, end='')
    preorder(n.left)
    preorder(n.right)
    
def postorder(n) :
    if not n :
        return
    postorder(n.left)
    postorder(n.right)
    print(n.name, end='')

N = int(input())
root = Node('A')
for i in range(N):
    n, l, r = input().split()
    insert_node(root, n, l, r)

preorder(root)
print()
inorder(root)
print()
postorder(root)
print()

