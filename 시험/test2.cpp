#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int R, S; //R = ����, S = ����
	cin >> R >> S;
	//�迭 �Է¹���
	vector <string> photo;
	photo.resize(R + 1);
	for (int i = 0; i < R; i++) cin >> photo[i];
	//������ �� ������ �Ÿ��� ���
	int gnd = 0;
	int dis = 300000;
	//�� ������ �Ÿ��� ���
	for (int i = 0; i < S; i++) {
		for (int j = R-1; j >= 0; j--) {
			if (photo[j][i] == '#') gnd = j;
			else if (photo[j][i] == 'X') {
				dis = min(dis, gnd - j - 1);
				break;
	}	}	}
	//���� ������ ���ؼ� �����
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (photo[j][i] == 'X') {
				photo[j+dis][i] = 'X';
				photo[j][i] = '.';
	}	}	}
	for (int i = 0; i < R; i++) 
		cout << photo[i] << "\n";
	return 0;
}