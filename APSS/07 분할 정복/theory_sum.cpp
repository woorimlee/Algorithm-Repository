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
	
	//1 ~ n/2 + n/2 + 1 ~ n 까지 두 부분으로 쪼개고,
	//1 ~ n까지의 합 꼴로 나타내기 위해 우항을 다음과 같이 치환
	// (n/2 + 1) + (n/2 + 2) + ... (n/2 + n/2) -> (1 + 2 + ... n/2) + n/2 * n/2
	// 즉 1 ~ n 까지의 합은 2 * f(n/2) + n^2/4

	if (num == 1) return 1;
	if (num % 2 == 1) //홀수일 땐 -1 한 값인 짝수까지 구하고 n 더해줌
		return (devideSum(num - 1) + num);
	
	return (devideSum(num / 2)*2 + (num / 2)*(num / 2));
}

void main() {
	int n;
	cin >> n;

	cout << "reculsive : " << reculsiveSum(n) << "\n";
	cout << "devide : " << devideSum(n) << "\n";

}