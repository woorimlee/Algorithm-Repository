#include <iostream>

using namespace std;

int N, ans;
int roma[4] = { 1, 5, 10, 50 };
bool visited[50 * 20 + 1];

void dfs(int now, int cnt, int num) {
	if (cnt == N) {
		if (visited[num] == false) {
			visited[num] = true;
			ans++;
		}
		return;
	}

	for (int i = now; i < 4; i++) {
		dfs(i, cnt + 1, num + roma[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}