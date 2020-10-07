#include<iostream>
#include<queue>

using namespace std;

int R, C;
int start_x, start_y, end_x, end_y;
//[][0] == x, [][1] == y
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
char map[51][51];
bool visited[51][51] = { false };
struct Hedgehog {
	int x;
	int y;
	int time;
};
queue <struct Hedgehog> escape;
queue <pair <int, int> > water;

void bfs();

int main() {
	//ó�� �Է�
	cin >> R >> C;
	for (int i = 0; i < R; i++)	{
		for (int j = 0; j <  C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				water.push({ j, i });
			}

			else if (map[i][j] == 'D') {
				end_x = i;
				end_y = j;
			}

			else if (map[i][j] == 'S') {
				start_y = i;
				start_x = j;
			}
		}
	}

	bfs();

	if (visited[end_x][end_y])
		cout << "";
	else
		cout << "KAKTUS";

	return 0;

}

void bfs() {
	//����ġ �̵� ������ ������ while
		//�� ä���
			//1. * ���� �����¿� �˻� 
			//2. ��, �����, * �ƴϸ�
			//3. *�� �ٲٱ�
		//����ġ �̵��ϰ�
			//1. ����ġ ��ġ���� �����¿� �˻� 
			//2. ��, * �ƴϸ� ť�� �߰�
			//3. D�� Ż�� & ������
	int water_size, water_x, water_y, water_nx, water_ny;
	int Hedgehog_size, hh_nx, hh_ny;
	struct Hedgehog hh;
	escape.push({ start_x, start_y, 0 });
	visited[start_y][start_x] = true;
	while (!escape.empty()) {
		//�� ä���
		water_size = water.size();
		for (int i = 0; i < water_size; i++) {
			water_x = water.front().first;
			water_y = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				water_nx = water_x + dir[j][0];
				water_ny = water_y + dir[j][1];
				if (0 <= water_nx && water_nx < C && 0 <= water_ny && water_ny < R) {
					if (map[water_ny][water_nx] == '.') {
						map[water_ny][water_nx] = '*';
						water.push({ water_nx, water_ny });
					}
				}
			}
		}
		//����ġ �̵��ϰ�
		Hedgehog_size = escape.size();
		for (int i = 0; i < Hedgehog_size; i++) {
			hh = escape.front();
			escape.pop();
			for (int j = 0; j < 4; j++) {
				hh_nx = hh.x + dir[j][0];
				hh_ny = hh.y + dir[j][1];
				if (0 <= hh_nx && hh_nx < C && 0 <= hh_ny && hh_ny < R) {
					if (map[hh_ny][hh_nx] == '.' && !visited[hh_ny][hh_nx]) {
						visited[hh_ny][hh_nx] = true;
						escape.push({ hh_nx, hh_ny, hh.time + 1 });
					}
					else if (map[hh_ny][hh_nx] == 'D') {
						visited[hh_ny][hh_nx] = true;
						cout << hh.time+1;
						return;
					}
				}
			}
		}

	}
}