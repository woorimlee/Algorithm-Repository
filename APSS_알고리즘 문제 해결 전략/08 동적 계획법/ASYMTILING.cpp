/*
방법 1 : 전체 타일링 - 대칭으로 타일링 된 모델
대칭의 종류 :	1. n이 짝수인 경우
					1-1. n/2 사이즈가 모두 대칭인 경우 (가운데가 2*1 세로로 채워짐)
					1-2. n/2 - 1 사이즈가 모두 대칭인 경우 (가운데가 1 * 2 가로로 채워짐)
				2. n이 홀수인 경우 n/2 -

방법 2 : 비대칭 타일 모델 갯수 세기
	1. 맨 끝이 대칭이면, 안에는 무조건 비대칭
	2. 맨 끝이 비대칭이면 노상관.
-> 1과 2의 경우로 나누되, 1만 실행한 경우 return 0을 시킴.
-> 2가 실행되는 경우 실제로 타을 갯수 세기.
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
int cache2[101];
int asymmetric_ver2(int width) {
	if (width <= 2) {
		// 2 * 1 가로로 긴 거 위 아래 두 개를 채우든,
		// 1 * 2 세로로 긴 거 좌 우로 두 개를 채우든 대칭임
		return 0;
	}

	int& ret2 = cache2[width];
	if (ret2 != -1)
		return ret2;

	ret2 = asymmetric_ver2(width - 2) % MOD; // 양 끝이 1 * 2 세로로 긴 거 대칭
	ret2 = (ret2 + asymmetric_ver2(width - 4)) % MOD; 
	ret2 = (ret2 + tiling(width - 3) * 2 % MOD) % MOD;
	return ret2;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n + 1], -1);
		fill(&cache2[0], &cache2[n + 1], -1);
		//cout << asymmetric_ver1(n) << "\n";
		cout << asymmetric_ver2(n) << "\n";
	}
	return 0;
}