import sys
input = sys.stdin.readline

def dfs (prev: int, cur: int) :
    global max_n, min_n, visited, temp_str
    if cur == n + 1 :
        min_n = min(min_n, temp_str)
        max_n = max(max_n, temp_str)
        return

    if inequal[cur - 1] == '>' :
        for i in range(prev) :
            if visited[i] == False :
                visited[i] += True
                temp_str += str(i)
                dfs(i, cur + 1)
                visited[i] = False
                temp_str = temp_str[:-1]

    elif inequal[cur - 1] == '<' :
        for i in range(prev + 1, 10) :
            if visited[i] == False :
                visited[i] = True
                temp_str += str(i)
                dfs(i, cur + 1)
                visited[i] = False
                temp_str = temp_str[:-1]

n = int(input())
inequal = input().split()
visited = [False] * 10

max_n, min_n = "-1","9999999999"
temp_str = ""

for i in range(10) :
    visited[i] = True
    temp_str += str(i)
    dfs(i, 1)
    visited[i] = False
    temp_str = temp_str[:-1]

print(f'{max_n}\n{min_n}')
