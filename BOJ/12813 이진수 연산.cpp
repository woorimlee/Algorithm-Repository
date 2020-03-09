#include <iostream>
#include <cstdio>
#define BITSIZE 100000

using namespace std;

char A[BITSIZE+1], B[BITSIZE+1];

char AND[BITSIZE+1] = { 0, };
char OR[BITSIZE+1] = { 0 };
char XOR[BITSIZE+1] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
		
	cin >> A >> B;
	for (int i = 0; i < BITSIZE; i++) {
		//A�� B�� �ִ� '0'�� '1'�� ���� 0, 1�� �ٲ㼭 ��Ʈ �����ϰ� �ٽ� char���� '0'�� '1'�� �ٲ�
		AND[i] = ((A[i] - '0') & (B[i] - '0')) + '0';
		OR[i] = (A[i] - '0') | (B[i] - '0') + '0';
		XOR[i] = (AND[i] != OR[i]) ? '1' : '0';
		A[i] = !(A[i] - '0') + '0';
		B[i] = !(B[i] - '0') + '0';
	}
	//����� �迭�� �̸�����(AND==&AND[0]) �ϰ� ������ �� ���� ���� ���� �ϳ� �־�־� ��.
	cout << AND << "\n";
	cout << OR << "\n";
	cout << XOR << "\n";
	cout << A << "\n";
	cout << B;

	return 0;
}