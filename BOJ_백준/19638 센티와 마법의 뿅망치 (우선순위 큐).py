import sys
import heapq

input = sys.stdin.readline

N, centi, T = map(int, input().split())

giant = []
for _ in range(N) :
    heapq.heappush(giant, -int(input()))

for i in range(T):
    if -giant[0] < centi:
        print(f'YES\n{i}')
        exit()
    elif -giant[0] > 1 :
        x = -heapq.heappop(giant)
        heapq.heappush(giant, -(x//2 if x>1 else 1))
        
if -giant[0] < centi :
    print(f'YES\n{T}')
else :
    print(f'NO\n{-giant[0]}')
