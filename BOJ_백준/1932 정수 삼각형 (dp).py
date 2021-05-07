import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]
# cache = [[0] * n for _ in range(n)]
cache = [[0] * 2 for _ in range(n)]

for x in range(n) : 
    cache[(n - 1) % 2][x] = triangle[n - 1][x]
    
for y in reversed(range(n - 1)) : 
    for x in range(y + 1) : 
        cache[y % 2][x] = max(cache[(y + 1) % 2][x], cache[(y + 1) % 2][x + 1]) + triangle[y][x]
        
print(cache[0][0])
