#include <iostream>
#include <string>

using namespace std;

int time = 0;
//A부터 Z까지 다이얼 걸리는 시간 저장해둘 배열
int alphabet[26];
string str;

int main() {
	cin >> str;
	int j = 0;
	//A,B,C 같이 세 알파벳을 한 세트로 묶어서 M,N,O까지
	for (int i = 0; i < 15; i+=3) {
		alphabet[i] = 3 + j;
		alphabet[i + 1] = 3 + j;
		alphabet[i + 2] = 3 + j;
		j++;
	}
	//P, Q, R, S 값 저장
	for (int i = 0; i < 4; i++) {
		alphabet[15 + i] = alphabet[14] + 1;
	}
	//T, U, V 값 저장
	for (int i = 0; i < 3; i++) {
		alphabet[19 + i] = alphabet[18] + 1;
	}
	//W, X, Y, Z 값 저장
	for (int i = 0; i < 4; i++) {
		alphabet[22 + i] = alphabet[21] + 1;
	}
	/* 배열 값 확인
	for(int i = 0 ; i < 26; i++) {
		cout << alphabet[i] << " " ;
	}
	*/
	//입력받은 문자에 해당하는 alphabet 배열 값은 걸리는 시간임. 
	//다 더해서 출력하면 됨.
	for (int i = 0; i < str.size(); i++) {
		//str[0] == A라고 하면,
		//str[0] - 'A' --> 'A' - 'A' == 0
		//문자 A를 0번째 인덱스로 쓰는 중
		time += alphabet[str[i] - 'A'];
	}
	cout << time;
	return 0;
}