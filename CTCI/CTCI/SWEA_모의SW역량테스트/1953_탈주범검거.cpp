#include <iostream>
#include <memory.h>

using namespace std;

int T;
//���� �ͳ� ������ ���� ũ�� N, ���� ũ�� M, ��Ȧ �Ѳ��� ��ġ������� ���� ��ġ R, ���� ��ġ C, �׸��� Ż�� �� �ҿ�� �ð� L
int N, M, R, C, L;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
bool visited[51][51] = { false, };
//������ ���� �� �ִ� ��ġ
bool location[51][51];
int map[51][51];

void dfs(int X, int Y, int time);

int main(void) {
	cin >> T;
	int answer;

	for (int i = 1; i <= T; i++) {
		//�׽�Ʈ ���̽����� �ʱ�ȭ
		memset(location, false, sizeof(location));
		memset(map, 0, sizeof(map));
		answer = 0;
		cin >> N >> M >> R >> C >> L;
		
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> map[y][x];
			}
		}

		dfs(C, R, 0);
		//�̵� ������ ��ġ �˻�
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (location[y][x])
					answer++;
			}
		}

		cout << "#" << i  << " " << answer << "\n";
	}

	return 0;
}

void dfs(int X, int Y, int time) {
	//���̽� �����
	if (time == L)
		return;

	location[Y][X] = true;
	int cur = map[Y][X]; //cur = current
	int next;
	int nx, ny;

	//�ڱ� ��ǥ���� �� �� �� �� �˻�
	for (int i = 0; i < 4; i++) {
		nx = X + direct[i][0];
		ny = Y + direct[i][1];
		next = map[ny][nx];

		//�� ���� �������� ����, �̹� �湮�� ���̰�, ���� ���� �����
		if (map[ny][nx] == 0) continue;
		else if (visited[ny][nx]) continue;
		else if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		//�ڱ� ������ ���°� ���� �̵��� �� �ִ°� �ƴ϶��
		if (i == 0 && (cur == 3 || cur == 5 || cur == 6)) continue;
		//��
		else if (i == 1 && (cur == 2 || cur == 6 || cur == 7)) continue;
		//��
		else if (i == 2 && (cur == 3 || cur == 4 || cur == 7)) continue;
		//��
		else if (i == 3 && (cur == 2 || cur == 4 || cur == 5)) continue;

		//���� ������ ���°� ������ �Ұ����� ���¶��
		if (i == 0 && (next == 3 || next == 4 || next == 7)) continue;
		else if (i == 1 && (next == 2 || next == 4 || next == 5)) continue;
		else if (i == 2 && (next == 3 || next == 5 || next == 6)) continue;
		else if (i == 3 && (next == 2 || next == 6 || next == 7)) continue;

		visited[Y][X] = true;
		dfs(nx, ny, time + 1);
		visited[Y][X] = false;
	}
}