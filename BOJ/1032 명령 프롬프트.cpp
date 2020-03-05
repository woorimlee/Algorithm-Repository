#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_file_name(vector <string> & sv, int index) {
	char temp = sv[0][index];
	for (int j = 0; j < sv.size(); j++) {
		if (temp != sv[j][index])
			return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector <string> sv; // str_vector
	sv.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> sv[i];
	}
	//���� �������� �˻��� ����.
	//ù ��° ������ ���ڿ� ���̸�ŭ ������
	for (int i = 0; i < sv[0].length(); i++) {
		//�� ��° ����(check_file_name �Լ�)�� �Է¹��� ������ ������ŭ ����
		//check_file_name �Լ��� �Է¹��� ���ڵ��� i ��° �ε��� ����
		//��� �����ϸ� true�� �����ϰ�,
		//�ϳ��� �ٸ��� false�� �����ϴ� bool���� �Լ�.
		if (check_file_name(sv, i)) {
			cout << sv[0][i];
		}
		else {
			cout << "?";
		}
	}
	return 0;
}