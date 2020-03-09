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
		//A와 B에 있는 '0'과 '1'을 숫자 0, 1로 바꿔서 비트 연산하고 다시 char형인 '0'과 '1'로 바꿈
		AND[i] = ((A[i] - '0') & (B[i] - '0')) + '0';
		OR[i] = (A[i] - '0') | (B[i] - '0') + '0';
		XOR[i] = (AND[i] != OR[i]) ? '1' : '0';
		A[i] = !(A[i] - '0') + '0';
		B[i] = !(B[i] - '0') + '0';
	}
	//출력을 배열의 이름으로(AND==&AND[0]) 하고 있으니 맨 끝에 여유 공간 하나 넣어둬야 함.
	cout << AND << "\n";
	cout << OR << "\n";
	cout << XOR << "\n";
	cout << A << "\n";
	cout << B;

	return 0;
}