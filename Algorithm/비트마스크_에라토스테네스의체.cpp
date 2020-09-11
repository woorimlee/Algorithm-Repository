#include <iostream>

using namespace std;
unsigned const int max_n = 987654321;

//Unsigned 32비트 정수에 대해 미리 소수 여부를 집합 형태로 저장해둠.
//UINT32_MAX 이 값을 bite로 쪼갠 배열에 저장할 것.
//[x]의 i번째 비트가 1이면 소수가 아님. 0이면 소수
unsigned char sieve[(max_n + 7) / 8];

bool isPrime(int n) {
	return sieve[n >> 3] & (1 << (n & 7));
}

void eratosthenes() {
	int sqrtn = int(sqrt(max_n));
	for (unsigned int i = 2; i <= sqrtn; i++) {
		if (isPrime(i) == 0) {
			for (unsigned int j = i * i; j <= max_n; j+=i) {
				//sieve[(j / 8)] |= (1 << (j%8))
				sieve[j >> 3] |= (1 << (j & 7));
			}
		}
	}
}
int main() {
	eratosthenes();
	cout << isPrime(7) << "\n";
	cout << isPrime(2) << "\n";
	cout << isPrime(6) << "\n";
	cout << isPrime(27644437) << "\n";
	return 0;
}