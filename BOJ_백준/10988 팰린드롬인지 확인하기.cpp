#include <iostream>
#include <string>

using namespace std;

string str;


int main() {
	//str�� �ҹ��ڷ� �̷���
	cin >> str;
	//�־��� ���ڿ��� �� �հ� �ڸ� ���ÿ� Ȯ���� ����
	int tail = str.size();
	for (int head = 0; head < str.size()/2; head++) {
		tail--;
		//head�� ���ڿ��� �տ�������,
		//tail�� ���ڿ��� �ڿ������� 
		//���� ���ڿ��� �˻��� ����.
		//�� ���ڰ� �ٸ��ٸ� 0�� ����ϰ�
		if (str[head] != str[tail]) {
			cout << 0;
			return 0;
		}
		//for ������ ������ ����ϸ� 1�� �����
	}
	cout << 1;
	return 0;
}