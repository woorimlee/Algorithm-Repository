# [ [넣을 리스트] 넣을 리스트가 들어갈 리스트의 위치 ]
board = [[int(x) for x in input().split()] for y in range(19)]
num = int(input())
coordinate = [[int(x) for x in input().split()] for y in range(num)]
for i in range(num) :
    x = coordinate[i][0]
    y = coordinate[i][1]
    for j in range(19) :
        if board[j][x-1] == 1 :
            board[j][x-1] = 0
        else :
            board[j][x-1] = 1
    for j in range(19) :
        if board[y-1][j] == 1 :
            board[y-1][j] = 0
        else :
            board[y-1][j] = 1
for i in range(19) :
    for j in board[i] :
        print(j, end=' ')
    print()
