#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	//N�� �Ҽ����� �ƴ��� ã�� ��, 
	//x�� 2���� �����ؼ� x�� ������ N�� �ʰ��ϴ� ����
	//�� ���� �Ҽ���� �Ǵ���.
	//��, �Ҽ��� �ƴ϶�� x=2���� �����ؼ� x�� ������ N ������ �������� �˻��ϸ� ����� ����.
	for (int i = 2; i*i <= N; i++) {
		if (N % i == 0) {
			cout << (N - (N/i));
			return 0;
		}
	}
	cout << N - 1;
	return 0;
}