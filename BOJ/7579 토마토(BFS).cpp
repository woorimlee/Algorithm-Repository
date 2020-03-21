#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
//[i][0] == z, [i][1] == y, [i][2] == x
//�� �Ʒ� ���� ������ �� ��
int dir[6][3] = { {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}, {1, 0, 0}, {-1, 0, 0} };
int tomato[101][101][101];
queue< tuple <int, int, int> > q;

void printTomato() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout << tomato[i][j][k] << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q_size = 0;
	int day = 0;
	//�丶�䰡 �� �ʹ� ��찡 ���ٸ�,
	//���� ���� + �� ���� == M * N * H 
	//total�� �����ص״ٰ� -1�� ����ϴ� ��쿡 ������
	int total = 0;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ i, j, k });
					total++;
				}
				else if (tomato[i][j][k] == -1) {
					total++;
				}
			}
		}
	}

	int nx, ny, nz;
	q_size = q.size();
	while (q_size--) {
		auto [z, y, x] = q.front();
		q.pop();
		//�� �� �� �� �� �� ���⿡ �� ���� �丶�䰡 ������
		//�Ͱ� ����� queue�� �־���� ���� Ÿ�ӿ� �� ���� ���¸� Ȯ���Ŵ
		for (int j = 0; j < 6; j++) {
			nz = z + dir[j][0];
			ny = y + dir[j][1];
			nx = x + dir[j][2];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H) {
				if (tomato[nz][ny][nx] == 0) {
					tomato[nz][ny][nx] = 1;
					q.push({ nz, ny, nx });
					total++;
				}
			}
		}
		if (!q_size) {
			if (q_size = q.size())
				day++;
		}
	}
	//�� ���� ������ �ϳ��� �ִٸ� while�� �������ͼ� -1 ����ϰ� ���α׷� ����.
	if (total != N * M * H) {
		cout << -1;
	}
	else
		cout << day;
	return 0;
}