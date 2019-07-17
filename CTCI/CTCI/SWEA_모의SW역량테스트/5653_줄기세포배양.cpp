#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct cell {
	int X;
	int x, y;
	int inact = 0;// 비활성 값
	int act = 0; // 활성 값
};

int T, N, M, K;
int mid = 150;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int arr[350][350];

void bfs(queue <cell> *que) {
	int nx, ny;
	cell cur, temp;
	for (int i = 0; i <= K; i++) { // i = time
		for (int j = 10; j > 0; j--) { // j = X 값 
			int size = que[j].size();
			for (int k = 0; k < size; k++) {
				cur = que[j].front();
				que[j].pop();
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (int i = 1; i <= T; i++) {
		//입력 & 초기화
		cin >> N >> M >> K;
		memset(arr, 0, sizeof(arr));
		queue <cell> que[11];
		cell temp;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++) {
				cin >> arr[mid + y][mid + x];
				temp.x = x + mid;
				temp.y = y + mid;
				que[arr[mid + y][mid + x]].push(temp);
			}

		bfs(que);
		int answer = 0;
		for (int y = 0; y < 350; y++) {
			for (int x = 0; x < 350; x++) {
				if (arr[y][x] > 0)
					answer++;
			}
		}
		/*
		for (int y = 135; y < 166; y++) {
			for (int x = 135; x < 165; x++) {
				cout << arr[y][x] << " ";
			}
			cout << endl;
		}*/

		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}