/*
방법 1 : 전체 타일링 - 대칭으로 타일링 된 모델
대칭의 종류 :	1. n이 짝수인 경우
					1-1. n/2 사이즈가 모두 대칭인 경우 (가운데가 2*1 세로로 채워짐)
					1-2. n/2 - 1 사이즈가 모두 대칭인 경우 (가운데가 1 * 2 가로로 채워짐)
				2. n이 홀수인 경우 n/2 -

방법 2 : 비대칭 타일 모델 갯수 세기
*/

#include <iostream>

using namespace std;

int C, n;
int MOD = 1000000007;
int cache[101];

int tiling(int size) {
	if (size <= 1) return 1;
	int& ret = cache[size];
	if (ret != -1) return ret;

	ret = tiling(size - 1) + tiling(size - 2);
	return (ret %= MOD);
}

//방법 1
int asymmetric_ver1(int width) {
	int ret;
	if (width % 2 == 1) {
		ret = tiling(width) - tiling(width / 2) + MOD;
		return ret % MOD;
	}
	else {
		ret = (tiling(width) - tiling(width / 2) + MOD) % MOD;
		ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
		return ret;
	}
}

//방법 2
int asymmetric_ver2(int width) {
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n + 1], -1);
		cout << asymmetric_ver1(n) << "\n";
	}
	return 0;
}