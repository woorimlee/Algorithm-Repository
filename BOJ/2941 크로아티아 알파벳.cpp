#include <iostream>
#include <string>

using namespace std;

int main() {
	int ans = 0;
	string str;
	cin >> str;

	//�������� ����ó���� ������.
	//������ ���°� �ξ� �ڵ�� ����� �� ����.
	for (int i = 0; i < str.length(); i++) {
		//(i-1) >= 0�� �� ���൵ �� �� ������ Ȥ�ø��� ����
		if (str[i] == '-' && (i - 1) >= 0) {
			//c- || d-�� ��� c�� d�϶� �̹� �ܾ� ���� 1 ������������ �ƹ��͵� ���ϰ� ���� �ܾ� �˻����
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
				continue;
		}
		else if (str[i] == '=' && (i - 1) >= 0) {
			if (str[i - 1] == 'c' || str[i - 1] == 's')
				continue;
			//dz=���� �˻��ϰ� z=�� �˻��ؾ���.
			else if ((i - 2) >= 0 && str[i - 1] == 'z' && str[i - 2] == 'd') {
				ans--;
				continue;
			}	
			else if (str[i - 1] == 'z')
				continue;
		}
		//j�� �׳� �ܾ��ϼ��� ������ ���� �ܾ���� �� ���� ���� �˻��ؾ���
		else if (str[i] == 'j' && (i - 1) >= 0 && (str[i - 1] == 'l' || str[i - 1] == 'n')) {
				continue;
		}
		//�⺻������ ��� �ܾ �ϳ��� ����ϴµ�, ���� ����� ũ�ξ�Ƽ�� ���ĺ��̸� ���� if ~ else if ������ ������
		else
			ans++;
	}
	cout << ans;
	return 0;
}