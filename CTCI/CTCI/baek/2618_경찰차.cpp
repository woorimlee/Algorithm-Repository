#include <iostream>
#include <algorithm>
#include <vector>

#define coord pair<int, int> //coordinate
using namespace std;

int N, W;
vector <coord> car1;
vector <coord> car2;
int dp[1001][1001] = { -1, };

//dp °»½Å
void find_Path();

int main() {
	cin >> N >> W;
	car1.resize(W + 1);
	car2.resize(W + 1);
	car1[0] = { 0, 0 };
	car2[0] = { N - 1, N - 1 };
	for (int i = 1; i <= W; i++) {
		cin >> car1[i].first >> car2[i].second;
		car2[i] = car1[i];
	}
	
	find_Path();

	return 0;
}