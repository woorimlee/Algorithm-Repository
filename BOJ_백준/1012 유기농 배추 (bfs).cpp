#include <iostream>
#include <queue>

using namespace std;
int T, M, N, K, X, Y;
//�� ������ �Ʒ� ���� ����
int dir[4][2] = { {-1, 0 }, {0, 1}, {1, 0}, {0, -1 } };

int main() {

	cin >> T;
	while (T--) {
		int temp_x;
		int temp_y;
		//field�� �� �׽�Ʈ ���̽����� �ʱ�ȭ�Ǿ����.
		//���� �ݺ��� or memset �Լ� or fill �Լ��� ���ų�
		//���� ��ü�� ���� ������
		bool field[51][51] = { false };
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> temp_x >> temp_y;
			field[temp_x][temp_y] = true;
		}

		//2���� �迭 0, 0���� N-1, M-1���� ������ ���� �� Ž��
		//true�� ������ ���� �ش� �������� ��翵���� ��� bfs�� Ž��
		int cnt = 0; //*cnt = ������ ���� ����
		queue <pair<int, int > > q; //*first�� y��ǥ, second�� x��ǥ ������ ����
		pair <int, int> now; //*bfs Ž���� �� q.front �޾��� ����
		int ny, nx; //*now ��ǥ���� �����¿� Ž���� ����
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == true) { //*���߰� �ִ� ���̴� bfs Ž�������� ������ ���� Ž��
					q.push({ i, j });
					field[i][j] = false; //*������ ���� ��ġ false�� �ٲ� 
					//(�ٽ� Ž�� ���ϰ�. push�� �� ��Ʈ�� ������)
					while (!q.empty()) {
						now = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							ny = now.first + dir[i][0];
							nx = now.second + dir[i][1];
							if (ny < 0 || nx < 0 || ny >= M || nx >= N || field[ny][nx] == false)
								continue;
							q.push({ ny, nx });
							field[ny][nx] = false;
						}
					}
					//bfs Ž�� ������ �ش� �������� �����̰� �� �� �ִ°��� �� ����.
					//�� 1 ����
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}