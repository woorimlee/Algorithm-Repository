//O(N^2)에 풀 수 있는 동적 계획법 풀이. (8장 지도 방식)
// { 1, 5, 9, 2, 3, 1, 5, 4 }
//가 있을 때, {1, 2, 3, 5} or {1, 2, 3, 4}를 구해야함.
//이 과정에서 {1, 2, 3, 5}, {1, 2, 3, 4}, {1, 5, 9}, {2, 3}, {1, 5} 부분 증가 수열이 구해져야 함.
//즉, 배열의 모든 위치에서 증가수열을 구하는 시도를 해봐야 하며, 비둘기 집 원칙에 따라 중복 검사는 반드시 있음.
//lis(idx) : idx에서 시작하는 최장 부분 증가 수열 길이를 return

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;

int cache[501];

//idx가 -1부터 시작하여 0 ~ 길이까지 모든 배열 순회할 것임.
int lis(const vector <int>& s, int idx) { 
	int& ret = cache[idx + 1];
	if (ret != -1)
		return ret;
	
	ret = 1;
	for (int i = idx + 1; i < s.size(); i++) {
		if (idx == -1 || s[idx] < s[i])
			ret = max(ret, lis(s, i) + 1);
	}

	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N;
		fill(&cache[0], &cache[500], -1);
		vector <int> seq(N, 0);
		for (int i = 0; i < N; i++)
			cin >> seq[i];
		cout << lis(seq, -1) - 1 << "\n";
	}

	return 0;
}