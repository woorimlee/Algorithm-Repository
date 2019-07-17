#include <iostream>
#include <vector>

using namespace std;

int N;

//각 소수가 하나씩만 있는 집합에서
//연속된 원소들의 합을 구하는 것이니
//Two pointer를 사용하면 됨.
//1. 중복 없는 소수 집합 구해 놓고 (N 까지)
//2. 연속된 원소인 부분 합이 N인 것을 찾으면 경우의 수(answer) ++.
int main(void) {
	ios::sync_with_stdio(false);

	cin >> N;

	//false로 초기화 된 N개의 원소를 갖는 벡터 vec
	vector <bool> vec(N + 1, false);
	vector <int> decimal;

	//vec에서 소수가 아닌 것은 true로 바꾼다.
	for (long long i = 2; i <= N; i++) {
		if (vec[i] == false) {
			for (long long j = i*i; j <= N; j += i) {
				vec[j] = true;
			}
			decimal.push_back(i);
		}
	}

	//첫 번째 소수는 2
	int sum = 2, answer = 0;
	int left = 0, right = 0;

	while (right < decimal.size() && left <= right) {
		if (sum <= N) {
			if (sum == N) answer++;
			right++;
			if (right >= decimal.size()) break;
			sum += decimal[right];
		}

		else if (sum > N) {
			sum -= decimal[left];
			left++;
			if (left > right) {
				right = left;
				if (left < decimal.size()) sum = decimal[left];
			}
		}
	}

	cout << answer << endl;

	return 0;
}