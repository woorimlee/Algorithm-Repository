#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	//��� 1. ť�� �迭�� �̿��� �˰����� ����
	//��� 2. ������ ������ Ư���� ���캸�� ������ ����

	//��� 2 Ǯ�̹�
	//���������� ���� ���� 2^x <= N < 2^(x+1) ����
	//x�� ���ϱ� ���ؼ� N�� log2 ������ �ϰ� 2�� ���� �÷� ����� ��.
	cout << pow(2, int(log2(N)));

	return 0;
}