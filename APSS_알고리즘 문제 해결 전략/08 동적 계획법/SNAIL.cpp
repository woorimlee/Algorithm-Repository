/*
Ȯ�� ������ dp��
������ m�� ���� ��� Ȯ�� 75%
�� ���� h(������ ���� ��ġ) + 2, �� ���� h + 1
m�� ���� ������ �������� h�� n���� ū ����� �� / 2^m == ��
*/

#include <iostream>

#define MAX_M 1001

using namespace std;

int C;
int n, m;

double cache[MAX_M * 2][MAX_M];	//MAX_M * 2 : ����
								//MAX_M : Day

//sanil_percentage
double snail_per(int h, int d) {
	if (d == m)
		return h >= n ? 1.0 : 0.0;

	double& ret = cache[h][d];
	if (ret != -1)
		return ret;

	ret = (0.75 * snail_per(h + 2, d + 1)) + (0.25 * snail_per(h + 1, d + 1));
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> n >> m;
		fill(&cache[0][0], &cache[m * 2][m + 1], -1);
		cout << fixed;
		cout.precision(10);
		cout << snail_per(0, 0) << "\n";
	}
	return 0;
}