#!/usr/bin/env python
# coding: utf-8

# In[4]:


"""그리디가 되는 이유?
동전이 서로 배수 관계로 이뤄져 있어서 500엔부터 1엔까지의 순서로 
그리디하게 탐색해도 됨"""

coins = [500, 100, 50, 10, 5, 1]
pay = 1000 - int(input())
change = 0

for coin in coins :
    if(pay == 0) :
        break
    change += pay//coin
    pay %= coin
    
print(change)

