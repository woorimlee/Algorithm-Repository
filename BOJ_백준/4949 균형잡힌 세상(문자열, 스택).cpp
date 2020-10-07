#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

string str;

bool check_Blanced() {
	stack <char> bracket;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			bracket.push(str[i]);
		}
		else if (str[i] == ')') {
			//������ ��������� ������ �ȸ���
			//���� ���ڿ��� ���ڰ� )�ε� ������ ž ���� [�� �ұ���
			if (bracket.empty() || bracket.top() != '(')
				return false;
			bracket.pop();
		}
		else if (str[i] == ']') {
			if (bracket.empty() || bracket.top() != '[')
				return false;
			bracket.pop();
		}
	}
	//�Ʒ� ���� ó���� �� �ϸ� ((). ������ �� �ɷ���
	if (!bracket.empty()) {
		return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while (getline(cin, str)) {
		if (str==".")
			return 0;
		//�� �� �Է¹޾Ұ�,
		//( �Ǵ� [�� ���� ���ÿ� �ְ� ) �Ǵ� ]�� ���� ���� ���� ������ ���� ����.
		//������ ������ �ʾҴٸ� �ٷ� no ����ϰ�
		//���ڿ� ��� ������ Ž���ߴٸ� yes ����ϰ�
		if (check_Blanced()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}