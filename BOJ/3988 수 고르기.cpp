/*#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
const int MAX = 1000000;
const int INF = 987654321;

int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	deque<int> dq; //idx
	int result = INF;

	K = N - K;
	//�����̵� ������
	for (int i = 0, j = 1; i + K <= N; i++)
	{
		if (!dq.empty() && dq.front() <= i)
			dq.pop_front();

		//K���� Ȯ��
		for (; j < i + K; j++)
		{
			//arr[j] - arr[j - 1]�� �ִ뿩���Ѵ�
			while (!dq.empty() && arr[j] - arr[j - 1] <= arr[dq.back()] - arr[dq.back() - 1])
				dq.pop_back();

			dq.push_back(j);
		}

		int m = arr[dq.front()] - arr[dq.front() - 1]; //�� �� �� ���� ��
		int M = arr[i + K - 1] - arr[i]; //�� �� ��
		cout << " m & M : " << m << " " << M << " : ";
		for (auto it : dq) {
			cout << it << " ";
		}cout << "\n";

		result = min(result, m + M);
	}

	cout <<result << "\n";
	return 0;
}*/