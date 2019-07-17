#include <iostream>
using namespace std;

int N, answer = 0;
int *arr;

void dfs(int cal, int cur) { //cal = ���ݱ��� ���� ���� ��,   cur = ���� ��ȣ �־ ���� ��ġ 
	//���� ����	
	if (cur == N - 1) {
		if (cal == arr[cur])
			answer++;
		return;
	}

	if ((cal + arr[cur]) <= 20)
		dfs(cal + arr[cur], cur + 1);
	if (cal - arr[cur] >= 0)
		dfs(cal - arr[cur], cur + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dfs(arr[0], 1);

	cout << answer;
	return 0;
}