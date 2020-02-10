#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;

int run(int n, int &row, int sum, vector<vector<int> > &land, int except) {
	if (n >= row) {
		answer = max(answer, sum);
		return 0;
	}

	for (int i = 0; i < 4; i++) {
		if (i == except) continue;
		run(n + 1, row, sum + land[n][i], land, i);
	}
	return 0;

}

int main(void)
{

	vector<vector<int> > land = { {1,2,3,5}, {5,6,7,8}, {4,3,2,1} };
	int row = land.size();
	run(0, row, 0, land, 5);

	cout << answer << endl;

	return 0;
}
