#include <iostream>
#include <string>

using namespace std;

int N, ans=0;
bool check[26] = { false };

bool group_word_check(string &str) {
	//�� ó�� ���ڴ� true�� �����ϰ� ���� ���ں��� �˻� ����
	check[str[0] - 'a'] = true;
	for (int i = 1; i < str.length(); i++) {
		//���� ���ڿ� ���� ���ڰ� �ٸ� ��Ȳ�ε�
		//���� ������ bool �迭 ���� true�� ������ ���� �� �ִ� �ܾ�
		if (str[i] != str[i - 1] && check[str[i] - 'a']) {
			return false;
		}
		//������ ��쿡�� �׳� ���� �ܾ��� bool �迭�� true�� �������
		check[str[i] - 'a'] = true;
	}
	//�� for ������ ������ ����ϸ� ����� ���� �ߺ� �ܾ�� ���� ����
	return true;
}

int main() {
	cin >> N;
	string str;
	while (N--) {
		cin >> str;
		//�� ���ึ�� bool �迭 false�� �ʱ�ȭ
		fill_n(check, 26, false);
		//���� �˻��ؼ� ���� ��� �� ����
		if (group_word_check(str)) {
			ans++;
		}
	}
	cout << ans;
}