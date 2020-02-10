#include <iostream>
#include <memory.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, ans;
bool material[17] = { false };
int table[17][17] = { 0, };

int calc_Synergy() {
	int synergyA = 0, synergyB = 0;
	vector <char> A, B;
	for (int i = 0; i < N; i++) {
		if (material[i]) {
			A.push_back(i);
		}
		else
			B.push_back(i);
	}

	for (int i = 0; i < A.size() - 1; i++) {
		for (int j = i + 1; j < A.size(); j++) {
			synergyA += table[A[i]][A[j]] + table[A[j]][A[i]];
			synergyB += table[B[i]][B[j]] + table[B[j]][B[i]];
		}
	}

	return abs(synergyA - synergyB);
}

void dfs(int cur, int num) { //cur == current 현재 선택할 재료, num == 총 선택한 갯수
	//base case
	if (num == N / 2) {
		ans = min(ans, calc_Synergy());
		return;
	}

	for (int i = cur; i < N; i++) {
		material[i] = true;
		dfs(i + 1, num + 1);
		material[i] = false;
		//back tracking
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = INT_MAX;
		memset(material, false, sizeof(material));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> table[i][j];
			}
		}
		//calc_Synergy() 확인
		/*
		material[0] = true;
		material[1] = true;
		cout << calc_Synergy();
		*/
		//배열 확인
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << table[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		dfs(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}