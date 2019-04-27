#include <iostream>
using namespace std;
int N, M, answer = 1;
int arr[4] = { 0, };

//fib 계산할 때 + 1 해서 넣자.
int fib(int num) {
	if (num == 1 || num == 0)
		return num;
	return fib(num - 1) + fib(num - 2);
}

int main() {
	cin >> N >> M;

	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		arr[temp - 1] = -1; // VIP좌석은 -1로 저장해둠.
	}
	
	int length = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == -1) { // VIP석
			//계산 & 초기화
			answer *= fib(length + 1);
			length = 0;
		}
		else
			length++;
	}

	if (length != 0)
		answer *= fib(length + 1);

	cout << answer;
}
