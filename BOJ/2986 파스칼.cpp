#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	//N이 소수인지 아닌지 찾을 때, 
	//x는 2부터 시작해서 x의 제곱이 N을 초과하는 순간
	//그 수는 소수라고 판단함.
	//즉, 소수가 아니라면 x=2부터 시작해서 x의 제곱이 N 이하일 때까지만 검사하면 약수는 나옴.
	for (int i = 2; i*i <= N; i++) {
		if (N % i == 0) {
			cout << (N - (N/i));
			return 0;
		}
	}
	cout << N - 1;
	return 0;
}