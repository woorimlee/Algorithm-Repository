#include <iostream>
using namespace std;
int main() {
	int N= 1;
	long long S;
	long long sum = 0;
	cin >> S;
	//N�� �ִ��� ���ϴ� ���̴� N�� 1���� 1 + 2 + ...
	//S == 6 ~ 10 ������ ���̶�� ���� --> 
	//6 => 1 + 2 + 3
	//7 => 1 + 2 + 4
	//8 => 1 + 2 + 5
	//9 => 1 + 2 + 6
	//10 => 1 + 2 + 3 + 4
	//6~9�� N�� �ִ� 3��.
	//1���� 1�� �����ϴ� ���������� ���� S���� �Ѿ�� ���� �ִ� ��밡���� N�� �������� ������ �� - 1
	while (1) {
		sum += N;
		if (sum > S) {
			cout <<	--N;
			return 0;
		}
		N++;
	}
	return 0;
}