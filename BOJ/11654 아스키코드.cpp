#include <iostream>
#include <string>

using namespace std;

int main() {
	int ans = 0;
	string str;
	//������ ���Ե� �� ���� �Է¹޴� ���
	getline(cin, str, '\n');
	//str.front�� str.back�� �� str�� empty���¸� �� ��
	while (!str.empty()) {	//while�� �� ���� 14��, 20��, 25��° �ٺ��͸� ���� if(!str.empty())�� �����൵ �� 
		//�� ó�� ���� ����
		if (str.front() == ' ') {
			str.erase(str.begin());
			continue;
		}
		
		//�� ������ ���� ����
		if (str.back() == ' ') {
			str.erase(str.end() - 1);
			continue;
		}
		
		//find�� ã�� ������ ��ġ�� ��ȯ��
		size_t pos = str.find(' ');
		while (pos != string::npos) {
			ans++;
			//ã�� ��ġ �������� ã�ƶ�
			pos = str.find(' ', pos + 1);
		}
		ans++;
		break;
	}
	cout << ans;
	return 0;
}