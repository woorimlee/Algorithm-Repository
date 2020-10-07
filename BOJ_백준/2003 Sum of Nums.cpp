#include <iostream>
#include <vector>

using namespace std;

/*
N�� 10,000���� �����ϱ� ������ ��� ���Ҹ� �����ϰ� ������ ã�� ����� �ð� ���⵵�δ� Ǯ�� ���Ѵ�.
������ ��� ���Ұ� �ڿ�����, ������� �ϴ� �䵵 �ڿ����� Two pointer algorithm�� ����Ѵ�. (������ ���ҷ� ������ �ٸ� ��� ����Ѵ�.)
������ head �κп� ������ �� ���� �ּ� ��ġ�� ������Ű�� ���� ã�´�. (��¥ �����͸� �� �ֵ� vec�� �迭�� �ε����� ����Ű�Ը� �ϸ� �Ǵ� int �ڷ����� ����)
*/
int N, M;

int main(void) {
	ios::sync_with_stdio(false);

	cin >> N >> M; // N�� ���� ����, M�� ������� �ϴ� ��

	int answer = 0;
	//N ���� int ���� ���� vector A
	vector <int> A(N);

	for (int i = 0; i < N ; i++) {
		cin >> A[i];
	}

	//�ʱ�ȭ
	int sum = A[0];
	int left = 0, right = 0;

	//�� ������ �˰��� �������� ������ ����.
	//1. left�� right���� �۰ų� ����, right�� N ��������
	//2. sum�� M���� ������ right++, 
	while (right < N && left <= right) {
		if (sum < M) {
			right++;
			//���� ũ�⸦ �Ѱ�ٸ� �˻� ��
			if (right >= N) break;
			
			sum += A[right];
		}
		else if (sum == M) {
			answer++;
			//���� ã������ �ٽ� right ������ �ϳ� �̵�
			right++;
			sum += A[right];
		}
		else { //sum > M
			sum -= A[left];
			left++;
			//left == right ��ġ�� �Ѿ�����, left ��ġ�� �� �ʱ�ȭ.
			if (left > right) {
				right = left;
				if(left < N) sum = A[right];
			}
		}
	}
	cout << answer << endl;
	return 0;
}