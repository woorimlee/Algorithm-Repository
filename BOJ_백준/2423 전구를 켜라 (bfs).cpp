#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using w_cord = pair<int, pair<int, int> >;

const int MAXSIZE = 501;

int N, M;
int board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int dir_y[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dir_x[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == '/') // / : 0, \ : 1
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}

	priority_queue <w_cord, vector<w_cord>, greater<w_cord> > pq; // ���� Ƚ��, y, x
	if (!board[0][0]) { // �� �� ������ \�� �ٲ�
		pq.push({ 1, {0, 0} });
		board[0][0] = 1;
	}
	else
		pq.push({ 0, {0, 0} });
	visited[0][0] = true;

	bool flag = false;
	while (!pq.empty()) {
		w_cord now = pq.top();
		pq.pop();

		int t = now.first, y = now.second.first, x = now.second.second;

		// ������ ����
		if (y == N - 1 && x == M - 1) {
			if (board[y][x])
				cout << t;
			else
				cout << "NO SOLUTION";
			flag = true;
			break;
		}

		//cout << y << ", " << x << " : " << t << "\n";

		for (int i = 0; i < 8; i++) {
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {
				if (i <= 3) { // �� �� �� ��
					if (board[ny][nx] == board[y][x]) { // ���� ����̸�
						// ȸ���ϰ� �̵�����
						board[ny][nx] = board[ny][nx] ? 0 : 1;
						pq.push({ t + 1, {ny, nx} });
					}
					else
						pq.push({ t, {ny, nx} });
					visited[ny][nx] = true;
				}

				else if (i == 4 || i == 5) { // \, 1
					if (board[y][x]) {
						// board�� /����̸� ���� �Ұ�
						// �ڽŰ� �ǵ帮�� �����ϱ�
						if (board[ny][nx] == board[y][x])
							pq.push({ t, {ny, nx} });
						else {
							board[ny][nx] = board[ny][nx] ? 0 : 1;
							pq.push({ t + 1, {ny, nx} });
						}
						visited[ny][nx] = true;
					}
				}

				else if (i == 6 || i == 7) {
					if (!board[y][x]) {
						if (board[ny][nx] == board[y][x])
							pq.push({ t, {ny, nx} });
						else {
							board[ny][nx] = board[ny][nx] ? 0 : 1;
							pq.push({ t + 1, {ny, nx} });
						}
						visited[ny][nx] = true;
					}
				}
			}
		}
	}

	if (!flag)
		cout << "NO SOLUTION";
	return 0;
}