#include <iostream>
#include <string>

using namespace std;

//alphabet �迭�� 0��° �ε����� D�� ����.
//... 25��° �ε����� C�� ����.
char alphabet[26];
string str;

int main() {
	cin >> str;
	//D���� Z�� �ش��ϴ� �ε����� ���ĺ� A���� W���� ����
	for (int i = 3; i < 26; i++) {
		alphabet[i] = 'A' + i - 3;
	}
	//A���� C�� �ش��ϴ� �ε����� ���ĺ� X���� Z���� ����
	for (int i = 0; i < 3; i++) {
		alphabet[i] = 'X' + i;
	}
	/*�迭 Ȯ�ο� �ڵ�
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	*/
	for (int i = 0; i < str.size(); i++) {
		//str�� MRL�̶�� �ϸ�,
		//str[i]���� M, R, L�� ����ְ�
		//i == 0�� ��, str[0] == 'M'
		//���� M�� �ε��� ���� 'M' - 'A' ��. (���� A�� �ε��� ���� 'A' - 'A'�� 0)
		cout << alphabet[str[i] - 'A'];
	}
	return 0;
}