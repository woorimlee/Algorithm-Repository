card = [i+1 for i in range(int(input()))]

while len(card) > 1 :
    print(card.pop(0), end = ' ')
    temp = card.pop(0)
    card.append(temp)

print(card.pop())

