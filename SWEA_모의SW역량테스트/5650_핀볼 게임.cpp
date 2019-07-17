#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct wormholl {
	int count;
	int x[2];
	int y[2];
}wh[5];

int T, N, answer;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
//[1������ 5�� ��ϱ���][�ɺ��� ��, ��, ��, �� �������� ����Ǵ� �������� ���� ��ȯ]
int block[5][4] = { {2, 3, 1, 0}, // �� �� �� �� �������� �����ϴ� 1�� ��� ������
					{1, 3, 0, 2}, // 2�� ������
					{3, 2, 0, 1}, // 3�� ������
					{2, 0, 3, 1}, // 4�� ������
					{2, 3, 0, 1} };// 5�� ������ || ��� ������
int map[101][101];

int pinBall(int x, int y);

int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;
		//�ʱ�ȭ ����
		memset(map, 0, sizeof(map));
		answer = 0;
		for (int i = 0; i < 5; i++) {
			wh[i].count = 0;
		}

		//map ���� �Է�
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];
				//��Ȧ ���� �߰� ����
				if (6 <= map[j][k] && map[j][k] <= 10) {
					wh[map[j][k] - 6].x[wh[map[j][k] - 6].count] = k;
					wh[map[j][k] - 6].y[wh[map[j][k] - 6].count] = j;
					wh[map[j][k] - 6].count++;
				}
			}
		}

		//�ɺ� ���� ���
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == 0) {
					answer = max(answer, pinBall(k, j));	
				}
			}
		}
		cout << "#" << i << " " << answer << "\n";
	}


	return 0;
}

int pinBall(int x, int y) {
	int nx, ny, curBlock, nextDir;
	int curScore, maxScore = 0;
	for (int dir = 0; dir < 4; dir++) {
		nx = x;
		ny = y;
		curScore = 0;
		nextDir = dir;

		do {
			nx += direct[nextDir][0];
			ny += direct[nextDir][1];
			curBlock = map[ny][nx];
			//1. ��踦 ������
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				curScore++;
				nextDir = block[4][nextDir];
			}
			//2. 1~5�� ��� ������
			else if (1 <= curBlock && curBlock <= 5) {
				curScore++;
				nextDir = block[curBlock - 1][nextDir];
			}
			//3. ��Ȧ ������
			else if (6 <= curBlock && curBlock <= 10) {
				//���� ��ǥ�� ���ؼ� �ٸ� �� ��Ȧ�� �̵�
				if ((wh[curBlock - 6].x[0] == nx) && (wh[curBlock - 6].y[0] == ny)) {
					nx = wh[curBlock - 6].x[1];
					ny = wh[curBlock - 6].y[1];
				}
				else {
					nx = wh[curBlock - 6].x[0];
					ny = wh[curBlock - 6].y[0];
				}
			}
		} while ((curBlock != -1) && !(nx == x && ny == y));
		maxScore = max(maxScore, curScore);
	}
	return maxScore;
}