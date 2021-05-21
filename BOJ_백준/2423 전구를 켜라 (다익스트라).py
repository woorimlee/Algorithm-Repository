import sys
import heapq

input = sys.stdin.readline
INF = 1e9
MAXSIZE = 501

# 노드를 2차원 좌표로 받아야하기 때문에 1차원으로 변환해줌
def hashing(y: int, x: int) -> int :
    return y * MAXSIZE + x
    
def connect_edge(y1, x1, y2, x2, w) :
    
    global board
    
    board[hashing(y1, x1)].append([hashing(y2, x2), w])
    board[hashing(y2, x2)].append([hashing(y1, x1), w])


N, M = map(int, input().split())

board = [[] for _ in range(MAXSIZE ** 2 + MAXSIZE)]

for y in range(1, N + 1) : 
    row = input().split()
    for x, w in enumerate(row[0], start = 1) :
        if w == '/' : 
            connect_edge(y, x, y - 1, x - 1, 1)
            connect_edge(y - 1, x, y, x - 1, 0)
        else : 
            connect_edge(y, x, y - 1, x - 1, 0)
            connect_edge(y - 1, x, y, x - 1, 1)
            
dist = [INF] * (MAXSIZE ** 2 + MAXSIZE)
dist[hashing(0, 0)] = 0
pq = []
heapq.heappush(pq, [dist[hashing(0, 0)], hashing(0, 0)])
while pq : 
    w, v = heapq.heappop(pq)
    # print(w, v)
    if w > dist[v] : 
        continue
    for nb, nb_w in board[v] :
        # print("{0}, {1} : {2}, {3}".format(w, v, nb_w, nb))
        nb_dist = nb_w + w
        if dist[nb] > nb_dist : 
            dist[nb] = nb_dist
            heapq.heappush(pq, [dist[nb], nb])
            
res = dist[hashing(N, M)]
if(res == 1e9) :
    print("NO SOLUTION")
else : 
    print(res)
