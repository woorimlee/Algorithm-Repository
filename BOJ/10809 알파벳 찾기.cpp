#include <iostream>
#include <string>

#define alphabet 26

using namespace std;

int main() {
	//������ ���϶�� �׳� char�迭 ��
	char ans[alphabet] = { 0 };
	//�迭 -1�� ä���
	fill_n(ans, alphabet, -1);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		//ó�� �Էµ� ��ġ�� ����ص� ����. 
		//�迭�� -1�̸� ���� �ܾ �Էµ� ���� ���� ��Ȳ
		if(ans[str[i]-'a'] == -1)
			//�ܾ��� ��ġ�� �迭�� ����
			ans[str[i] - 'a'] = i;
	}
	for (int i = 0; i < alphabet; i++) {
		//char �迭�� �����ص� ���¶� ����� �� int�� ��ȯ
		cout << (int)ans[i] << " ";
	}

	return 0;
}