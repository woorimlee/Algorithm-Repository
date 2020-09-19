#!/usr/bin/env python
# coding: utf-8

# In[9]:


import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dir_x = [0, 1, 0, -1]
dir_y = [-1, 0, 1, 0]
N = int(input())
graph = [ list(map(int, input().split())) for _ in range(N) ]
visited = [ [False]*N for _ in range(N) ]

def find_island(y, x, num) :
    visited[y][x] = True
    graph[y][x] = num
    for i in range(4) :
        ny = y + dir_y[i]
        nx = x + dir_x[i]
        if(0 <= ny < N and 0 <= nx < N and graph[ny][nx] and not visited[ny][nx]) :
            find_island(ny, nx, num)

island_num = 1
for i in range(N) :
    for j in range(N) : 
        if graph[i][j] and not visited[i][j]  :
            find_island(i, j, island_num)
            island_num += 1

def bridges_continent(num) :
    que = []
    for i in range(N) :
        for j in range(N) :
            if graph[i][j] == num :
                que.append((i, j))
                visited[i][j] == True
    
    length = 0
    while(que) :
        que_size = len(que)
        for _ in range(que_size) :
            node = que.pop(0)
            for i in range(4) :
                ny = node[0] + dir_y[i]
                nx = node[1] + dir_x[i]
                if 0 <= ny < N and 0 <= nx < N :
                    if graph[ny][nx] != num and graph[ny][nx] != 0 :
                        return length
                    elif graph[ny][nx] == 0 and visited[ny][nx] == False :
                        visited[ny][nx] = True
                        que.append((ny, nx))
        length += 1
                    
    
            
ans = 987654321
for i in range(1, island_num) :
    visited = [ [False]*N for _ in range(N) ]
    bridge_len = bridges_continent(i)
    ans = ans if ans < bridge_len else bridge_len
    
print(ans)


# #include <iostream>
# #include <queue>
# #include <algorithm>
# #include <cstring> //memset
# 
# using namespace std;
# 
# const int INF = 987654321;
# const int MAX = 100;
# 
# typedef struct
# {
#     int y, x;
# }Dir;
# 
# Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
# 
# int N;
# int graph[MAX][MAX];
# bool visited[MAX][MAX];
# 
# void DFS(int y, int x, int cnt)
# {
#     visited[y][x] = true;
#     graph[y][x] = cnt; //몇번 섬인지 표시ㅑㅑ
# 
#     for (int i = 0; i < 4; i++)
#     {
#         int nextY = y + moveDir[i].y;
#         int nextX = x + moveDir[i].x;
#         if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
#             if (graph[nextY][nextX] && !visited[nextY][nextX])
#                 DFS(nextY, nextX, cnt);
#     }
# }
# 
# 
# int BFS(int cnt)
# 
# {
#     queue<pair<int, int>> q;
# 
#     //우선 해당 섬의 좌표를 다 큐에 넣는다
# 
#     for (int i = 0; i < N; i++)
#         for (int j = 0; j < N; j++)
#             if (graph[i][j] == cnt)
#             {
#                 visited[i][j] = true;
#                 q.push(make_pair(i, j));
#             }
# 
#     int result = 0;
#     while (!q.empty())
#     {
#         int curSize = q.size();
# 
#         //현재 큐에 있는 칸으로부터 한칸씩 전진해본다
#         for (int i = 0; i < curSize; i++)
#         {
#             int y = q.front().first;
#             int x = q.front().second;
#             q.pop();
#             for (int i = 0; i < 4; i++){
#                 int nextY = y + moveDir[i].y;
# 
#                 int nextX = x + moveDir[i].x;
#                 //범위 내에 있고
# 
#                 if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
#                 {
#                     //다른 섬에 도착할 경우 반환
#                     if (graph[nextY][nextX] && graph[nextY][nextX] != cnt)
#                         return result;
# 
#                     //아직 방문하지 않은 바다칸이면 방문했다고 표시 후 큐에 넣는다
#                     else if (!graph[nextY][nextX] && !visited[nextY][nextX])
#                     {
#                         visited[nextY][nextX] = true;
#                         q.push(make_pair(nextY, nextX));
#                     }
#                 }
#             }
#         }
#         result++;
#     }
# }
# 
# 
# 
# int main(void)
# 
# {
# 
#     cin >> N;
# 
#     for (int i = 0; i < N; i++)
# 
#         for (int j = 0; j < N; j++)
# 
#             cin >> graph[i][j];
# 
#     int cnt = 1;
#     //DFS를 통해 섬 표시
#     for (int i = 0; i < N; i++)
#         for (int j = 0; j < N; j++)
# 
#             if (graph[i][j] && !visited[i][j])
# 
#                 DFS(i, j, cnt++);
# 
#     int result = INF;
# 
#     //각 섬에서 제일 가까운 섬까지 다리 놓을 때 최소 길이 구한다
# 
#     for (int i = 0; i < 5; i++) {
#         for (int j = 0; j < 5; j++) {
#             cout << graph[i][j] << " ";
#         }cout << "\n";
#     }cout << "\n";
#     for (int i = 0; i < 5; i++) {
#         for (int j = 0; j < 5; j++) {
#             cout << visited[i][j] << " ";
#         }cout << "\n";
#     }
#     for (int i = 1; i < cnt; i++)
# 
#     {
# 
#         memset(visited, false, sizeof(visited));
# 
#         result = min(result, BFS(i));
# 
#     }
# 
# 
# 
#     cout << result << endl;
#     for (int i = 0; i < 5; i++) {
#         for (int j = 0; j < 5; j++) {
#             cout << graph[i][j] << " ";
#         }cout << "\n";
#     }cout << "\n";
#     for (int i = 0; i < 5; i++) {
#         for (int j = 0; j < 5; j++) {
#             cout << visited[i][j] << " ";
#         }cout << "\n";
#     }
#     return 0;
#     
# }
# 

# In[6]:





# In[ ]:




