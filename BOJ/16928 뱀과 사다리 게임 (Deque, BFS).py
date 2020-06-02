from collections import deque
    
def run(sl) :
    visited=[1]
    stack=[1]
    answer=0
    visited = {1:0}
    que = deque([1])
    
    while 1:
        #트리 or 수형도의 한 레벨 별로 BFS 탐색하기 위해 t_que 만듦
        t_que = deque([ ])
        #que에 한 레벨별로 탐색할 노드가 들어있음
        while que:
            now = que.popleft()
            for i in range(1,7):
                new=i+now
                if new > 100 : 
                    continue
                if new not in visited :
                    if new not in sl :
                        visited[new] = visited[now] + 1
                        t_que.append(new)
                    else :
                        visited[new] = visited[now] + 1
                        t_que.append(sl[new])
                        visited[sl[new]] = visited[now] + 1
        #print(t_que, visited)
        que=t_que
        answer+=1
        if 100 in visited:
            break
    return answer
            
N, M = map(int, input().split())
sl = {} #snake, ladder
for _ in range(N+M) :
    a, b = map(int, input().split())
    sl[a] = b

print(run(sl))
