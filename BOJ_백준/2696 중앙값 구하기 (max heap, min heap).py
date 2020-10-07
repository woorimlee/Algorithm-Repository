#!/usr/bin/env python
# coding: utf-8

# In[12]:


import sys
import heapq
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    M = int(input())
    max_h = []
    min_h = []
    ans = []
    print(M//2 + 1)
    while M :
        seq = list(map(int, input().split()))
        for j, i in enumerate(seq, start = 1) : 
            #두 힙의 길이가 같은 경우
            #max_heap에 넣음
            if len(max_h) <= len(min_h) :
                heapq.heappush(max_h, -i)
            #두 힙의 길이가 다른 경우
            #min_heap에 넣음
            else :
                heapq.heappush(min_h, i)
                
            if j % 2 == 1 :
            #min_heap의 top보다 max_heap의 top이 큰 경우 둘을 swap
                if(max_h and min_h and -max_h[0] > min_h[0]) :
                    n1 = heapq.heappop(max_h)
                    n2 = heapq.heappop(min_h)
                    heapq.heappush(max_h, -n2)
                    heapq.heappush(min_h, -n1)
                ans.append(-max_h[0])
        M -= len(seq)
            
    for i in range(len(ans)) :
        if i != 0 and i%10 == 0 :
            print()
        print(ans[i], end=' ')
    print()

