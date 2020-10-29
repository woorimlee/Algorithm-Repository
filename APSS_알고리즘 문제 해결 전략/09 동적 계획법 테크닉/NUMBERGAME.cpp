#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n;
vector <int> board;

const int IMPOSSIBLE = 100000;
int cache[51][51];

int run_game(int lft, int rgt) {
	//base case
	if (lft > rgt)
		return 0;

	int& ret = cache[lft][rgt];
	if (ret != IMPOSSIBLE)
		return ret;

	ret = board[lft] - run_game(lft + 1, rgt);
	ret = max(ret, board[rgt] - run_game(lft, rgt - 1));
	if (rgt - lft >= 1) // 길이가 2 이상
	{
		ret = max(ret, -run_game(lft + 2, rgt));
		ret = max(ret, -run_game(lft, rgt - 2));
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		board.clear();
		board.resize(n + 1);
		fill(&cache[0][0], &cache[50][51], IMPOSSIBLE);
		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}
		cout << run_game(0, n - 1) << "\n";
	}
	return 0;
}