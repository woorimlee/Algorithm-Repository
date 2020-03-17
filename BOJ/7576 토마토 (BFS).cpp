#include<iostream>
#include<queue>
using namespace std;

//[i][0] == y, [i][1] == x
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int tomato[1001][1001];
queue< pair <int, int> > q;


int main() {
	int M, N, size;
	int day = 0;
	int total = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j });
			}
			else if (tomato[i][j] == -1) {
				total++;
			}
		}
	}

	while (!q.empty()) {
		size = q.size();
		total += size;
		//���� ������ ����ִ� ĭ �� ���ļ� �迭�� ũ�Ⱑ �ȴٸ�
		//�� ����ϰ� ���α׷� ����
		if (total == N * M) {
			cout << day;
			return 0;
		}
		//q.size ��ŭ queue�� Ž���ϸ� ���� ���� �丶�丸ŭ�� �˰����� �����ų �� ����
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//�� �� �� �� ���⿡ �� ���� �丶�䰡 ������
			//�Ͱ� ����� queue�� �־���� ���� Ÿ�ӿ� �� ���� ���¸� Ȯ���Ŵ
			for (int j = 0; j < 4; j++) {
				int ny = y + dir[j][0];
				int nx = x + dir[j][1];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (tomato[nx][ny] == 0) {
						tomato[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		day++;
	}
	//�� ���� ������ �ϳ��� �ִٸ� while�� �������ͼ� -1 ����ϰ� ���α׷� ����.
	if (total != N * M) {
		cout << -1;
	}
	return 0;
}