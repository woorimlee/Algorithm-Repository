/*
count_poly(n, first) // n개 남아있고, 그 중 first개를 첫 줄에 씀
if n == first 
	return 1
for int second = 1 ~ n-first 
	ans += (second + first - 1) * count_poly(n - first, second);
return ans;
*/

#include <iostream>
#include <vector>

using namespace std;

#define MOD 10000000

int C;
int cache[101][101];

//N개 남아있고, 그 중 first개를 첫 줄에 씀
int count_poly1(int N, int first) {
	if (N == first)
		return 1;

	int& ret = cache[N][first];
	if (ret != -1)
		return ret;

	ret = 0;
	int temp_sum = 0;
	for (int second = 1; second <= (N - first); second++) {
		temp_sum = count_poly1(N - first, second) * (second + first - 1);
		ret = (ret + (temp_sum) % MOD) % MOD;
	}
	return ret;
}

int count_poly2(int N, int first) { 
	if (N == first)
		return 1;

	int& ret = cache[N][first];
	if (ret != -1)
		return ret;

	ret = 0;
	int temp_cnt = 0, temp_mul = 1;
	for (int second = 1; second <= (N - first); second++) {
		temp_cnt = count_poly2(N - first, second);
		if(first != 0)
			temp_mul = (second + first - 1);
		ret = (ret + (temp_cnt * temp_mul) % MOD) % MOD;
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		fill(&cache[0][0], &cache[100][101], -1);
		int ans = 0;
		/*for (int i = 1; i <= N; i++) {
			ans = (ans + count_poly1(N, i)) % MOD;
		}
		cout << ans << "\n";
		*/
		cout << count_poly2(N, 0) << "\n";
	}
	return 0;
}