#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N, K, M, answer;
vector <vector <char> > vec;
string str;

void dfs(int start, int now, int startNode, int kTime);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		//초기화
		answer = 0;
		cin >> N >> K >> M;
		vec.clear();
		vec.resize(N);

		//입력
		for (int i = 0; i < N; i++) {
			cin >> str;
			for (int k = 0; k < str.size(); k++) {
				vec[i].push_back(str[k]);
			}
		}

		for (int k = vec.size(); k >= 1; k--) {
			for (int start = 0; start < N; start++) {
				dfs(start, 0, start, k);
			}
		}

		cout << "#" << tc << " " << answer % M << "\n";
	}
	return 0;
}

void dfs(int start, int now, int startNode, int kTime) {
	if (now == kTime) {
		if (start == startNode) {
			answer++;
		}
		return;
	}

	for (int i = 0; i < vec[start].size(); i++) {
		if (vec[start][i] == 'Y') {
			dfs(i, now + 1, startNode, kTime);
		}
	}
}