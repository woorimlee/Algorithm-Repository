#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, answer = 0;
	int Highest = 0;
	vector<int> vec;

	for (int i = 1; i <= 10; i++) {
		//�׽�Ʈ ������ �ʱ�ȭ
		answer = 0;
		cin >> N;
		vec.clear();
		vec.resize(N + 1);

		//���Ϳ� N���� ���� ���� �������.
		for (int j = 0; j < N; j++) {
			cin >> vec[j];
			if (j >= 4) {
				//�˻��� ���� ���� ���� �� �� ������ ������ �� �� �������� ���� ���� ū ���� ã��
				//�װ� �� �ٽ� ���� ū ���� ã�Ƽ�
				Highest = max(max(vec[j - 4], vec[j - 3]), max(vec[j - 1], vec[j])); 
				//�˻��� �����̶� ��
				if (vec[j - 2] > Highest)
					answer += vec[j - 2] - Highest;
			}
		}

		cout << "#" << i << " " << answer << "\n";
	}

}