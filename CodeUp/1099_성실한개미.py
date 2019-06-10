def ant() :
    x, y = 1, 1
#(1,1)이 1로 시작하는가?
    while (miro[y][x] != '2') :
        miro[y][x] = '9'

        if(miro[y][x+1] == '1' and miro[y+1][x] == '1' and miro[y+1][x+1] == '1') :
            return
        
        #오른쪽으로 이동하다가 막히면 아래로 이동
        if (miro[y][x+1] != '1') :
            x+=1

        elif (miro[y+1][x] != '1') :
            y+=1

    miro[y][x] = '9'


#miro = [[0]*10 for i in range(10)]
miro = []
for i in range(10) :
    temp = input().split()
    miro.append(temp)

ant()

for i in range(10):
    for j in range(10):
        print(miro[i][j],end= ' ')
    print()
