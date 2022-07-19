#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int sequence[200001];
int cnt[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	int answer = 0;
	int lft = 0;
	for (int rgt = 0; rgt < N; rgt++) {
		cin >> sequence[rgt];
		cnt[sequence[rgt]]++;

		//���� ������� ���� �κ� �������� Ư�� ���ڰ� K �ʰ��� �ߺ��ȴٸ� 
		//left �����͸� ���������� ����
		while (cnt[sequence[rgt]] > K) {
			cnt[sequence[lft]]--;
			lft++;
		}
		answer = max(answer, rgt - lft + 1);
	}

	cout << answer;
	return 0;
}