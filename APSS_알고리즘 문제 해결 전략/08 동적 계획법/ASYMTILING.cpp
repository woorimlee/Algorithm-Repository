/*
��� 1 : ��ü Ÿ�ϸ� - ��Ī���� Ÿ�ϸ� �� ��
��Ī�� ���� :	1. n�� ¦���� ���
					1-1. n/2 ����� ��� ��Ī�� ��� (����� 2*1 ���η� ä����)
					1-2. n/2 - 1 ����� ��� ��Ī�� ��� (����� 1 * 2 ���η� ä����)
				2. n�� Ȧ���� ��� n/2 -

��� 2 : ���Ī Ÿ�� �� ���� ����
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

//��� 1
int asymmetric_ver1(int width) {
	int ret;
	if (width % 2 == 1) {
		ret = tiling(width) - tiling(width / 2) + MOD;
		return ret % MOD;
	}
	else {
		ret = (tiling(width) - tiling(width / 2) + MOD) % MOD;
		ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
		return ret;
	}
}

//��� 2
int asymmetric_ver2(int width) {
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n + 1], -1);
		cout << asymmetric_ver1(n) << "\n";
	}
	return 0;
}