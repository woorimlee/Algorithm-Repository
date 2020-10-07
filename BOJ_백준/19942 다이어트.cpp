#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int m[4];
int nutrient[15][4];
int price[15];
int cur_nutrient[4];
int ans_price = 987654321;
vector <int> ans_vec = {};

vector <int> vec; //조합 저장

void dfs(int cnt, int p) { //선택 갯수, 가격
	//base case
	if (cnt >= N) { // 모든 식재료 정보 살펴보면
		//최소 영양성분 검사
		for (int i = 0; i < 4; i++) {
			if (m[i] > cur_nutrient[i]) {
				return;
			}
		}
		//최소 영양성분 통과하면
		if (ans_price > p) {
			ans_price = p;
			ans_vec = vec;
		}
		else if (ans_price == p) {
			ans_vec = min(ans_vec, vec);
		}

		return;
	}

	dfs(cnt + 1, p); // 선택 안 함

	//선택 함
	vec.push_back(cnt); // cnt번째 선택
	for (int i = 0; i < 4; i++) {
		cur_nutrient[i] += nutrient[cnt][i];
	}
	dfs(cnt + 1, p + price[cnt]);

	//백트랙킹
	for (int i = 0; i < 4; i++) {
		cur_nutrient[i] -= nutrient[cnt][i];
	}
	vec.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> nutrient[i][j];
		}
		cin >> price[i];
	}

	dfs(0, 0);

	if (ans_price == 987654321) {
		cout << "-1";
	}
	else {
		cout << ans_price << "\n";
		for (auto it : ans_vec) {
			cout << it + 1 << " ";
		}
	}

	return 0;
}