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

	ret = 2; //jlis ������ �� �ּ� ret�� return ���� 2
	//ll a = (Adx == -1) ? LLONG_MIN : A[Adx];
	//ll b = (Bdx == -1) ? LLONG_MIN : B[Bdx];
	ll a = (Adx == -1) ? LM : A[Adx];
	ll b = (Bdx == -1) ? LM : B[Bdx];
	ll max_num = max(a, b); // �� �� ū �� ã�Ƽ� �װͺ��� ū ������ jlis Ȯ��
	//ll max_num = (a, b) ��� �ع���. 
	//https://docs.microsoft.com/ko-kr/cpp/cpp/comma-operator?view=vs-2019
	//��ũ Ȯ���ؼ� ���� ���� �������� �� Ȯ������.

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