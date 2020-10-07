#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int answer = 0;
	vector <char> rod;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') rod.push_back(str[i]);
		else if (str[i] == ')') {
			//���� ���������
			if (str[i - 1] == '(') {
				rod.pop_back();
				answer += rod.size();
			}
			//�踷��� ������ �ϳ� ����
			else {
				rod.pop_back();
				answer += 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}