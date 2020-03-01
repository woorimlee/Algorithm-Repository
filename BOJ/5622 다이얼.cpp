#include <iostream>
#include <string>

using namespace std;

int time = 0;
//A���� Z���� ���̾� �ɸ��� �ð� �����ص� �迭
int alphabet[26];
string str;

int main() {
	cin >> str;
	int j = 0;
	//A,B,C ���� �� ���ĺ��� �� ��Ʈ�� ��� M,N,O����
	for (int i = 0; i < 15; i+=3) {
		alphabet[i] = 3 + j;
		alphabet[i + 1] = 3 + j;
		alphabet[i + 2] = 3 + j;
		j++;
	}
	//P, Q, R, S �� ����
	for (int i = 0; i < 4; i++) {
		alphabet[15 + i] = alphabet[14] + 1;
	}
	//T, U, V �� ����
	for (int i = 0; i < 3; i++) {
		alphabet[19 + i] = alphabet[18] + 1;
	}
	//W, X, Y, Z �� ����
	for (int i = 0; i < 4; i++) {
		alphabet[22 + i] = alphabet[21] + 1;
	}
	/* �迭 �� Ȯ��
	for(int i = 0 ; i < 26; i++) {
		cout << alphabet[i] << " " ;
	}
	*/
	//�Է¹��� ���ڿ� �ش��ϴ� alphabet �迭 ���� �ɸ��� �ð���. 
	//�� ���ؼ� ����ϸ� ��.
	for (int i = 0; i < str.size(); i++) {
		//str[0] == A��� �ϸ�,
		//str[0] - 'A' --> 'A' - 'A' == 0
		//���� A�� 0��° �ε����� ���� ��
		time += alphabet[str[i] - 'A'];
	}
	cout << time;
	return 0;
}