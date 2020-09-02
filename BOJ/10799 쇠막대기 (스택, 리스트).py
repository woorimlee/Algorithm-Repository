#!/usr/bin/env python
# coding: utf-8

# In[1]:


bar=input()
bar = bar.replace('()','/')
raiser=0
ans=0
for i in bar:
    if(i=='/'):
        ans=ans+raiser
    elif(i=='('):
        raiser=raiser+1
    else:
        raiser=raiser-1
        ans=ans+1
print(ans)

