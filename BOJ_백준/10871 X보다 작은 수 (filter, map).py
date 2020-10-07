N, X = map(int, input().split())\n
A = map(int, input().split())\n
FA = filter( (lambda num : num < X), A )\n
for i in FA :\n",
    print(i, end=' ')\n