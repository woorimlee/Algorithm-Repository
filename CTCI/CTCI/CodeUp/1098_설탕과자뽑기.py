h, w = input().split()
h = int(h)
w = int(w)
board = [[0 for i in range(w)] for j in range(h)]
n = int(input())
for i in range(n) :
    l, d, y, x = input().split()
    l, d, y, x = int(l), int(d), int(y), int(x)
    if(d == 0) :
        for j in range(l) :
            board[y-1][x-1+j] = 1
    else :
        for k in range(l) :
            board[y-1+k][x-1] = 1
for i in range(h) :
    for j in range(w) :
        print(board[i][j], end = ' ' )
    print()
