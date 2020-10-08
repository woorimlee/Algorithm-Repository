/*
tiling(n) = 2 * n ũ���� �簢���� Ÿ�Ϸ� ���� �� �ִ� ����� ���� return

int tiling(n) { n�� ���� cache ó��
	base case	1) cache Ȯ��
				2) n == 0�϶� return 1;
				3) n < 0�϶� return 0;
				--> �� ���� ��� n <= 1�� �� return 1
	return tiling(n - 1) + tiling( n - 2); 
	//n-1 : ���η� Ÿ�� ����
	//n-2 : ������ Ÿ�� �� ���� �� �Ʒ��� ���� �簢�� ����
*/

#include <iostream>

using namespace std;

int C, n;
int MOD = 1000000007;
int cache[101];

int tiling(int size) {
	if (size <= 1) return 1;
	int& ret = cache[size];
	if (ret != -1) return ret;
	
	ret = tiling(size - 1) + tiling(size - 2);
	return (ret %= MOD);
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n+1], -1);
		cout << tiling(n) << "\n";
	}
	return 0;
}