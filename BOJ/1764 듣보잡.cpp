#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M, ans = 0;
//bool ���� true�� �赵 ���ϰų� ���� ���� ��� (�� �� �ϳ�)
//bool ���� false�� �躸��
//map�� �⺻ false�� �ʱ�ȭ
map <string, bool> emeqh; //�躸 = emeqh
int main() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N + M; i++) {
		cin >> str;
		//�赵 ���� ��� Ȥ�� ���� ���� �������
		//�̸��� �� �� �־����� true�� �ٲ�
		if (emeqh[str] == false) {
			emeqh[str] = true;
		}
		//�赵 ���� ��� & ���� ���� ���
		//������� �� �� �־��� ��쿡 �ش� 
		else {
			emeqh[str] = false;
			ans++;
		}
	}
	cout << ans << "\n";
	for (auto it : emeqh) {
		if (it.second == false) {
			cout << it.first << "\n";
		}
	}

	return 0;
}