#include <iostream>
#include <string>
using namespace std;
#define alphabet 26
int main() {
	string str;
	cin >> str;
	bool flag = false; //true�� ?���
	char find_char = str[0]; //���� ���� ���� ���� �����ϱ�
	int max_num = -1; //���� ���� ���� ������ Ƚ�� �����ϱ�
	int change_char = 0; //�ҹ��ڿ� �빮���϶� ���� �ٸ� ����� �ϱ� ���ؼ�
	int ans[alphabet] = { 0 }; //���� Ƚ�� �����ص� �迭

	for (int i = 0; i < str.size(); i++) {
		//�빮�ڸ� �⺻ ����� �����ϰ�
		//�ҹ����� ��� �빮�ڷ� �ٲ�
		if ('a' <= str[i] && str[i] <= 'z')
			change_char = 'a';
		else
			change_char = 'A';

		ans[str[i] - change_char]++;
		//���� ���� ���� ���ĺ� ã��
		if (max_num == ans[str[i] - change_char]) {
			flag = true;
		}
		else if (max_num < ans[str[i] - change_char]) {
			flag = false;
			find_char = str[i] - change_char + 'A'; //ã�� ���ڸ� �빮�ڷ� �ٲٱ�
			max_num = ans[str[i] - change_char];
		}
	}
	flag ? cout << "?" : cout << find_char;
	
	return 0;
}