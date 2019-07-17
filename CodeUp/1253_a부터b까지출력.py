a, b = input().split()
a = int(a)
b = int(b)
if a > b :
    temp = a
    a = b
    b = temp
c = []
while a != b :
    c.append(a)
    a += 1
c.append(b)
for i in c :
    print(i, end=' ')
    
