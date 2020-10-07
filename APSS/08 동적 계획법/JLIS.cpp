#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const ll LM = numeric_limits<long long>::min();
int C, n, m;
int cache[101][101];

int jlis(const vector<int>& A, const vector<int>& B, int Adx, int Bdx) {
	int& ret = cache[Adx + 1][Bdx + 1];
	if (ret != -1)
		return ret;

	ret = 2; //jlis 들어왔을 때 최소 ret의 return 값은 2
	//ll a = (Adx == -1) ? LLONG_MIN : A[Adx];
	//ll b = (Bdx == -1) ? LLONG_MIN : B[Bdx];
	ll a = (Adx == -1) ? LM : A[Adx];
	ll b = (Bdx == -1) ? LM : B[Bdx];
	ll max_num = max(a, b); // 둘 중 큰 거 찾아서 그것보다 큰 값으로 jlis 확장
	//ll max_num = (a, b) 라고 해버림. 
	//https://docs.microsoft.com/ko-kr/cpp/cpp/comma-operator?view=vs-2019
	//링크 확인해서 무슨 일이 벌어지는 지 확인하자.

	for (int nextA = Adx + 1; nextA < A.size(); nextA++) {
		if (max_num < A[nextA])
			ret = max(ret, jlis(A, B, nextA, Bdx) + 1);
	}
	for (int nextB = Bdx + 1; nextB < B.size(); nextB++) {
		if (max_num < B[nextB])
			ret = max(ret, jlis(A, B, Adx, nextB) + 1);
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n >> m;
		fill(&cache[0][0], &cache[n][m + 1], -1);
		vector<int> A(n, 0);
		vector<int> B(m, 0);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		cout << jlis(A, B, -1, -1) - 2 << "\n";
	}
	return 0;
}