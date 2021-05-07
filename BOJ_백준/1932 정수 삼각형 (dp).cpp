#include <iostream>
#include <algorithm>

using namespace std;

const int MAXSIZE = 500;
int n;
int triangle[MAXSIZE][MAXSIZE];
// int cache[MAXSIZE][MAXSIZE];
int cache2[2][MAXSIZE]; // 슬라이딩 윈도우 기법 적용

/*
// 상향식, 타뷸레이션, 반복적 dp
int iterative_dp() {
	//base case
	for (int x = 0; x < n; x++) {
		cache[n - 1][x] = triangle[n - 1][x];
	}

	for (int y = n - 2; y >= 0; y--) {
		for (int x = 0; x < y + 1; x++) {
			cache[y][x] = max(cache[y + 1][x], cache[y + 1][x + 1]) + triangle[y][x];
		}
	}

	return cache[0][0];
}*/

// 슬라이딩 윈도우 적용한 dp
int iterative_dp_sw() {
	//base case
	for (int x = 0; x < n; x++) {
		cache2[(n - 1) % 2][x] = triangle[n - 1][x];
	}

	for (int y = n - 2; y >= 0; y--) {
		for (int x = 0; x < y + 1; x++) {
			cache2[y % 2][x] = max(cache2[(y + 1) % 2][x], cache2[(y + 1) % 2][x + 1]) + triangle[y][x];
		}
	}

	return cache2[0][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			cin >> triangle[y][x];
		}
	}

	// int ret = iterative_dp();
	int ret = iterative_dp_sw();
	cout << ret;
	return 0;
}