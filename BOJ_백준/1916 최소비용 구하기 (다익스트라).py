import sys
import heapq

input = sys.stdin.readline

def dijkstra(source: int) :
    dist = [INF] * (N + 1)
    dist[source] = 0

    pq = []
    heapq.heappush(pq, [dist[source], source])

    while pq:
        cost, vertex = heapq.heappop(pq)
        
        for nb, nb_cost in city[vertex]:
            nb_dist = nb_cost + cost
            
            if dist[nb] > nb_dist :
                dist[nb] = nb_dist
                heapq.heappush(pq, [nb_dist, nb])
    return dist


INF = 1e9
N = int(input())
M = int(input())

city = [[] for _ in range(N + 1)]
for i in range(M):
    s, d, w = map(int, input().split())
    city[s].append([d, w])

start, dest = map(int, input().split())

result = dijkstra(start)
print(result[dest])
