#include <iostream>
#include <vector>

using namespace std;

int N;

//�� �Ҽ��� �ϳ����� �ִ� ���տ���
//���ӵ� ���ҵ��� ���� ���ϴ� ���̴�
//Two pointer�� ����ϸ� ��.
//1. �ߺ� ���� �Ҽ� ���� ���� ���� (N ����)
//2. ���ӵ� ������ �κ� ���� N�� ���� ã���� ����� ��(answer) ++.
int main(void) {
	ios::sync_with_stdio(false);

	cin >> N;

	//false�� �ʱ�ȭ �� N���� ���Ҹ� ���� ���� vec
	vector <bool> vec(N + 1, false);
	vector <int> decimal;

	//vec���� �Ҽ��� �ƴ� ���� true�� �ٲ۴�.
	for (long long i = 2; i <= N; i++) {
		if (vec[i] == false) {
			for (long long j = i*i; j <= N; j += i) {
				vec[j] = true;
			}
			decimal.push_back(i);
		}
	}

	//ù ��° �Ҽ��� 2
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