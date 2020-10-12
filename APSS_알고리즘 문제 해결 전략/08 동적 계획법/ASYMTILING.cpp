/*
��� 1 : ��ü Ÿ�ϸ� - ��Ī���� Ÿ�ϸ� �� ��
��Ī�� ���� :	1. n�� ¦���� ���
					1-1. n/2 ����� ��� ��Ī�� ��� (����� 2*1 ���η� ä����)
					1-2. n/2 - 1 ����� ��� ��Ī�� ��� (����� 1 * 2 ���η� ä����)
				2. n�� Ȧ���� ��� n/2 -

��� 2 : ���Ī Ÿ�� �� ���� ����
	1. �� ���� ��Ī�̸�, �ȿ��� ������ ���Ī
	2. �� ���� ���Ī�̸� ����.
-> 1�� 2�� ���� ������, 1�� ������ ��� return 0�� ��Ŵ.
-> 2�� ����Ǵ� ��� ������ Ÿ�� ���� ����.
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
int cache2[101];
int asymmetric_ver2(int width) {
	if (width <= 2) {
		// 2 * 1 ���η� �� �� �� �Ʒ� �� ���� ä���,
		// 1 * 2 ���η� �� �� �� ��� �� ���� ä��� ��Ī��
		return 0;
	}

	int& ret2 = cache2[width];
	if (ret2 != -1)
		return ret2;

	ret2 = asymmetric_ver2(width - 2) % MOD; // �� ���� 1 * 2 ���η� �� �� ��Ī
	ret2 = (ret2 + asymmetric_ver2(width - 4)) % MOD; 
	ret2 = (ret2 + tiling(width - 3) * 2 % MOD) % MOD;
	return ret2;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0], &cache[n + 1], -1);
		fill(&cache2[0], &cache2[n + 1], -1);
		//cout << asymmetric_ver1(n) << "\n";
		cout << asymmetric_ver2(n) << "\n";
	}
	return 0;
}