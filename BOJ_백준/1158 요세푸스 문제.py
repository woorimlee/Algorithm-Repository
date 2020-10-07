N, K = [int(i) for i in input().split()]

S =[str(i) for i in range(1, N + 1)]
temp=[]
i=0
while S:
    i = (i + K - 1) % len(S)
    temp.append(S.pop(i))

ans = '<' + ', '.join(temp) + '>'
print(ans)
