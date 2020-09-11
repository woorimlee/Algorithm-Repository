#include <iostream>

using namespace std;
unsigned const int max_n = 987654321;

//Unsigned 32��Ʈ ������ ���� �̸� �Ҽ� ���θ� ���� ���·� �����ص�.
//UINT32_MAX �� ���� bite�� �ɰ� �迭�� ������ ��.
//[x]�� i��° ��Ʈ�� 1�̸� �Ҽ��� �ƴ�. 0�̸� �Ҽ�
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