#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, M;
int INF = 1234567890;
int cache[101][11];
vector <int> S;

int pSum[101], pSqSum[101];
void partialsum() {
	pSum[0] = S[0];
	pSqSum[0] = S[0] * S[0];
	for (int i = 1; i < N; i++) {
		pSum[i] = S[i] + pSum[i - 1];
		pSqSum[i] = S[i] * S[i] + pSqSum[i - 1];
	}
}

int min_error(int begin, int end) {
	//begin to (end - 1)에 있는 숫자들 중 하나를 선택해서(중간값)
	//오차 제곱의 최소 값 계산하기
	//m = 부분합 / 갯수 -> 정수로 표현해야하기 때문에 반올림해줌.
	int sum_a_to_b = pSum[end - 1] - (begin == 0 ? 0 : pSum[begin - 1]);
	int pow_sum_a_to_b = pSqSum[end - 1] - (begin == 0 ? 0 : pSqSum[begin - 1]);
	int m = int(0.5 + (double)(sum_a_to_b) / (end - begin));
	int ret = ((end - begin) * m * m) - (2 * m * (sum_a_to_b)) + (pow_sum_a_to_b);
	return ret;
}

int quantize(int idx, int group) {
	int& ret = cache[idx][group];
	if (ret != -1)
		return ret;

	if (idx == N)
		return 0;
	if (group == M)
		return INF;

	ret = INF;
	for (int i = 1; idx + i <= N; i++) {
		ret = min(ret, quantize(idx + i, group + 1) + min_error(idx, idx + i));
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N >> M;
		fill(&cache[0][0], &cache[N][M + 1], -1);
		S.clear();
		S.resize(N);
		for(int i = 0; i < N; i++)
			cin >> S[i];
		sort(S.begin(), S.end());
		partialsum();
		cout << quantize(0, 0) << "\n";
	}

	return 0;
}