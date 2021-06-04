import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def divide (x1: int, y1: int, x2: int, y2: int) -> None : 
    global white, blue
    a = [i[x1:x2+1] for i in paper[y1:y2+1]]
    print(a)
    cnt_blue = 0
    for i in a : 
        cnt_blue += sum(i)
    paper_size = (x2 - x1 + 1) * (y2 - y1 + 1)
    
    if cnt_blue == 0 : 
        white += 1
    elif paper_size == cnt_blue : 
        blue += 1
    else :
        divide(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2)
        divide((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2)
        divide(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2)
        divide((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2)

N = int(input().rstrip())
paper = [[*map(int, input().split())] for _ in range(N)]

white = 0
blue = 0

divide(0, 0, N-1, N-1)
print(white); print(blue)
