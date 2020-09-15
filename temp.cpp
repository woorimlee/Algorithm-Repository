#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int x = 1, y = 1, face = 0;

//face = 0(아래), 오른쪽, 위, 왼쪽
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int left_dir[4][2] = { {1, 0}, {0, - 1},  {- 1, 0},{0, +1 } };

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    vector <vector<int> > wall_maze;
    wall_maze.resize(maze.size() + 2);
    for (int i = 0; i < wall_maze.size(); i++) {
        if (i == 0 || i == wall_maze.size() - 1) {
            for (int j = 0; j < wall_maze.size(); j++) {
                wall_maze[i].push_back(1);
            }
        }
        else {
            wall_maze[i].push_back(1);
            for (int j = 0; j < maze.size(); j++) {
                wall_maze[i].push_back(maze[i-1][j]);
            }
            wall_maze[i].push_back(1);
        }
    }

    for (int i = 0; i < wall_maze.size(); i++) {
        for (auto it : wall_maze[i]) {
            cout << it << " ";
        }cout << "\n";
    }
    
    int goal = wall_maze.size() - 2;
    int nx=0, ny=0, lx=0, ly=0;//n- : 앞쪽, l- : 왼쪽
    /* 
    목적지 도착까지 방향결정 -> 직진
    1) 방향 결정 : 
        (1) 현 위치 기준 n- 뚫, l- 벽 : 그대로
        (2) n- 뚫, l- 뚫 : (1)이 될 때까지 좌회전
        (3) n- 벽, l- 벽 : (1)이 될 때까지 우회전
        (4) n- 벽, l- 뚫 : 좌회전
    2) 방향 결정 후 직진한다.
    */
    
    
    while (!(x == goal && y == goal)) {//목적지 도착까지
        //1) 방향 결정
        lx = x + left_dir[face][0];
        ly = y + left_dir[face][1];
        nx = x + dir[face][0];
        ny = y + dir[face][1];
        cout << x << " , " << y << " : " << nx << ny << lx << ly << "\n";
        //(1) 앞쪽(n)은 뚫려있고, 옆쪽(l)은 벽있으면 아무것도 안함
        //(2) n 뚫, l 뚫
        if (wall_maze[ny][nx] == 0 && wall_maze[ly][lx] == 0) {
                face = (face + 1) % 4;
                lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
        }
        //(3) n 벽, l 벽 
        else if (wall_maze[ny][nx] == 1 && wall_maze[ly][lx] == 1) {
            //cout << " 3 ";
            while (!(wall_maze[ny][nx] == 0 && wall_maze[ly][lx] == 1)) {
                face = face - 1 < 0 ? face = 3 : face - 1;
                lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
            }
        }
        //(4) n 벽, l 뚫
        else if (wall_maze[ny][nx] == 1 && wall_maze[ly][lx] == 0) {
            //cout << " 4 ";
            face = (face + 1) % 4;
            lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
        }
        //직진
        x = nx;
        y = ny;
        answer++;
    }

    return answer;
}

int main() {
    vector <vector <int> > maze = { {0,1,0,1}, {0,1,0,0}, {0,0,0,0}, {1,0,1,0} };
    solution(maze);
    return 0;
}