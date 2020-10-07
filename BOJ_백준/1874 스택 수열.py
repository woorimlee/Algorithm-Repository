#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from sys import stdin
n = int(stdin.readline())
nums = map(lambda x : int(x.rstrip()), stdin.readlines())

def stack_sequence() :
    seq_num = 1 #스택에 넣을 숫자
    stack = []
    ans = ""
    for i in nums : #4 3 6 8 7 5 2 1
        while seq_num <= i : #수열 만들 숫자까지 seq_num 증가
            stack.append(seq_num)
            ans += '+\n'
            seq_num += 1
        #seq_num 4까지 증가시키고 
        if stack.pop() == i : #만드려는 수열 값과 비교
            ans += '-\n'
        else : 
            return 'NO'
    return ans

print(stack_sequence())

