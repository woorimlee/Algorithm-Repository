#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int x = 1, y = 1, face = 0;

//face = 0(�Ʒ�), ������, ��, ����
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
    int nx=0, ny=0, lx=0, ly=0;//n- : ����, l- : ����
    /* 
    ������ �������� ������� -> ����
    1) ���� ���� : 
        (1) �� ��ġ ���� n- ��, l- �� : �״��
        (2) n- ��, l- �� : (1)�� �� ������ ��ȸ��
        (3) n- ��, l- �� : (1)�� �� ������ ��ȸ��
        (4) n- ��, l- �� : ��ȸ��
    2) ���� ���� �� �����Ѵ�.
    */
    
    
    while (!(x == goal && y == goal)) {//������ ��������
        //1) ���� ����
        lx = x + left_dir[face][0];
        ly = y + left_dir[face][1];
        nx = x + dir[face][0];
        ny = y + dir[face][1];
        cout << x << " , " << y << " : " << nx << ny << lx << ly << "\n";
        //(1) ����(n)�� �շ��ְ�, ����(l)�� �������� �ƹ��͵� ����
        //(2) n ��, l ��
        if (wall_maze[ny][nx] == 0 && wall_maze[ly][lx] == 0) {
                face = (face + 1) % 4;
                lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
        }
        //(3) n ��, l �� 
        else if (wall_maze[ny][nx] == 1 && wall_maze[ly][lx] == 1) {
            //cout << " 3 ";
            while (!(wall_maze[ny][nx] == 0 && wall_maze[ly][lx] == 1)) {
                face = face - 1 < 0 ? face = 3 : face - 1;
                lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
            }
        }
        //(4) n ��, l ��
        else if (wall_maze[ny][nx] == 1 && wall_maze[ly][lx] == 0) {
            //cout << " 4 ";
            face = (face + 1) % 4;
            lx = x + left_dir[face][0]; ly = y + left_dir[face][1]; nx = x + dir[face][0]; ny = y + dir[face][1];
        }
        //����
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