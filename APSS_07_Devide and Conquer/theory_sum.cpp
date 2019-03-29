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
	
	if (num == 1) return 1;
	if (num % 2 == 1) 
		return (devideSum(num - 1) + num);
	
	return (devideSum(num / 2)*2 + (num / 2)*(num / 2));
}

void main() {
	int n;
	cin >> n;

	cout << "reculsive : " << reculsiveSum(n) << "\n";
	cout << "devide : " << devideSum(n) << "\n";

}