#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N, K, L, time=0;
int dir = 0; //���� ���������� ���� �� ����
//������� ��, ��, ��, ��
int direct[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
//��� = 2, �� = 1, �� = 0
int map[101][101] = { 0, };

queue <pair<int, char> > turn;
//���� front���� ���� ��ġ��, back���� �Ӹ� ��ġ�� �������.
deque <pair <int, int> > snake;

void turn_Snake(char t);

int main() {
	cin >> N >> K;
	int y, x;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		map[y - 1][x - 1] = 2;
	}
	cin >> L;
	char t;
	for (int i = 0; i < L; i++) {
		cin >> x >> t;
		turn.push({ x, t });
	}

	map[0][0] = 1;
	//first == y��ǥ, second == x��ǥ
	snake.push_back({ 0,0 });
	int nx, ny;
	pair <int, int> head;
	while (true) {
		//�� �̵� Ȯ�ο�
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		if (!turn.empty()) {
			if (turn.front().first == time) {
				turn_Snake(turn.front().second);
				turn.pop();
			}
		}
		//�Ӹ� �κ� ��ġ ��������
		head = snake.back();
		ny = head.first + direct[dir][0];
		nx = head.second + direct[dir][1];

		time++;

		//���� ��ġ�� ���̰ų� ���̶�� ��
		if (N <= ny || ny < 0 || N <= nx || nx < 0 || map[ny][nx] == 1)
			break;

		//���� ��ġ�� ���̸�
		else if (map[ny][nx] == 0) {
			//���� ��ǥ ����
			map[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		
		//�Ӹ� ��ǥ �־�
		snake.push_back({ ny, nx });
		map[ny][nx] = 1;
	}

	cout << time << "\n";
	return 0;
}

/*
	L�� �������� ȸ��,
	D�� ���������� ȸ��.
	���� �ִ� ������
	1) �������̾��� : L�̸� ��, D�� �Ʒ�
	2) �����̾��� : L�̸� �Ʒ�, D�� ��
	3) �Ʒ����� : L�̸� ������, D�� ����
	4) ������ : L�̸� ����, D�� ������
	L : �� -> �� -> �� -> ��
	D : �� <- �� <- �� <- ��
	���� ���� dir���� L�̸� + 1��, R�̸� -1��
*/
void turn_Snake(char t) {
	if (t == 'L') {
		(dir != 3) ? dir += 1 : dir = 0;
	}
	else {
		(dir != 0) ? dir -= 1 : dir = 3;
	}
}