#include <iostream>
#include <vector>
using namespace std;

//10,000 ������ �ڿ����� ���� < 100,000 �������� �� ������ ���!
//���� ������ ���� int���� ��� vector �ϳ��� �����ؼ�
//�� ���� int�� ������ left, right�� ������ ������ �����ϰ� �Ѵ�.

int N, S;

int main(void) {
	ios::sync_with_stdio(false);
	
	//���� ���� N, �κ� ������ ������ ���� �� S
	cin >> N >> S;

	vector <int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	//N�� 100,000�����ϱ� ���ϰ� answer�� 100,001�� ������.
	int sum = vec[0], answer = 100001;
	int left = 0, right = 0;

	//�� ������ �˰��� ������. ������ �ϳ� ���� ��߽�Ű��(right), ������ �ϳ��� ���󰡰�(left)
	while (right < N && left <= right) {
		if (sum < S) {
			right++;
			//�� �̻� �˻��� ���Ұ� ����
			if (right >= N) break;

			sum += vec[right];
		}
		
		//���� S�̻� �Ǵ� �� ��, ���� ª�� �� ����
		else if (sum == S) {
			int temp = (right - left) + 1;
			if (answer > temp) answer = temp;
			right++;
			sum += vec[right];
		}

		else if(sum > S) {
			int temp = (right - left) + 1;
			if (answer > temp) answer = temp;

			sum -= vec[left];
			left++;
			
			//left�� +1 ���״��� right�� ��ġ�� �Ѿ�ٸ�
			if (left > right && left < N) {
				//�ʱ�ȭ.
				right = left;
				sum = vec[right];
			}
		}

	}

	if (answer == 100001) answer = 0;
	cout << answer << endl;

	return 0;
}