#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int M, m;
	int ans = INT_MAX;
	cin >> N >> K;
	int S = N - K; // 슬라이딩 윈도우 사이즈

	vector <int> arr(N);
	deque <int> dq;

	int i;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	//슬라이딩 윈도우를 사용할 예정이며, M을 쉽게 구하기 위해
	//배열을 정렬할 예정.

	//정렬된 수열에서 K개의 수를 제거했다면, N-K 크기의 슬라이딩 윈도우를 생성.
	//각 윈도우에서 
	//M ==> 배열 양 끝의 차이
	//m ==> 윈도우 내에 있는 인접한 두 원소의 모든 차이값 중 가장 작은 값
	//m과 관련된 인덱스 값을 슬라이딩 윈도우의 deque에 넣을 것임.

	//윈도우 옮길 때마다 M+m의 최솟값을 기억해두면 됨.
	
	//윈도우 생성 전까지 & m을 계산하려면 최소 arr[1]부터 시작
	for (i = 1; i < S - 1; i++) {
		while ((!dq.empty()) && (arr[i] - arr[i - 1]) < (arr[dq.back()] - arr[dq.back() - 1])) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	//본격적인 슬라이딩 윈도우
	//슬라이딩 윈도우에 대한 설명은 https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
	//제가 짠 코드 기반으로 되어있는 설명은 https://github.com/woorimlee/Algorithm_BOJ_CTCI_SWEA_cpp/blob/master/BOJ/11003%20%EC%B5%9C%EC%86%9F%EA%B0%92%20%EC%B0%BE%EA%B8%B0%20(%EC%8A%AC%EB%9D%BC%EC%9D%B4%EB%94%A9%20%EC%9C%88%EB%8F%84%EC%9A%B0).cpp
	for (; i < N; i++) {
		while ((!dq.empty()) && dq.front() <= i - S) {
			dq.pop_front();
		}
		while ((!dq.empty()) && (arr[i] - arr[i - 1]) < (arr[dq.back()] - arr[dq.back() - 1])) {
			dq.pop_back();
		}
		dq.push_back(i);
		M = arr[i] - arr[i - S + 1];
		m = arr[dq.front()] - arr[dq.front() - 1];
		ans = min(ans, M + m);
	}
	cout << ans;

	return 0;
}