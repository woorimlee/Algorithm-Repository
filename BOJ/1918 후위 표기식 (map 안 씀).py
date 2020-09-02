#!/usr/bin/env python
# coding: utf-8

# In[15]:


"""
1. 문자가 나오면 정답용(ans) 스택에 push
2. '('가 나오면 연산 기록 저장용(stack) 스택에 push
3. '*' 혹은 '/'가 나오면 1) stack에 push,  
    2) stack에 이미 '*' 혹은 '/'가 있으면 ans에 push하고 stack에선 pop
    이 과정을 하지 않으면 연산자 우선순위가 뒤엉킴
    ex) A*B/C 같은 것을 후위 연산자로 표현할 때를 생각해보자.
4. '+' 혹은 '-'가 나오면 1) stack에 push,
    2) 우선순위가 낮은 연산이기 때문에 이미 stack에 들어있는 연산자 모두 ans에 push하고 stack에선 pop
5. ')'가 나오면 '('가 나올 때까지 stack에서 pop, ans에 push
"""

s = input()

ans, stack = [], []
for char in s:
    if ord('A') <= ord(char) <= ord('Z'):
        ans.append(char)
    elif char == '(':
        stack.append(char)
    elif char == '*' or char == '/':
        while len(stack)!=0 and (stack[-1] == '*' or stack[-1] == '/'):
            ans.append(stack.pop())
        stack.append(char)
    elif char == '+' or char == '-':
        while len(stack) != 0 and stack[-1] != '(':
            ans.append(stack.pop())
        stack.append(char)
    elif char == ')':
        while len(stack) != 0 and stack[-1] != '(':
            ans.append(stack.pop())
        stack.pop()
        
while len(stack) != 0:
    ans.append(stack.pop())

print(''.join(ans))

