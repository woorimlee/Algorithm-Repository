#!/usr/bin/env python
# coding: utf-8

# In[33]:


"""
3
1 2 1 3 2 4 1 1 1 1 1 1 1 1 (0 ~ 13까지 인덱스)
-> 포화 이진 트리 
1(0) 2(1) 
1(2) 3(3) 2(4) 4(5) 
1(6) 1(7) 1(8) 1(9) 1(10) 1(11) 1(12) 1(13)
->
1 2
3 3 4 4
1 1 1 1 1 1 1 1
->
3 2
3 3 4 4
1 1 1 1 1 1 1 1
-> 5 + 14 + 8 -> 27
"""

k = int(input())
temp = list(map(int, input().split()))
tree = [0]
tree.extend(temp)
ans = sum(tree) 
for i in range(k, 0, -1) : #3 -> 2 -> 1
    for j in range((2**i) - 1, (2**(i+1)) - 1, 2) :
        #참일 때 값 if 조건 else 거짓일 때 값
        #j가 6일 때, 7과 연산해서 2로, 
        #j가 8일 때, 9와 연산해서 3으로 가중치 값 업데이트 
        #print(i, j)
        tree[j//2] += tree[j] if tree[j] >= tree[j+1] else tree[j+1]
        ans += abs(tree[j] - tree[j+1])#변화된 가중치만큼 정답 증가
        #print(tree)
print(ans)

