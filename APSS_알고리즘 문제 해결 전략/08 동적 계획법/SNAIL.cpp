/*
확률 문제도 dp로
앞으로 m일 동안 비올 확률 75%
비가 오면 h(달팽이 현재 위치) + 2, 안 오면 h + 1
m일 동안 움직인 달팽이의 h가 n보다 큰 경우의 수 / 2^m == 답
*/

#include <iostream>

#define MAX_M 1001

using namespace std;

int C;
int n, m;

double cache[MAX_M * 2][MAX_M];	//MAX_M * 2 : 높이
								//MAX_M : Day

//sanil_percentage
double snail_per(int h, int d) {
	if (d == m)
		return h >= n ? 1.0 : 0.0;

	double& ret = cache[h][d];
	if (ret != -1)
		return ret;

	ret = (0.75 * snail_per(h + 2, d + 1)) + (0.25 * snail_per(h + 1, d + 1));
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n >> m;
		fill(&cache[0][0], &cache[m * 2][m + 1], -1);
		cout << fixed;
		cout.precision(10);
		cout << snail_per(0, 0) << "\n";
	}
	return 0;
}