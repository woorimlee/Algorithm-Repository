#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int temp = 0;

	string str;
	for (int i = 1; i <= B; i++) {
		str = "";
		temp = i;
		//�ߺ� ���ڰ���� ���� �־ �� a�� b���� z���� ����س��� ���¶�� �ϸ�,
		//�������� aa, �̷� ������ �ٸ� ���ڸ� ����� �� �ְ� �����ؾ���.
		while (temp > 0) {
			str += (char)(temp % 26 + 'a');
			temp /= 26;
		}
		cout << str << " ";
	}
	cout << "\n";
	return 0;
}