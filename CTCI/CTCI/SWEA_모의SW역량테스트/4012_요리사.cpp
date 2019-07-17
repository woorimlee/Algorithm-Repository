#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <memory.h>

using namespace std;

int T, N, answer;
bool arrCheck[17];
int arr[17][17];

int calFood() {
	vector <int> vecA, vecB;
	int calA = 0;
	int calB = 0;
	for (int i = 0; i < N; i++) {
		if (arrCheck[i] == true) {
			vecA.push_back(i);
		}
		else
			vecB.push_back(i);
	}
	//vecA = 0 1 5,   vecB = 3 4 2,
	for (int i = 0; i < (N / 2 - 1); i++) {
		for (int j = i + 1; j < N / 2; j++) {
			calA += arr[vecA[i]][vecA[j]] + arr[vecA[j]][vecA[i]];
			calB += arr[vecB[i]][vecB[j]] + arr[vecB[j]][vecB[i]];
		}
	}
	return abs(calA - calB);
}

void dfs(int cur, int len) {
	//기저 조건 추가 
	//1 2 3 4 5 6에서 len이 0인데 4부터 안되게
	if (len == (N / 2)) {
		answer = min(answer, calFood());
		return;
	}

	for (int i = cur; i < N; i++) {
		arrCheck[i] = true;
		dfs(i + 1, len + 1);
		arrCheck[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		memset(arrCheck, false, sizeof(arrCheck));
		answer = INT_MAX;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> arr[j][k];
			}
		}

		dfs(0, 0);
		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}