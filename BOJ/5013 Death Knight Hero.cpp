#include <iostream>
#include <string>
using namespace std;

bool check_dc(string &ki) {
	//i��°�� i+1��°�� ���ÿ� �˻��ϴ� for �� ��° �������� -1 ����� ��.
	for (int i = 0; i < ki.length() - 1; i++) {
		//C�ڿ� D�� ���� ��쿡 ������ �Ǵ� �ſ���.
		if (ki[i] == 'C' && ki[i + 1] == 'D')
			return false;
	}
	return true;
}

int main() {
	int n, ans = 0;
	cin >> n;
	string ki;
	//n���� ������ �Է¹ް� �̰���� �˻���
	while (n--) {
		cin >> ki;
		//n��° ������ �̰���� �˻��ؼ� 
		//true�� �̱� ������, false�� �� ������ ó����.
		//���� �� �ƹ��͵� �� ��
		if (check_dc(ki)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
