N = input()
N_list = input().split()
my_card = {}
for card in N_list :
    if my_card.get(card) : 
        my_card[card] += 1
    else :
        my_card[card] = 1

M = input()
M_list = input().split()

for card in M_list : 
    print(my_card.get(card, 0))

"""
from collections import defaultdict
N = input()
my_card = defaultdict(lambda : 0)
for card in input().split(): 
    my_card[card] += 1
M = input()
print(' '.join(map(str, [my_card[card] for card in input().split()])))
"""
