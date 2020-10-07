#include <iostream>

using namespace std;
#define forloop(i, j) for(int i = 0; i < j; i++)

int C, n;
int board[101][101];
int cache[101][101];

int jump_to_end(int y, int x) {
	if (y >= n || x >= n) 
		return 0;
	if (y == n - 1 && x == n - 1) {
		return 1;
	}

	int& ret = cache[y][x];
	if (ret != -1) 
		return ret;
	
	ret = jump_to_end(y + board[y][x], x) || jump_to_end(y, x + board[y][x]);
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0][0], &cache[100][100], -1);
		forloop(i, n)
			forloop(j, n) 
				cin >> board[i][j];
			
		if (jump_to_end(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";

	}

}