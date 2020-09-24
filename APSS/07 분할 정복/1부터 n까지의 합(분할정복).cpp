#include <iostream>
using namespace std;

// 1���� n ������ ��

//1. ��� ��� --> O(N)
int reculsiveSum(int num) {

	if (num == 1) return 1;
	num += reculsiveSum(num - 1);

	return num;
}

//2. ���� ���� ��� --> O(lgN)
int devideSum(int num) {
	
	//1 ~ n/2 + n/2 + 1 ~ n ���� �� �κ����� �ɰ���,
	//1 ~ n������ �� �÷� ��Ÿ���� ���� ������ ������ ���� ġȯ
	// (n/2 + 1) + (n/2 + 2) + ... (n/2 + n/2) -> (1 + 2 + ... n/2) + n/2 * n/2
	// �� 1 ~ n ������ ���� 2 * f(n/2) + n^2/4

	if (num == 1) return 1;
	if (num % 2 == 1) //Ȧ���� �� -1 �� ���� ¦������ ���ϰ� n ������
		return (devideSum(num - 1) + num);
	
	return (devideSum(num / 2)*2 + (num / 2)*(num / 2));
}

void main() {
	int n;
	cin >> n;

	cout << "reculsive : " << reculsiveSum(n) << "\n";
	cout << "devide : " << devideSum(n) << "\n";

}