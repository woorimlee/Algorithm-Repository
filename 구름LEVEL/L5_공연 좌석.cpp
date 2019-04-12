#include <iostream>
using namespace std;
int N, M, answer;
int arr[40] = { 0, };

int fib(int num);

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
			//to do
		}
		else
			length++;
	}
	if (length != 0)
		fib(length);
	cout << answer;
}
