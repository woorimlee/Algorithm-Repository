#include <iostream>
using namespace std;

// 1부터 n 까지의 합

//1. 재귀 방식 --> O(N)
int reculsiveSum(int num) {

	if (num == 1) return 1;
	num += reculsiveSum(num - 1);

	return num;
}

//2. 분할 정복 방식 --> O(lgN)
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