#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int MAX_K = 1000000000 + 100;
int C, k;
int skip;

//��Ž n���� ������ m���� ������ �̿��� s�� �����
void generate_signal(int n, int m, string s);

//���� ����� ���հ� �Ľ�Į �ﰢ��, dp�� �̿��� Ǯ��
int bino[201][201];
void calc_bino();
void generate_signal2(int n, int m, string s);

//bino�� ������ ������ �̿��� ��ȭ�� Ǯ��
//kth : �� ��° ��
string kth_signal(int n, int m, int kth);

int main() {
	cin >> C;
	fill(&bino[0][0], &bino[200][201], 0);
	calc_bino();
	while (C--) {
		int n, m;
		cin >> n >> m >> k;
		skip = k;
		//generate_signal(n, m, "");
		//generate_signal2(n, m, "");
		cout << kth_signal(n, m, k) << "\n";
	}
	return 0;
}

void generate_signal(int n, int m, string s) {
	if (skip <= 0)
		return;
	if (n == 0 && m == 0) {
		skip--;
		if (skip == 0)
			cout << s << "\n";
		return;
	}

	if (n > 0)
		generate_signal(n - 1, m, s + "-");
	if (m > 0)
		generate_signal(n, m - 1, s + "o");
}

void calc_bino() {
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(MAX_K, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

void generate_signal2(int n, int m, string s) {
	if (skip <= 0)
		return;
	if (n == 0 && m == 0) {
		skip--;
		if (skip == 0)
			cout << s << "\n";
		return;
	}

	if (bino[n+m][m] < skip) {
		skip -= bino[n + m][m];
		return;
	}

	if (n > 0)
		generate_signal2(n - 1, m, s + "-");
	if (m > 0)
		generate_signal2(n, m - 1, s + "o");
}

string kth_signal(int n, int m, int kth) {
	if (n == 0) 
		return string(m, 'o');
	
	if (kth <= bino[n - 1 + m][n-1])
		return "-" + kth_signal(n - 1, m, kth);
	else
		return "o" + kth_signal(n, m - 1, kth - bino[n - 1 + m][n-1]);
}