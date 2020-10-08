/*
tiling(n) = 2 * n 크기의 사각형을 타일로 덮을 수 있는 경우의 수를 return

int tiling(n) { n에 대한 cache 처리
	base case	1) cache 확인
				2) n == 0일때 return 1;
				3) n < 0일때 return 0;
				--> 더 좋은 방법 n <= 1일 때 return 1
	return tiling(n - 1) + tiling( n - 2); 
	//n-1 : 세로로 타일 덮기
	//n-2 : 가로의 타일 두 개를 위 아래로 놓고 사각형 덮기
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

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n+1], -1);
		cout << tiling(n) << "\n";
	}
	return 0;
}