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
	int S = N - K; // �����̵� ������ ������

	vector <int> arr(N);
	deque <int> dq;

	int i;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	//�����̵� �����츦 ����� �����̸�, M�� ���� ���ϱ� ����
	//�迭�� ������ ����.

	//���ĵ� �������� K���� ���� �����ߴٸ�, N-K ũ���� �����̵� �����츦 ����.
	//�� �����쿡�� 
	//M ==> �迭 �� ���� ����
	//m ==> ������ ���� �ִ� ������ �� ������ ��� ���̰� �� ���� ���� ��
	//m�� ���õ� �ε��� ���� �����̵� �������� deque�� ���� ����.

	//������ �ű� ������ M+m�� �ּڰ��� ����صθ� ��.
	
	//������ ���� ������ & m�� ����Ϸ��� �ּ� arr[1]���� ����
	for (i = 1; i < S - 1; i++) {
		while ((!dq.empty()) && (arr[i] - arr[i - 1]) < (arr[dq.back()] - arr[dq.back() - 1])) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	//�������� �����̵� ������
	//�����̵� �����쿡 ���� ������ https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
	//���� § �ڵ� ������� �Ǿ��ִ� ������ https://github.com/woorimlee/Algorithm_BOJ_CTCI_SWEA_cpp/blob/master/BOJ/11003%20%EC%B5%9C%EC%86%9F%EA%B0%92%20%EC%B0%BE%EA%B8%B0%20(%EC%8A%AC%EB%9D%BC%EC%9D%B4%EB%94%A9%20%EC%9C%88%EB%8F%84%EC%9A%B0).cpp
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