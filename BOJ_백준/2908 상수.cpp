#include <iostream> 
#include <string>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	string rA = ""; //reverse A
	string rB = ""; //reverse B
	//rA�� rB�� �Է¹��� �� ����(string����)�� �� �� ���ں���
	//������ ������ string��
	for (int i = A.length() - 1; i >= 0; i--) {
		rA += A[i];
		rB += B[i];
	}
	//stoi : string�� int�� �ٲٱ�
	//�ٲ� �� �� �� ó������ �Էµ� ���� �� ũ�ٸ� ó�� �� ���
	//�ƴϸ� �� ��° �� ���
	cout << (stoi(rA) > stoi(rB) ? rA : rB) << "\n";
	return 0;
}