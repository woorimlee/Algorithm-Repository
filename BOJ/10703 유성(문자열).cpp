#include <iostream>
#include <string>

using namespace std;

int R, S;
int dis = 3001;//dis == distance. ���� ���� ������ �Ÿ� �ּ� ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> S;
	//char �迭�� �ص� ��
	//�Ʒ��� �׳� R���� string�� ����� photo��� ������ �����ϰڴٴ� ��.
	//������ string �迭�� ��������.
	string* photo = new string[R];
	for (int i = 0; i < R; i++)
		cin >> photo[i];

	//������ �� ������ �Ÿ� ���
	int ground = 0;
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (photo[j][i] == '#') {
				//���� ��ġ�� ������ ����ص�
				ground = j;
			}
			else if (photo[j][i] == 'X') {
				//���� ������ ��ġ ������ �Ÿ��� ���ϸ�,
				//���ÿ� ���� �ּҰ� �Ǵ� �Ÿ��� ã�´�.
				dis = (dis > (ground - j - 1)) ? ground - j - 1 : dis;
				break;
			}
		}
	}

	//���� ����
	//�ּ� �Ÿ� ��ŭ ������ �Ʒ��� �̵���Ŵ
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (photo[j][i] == 'X') {
				photo[j + dis][i] = 'X';
				photo[j][i] = '.';
			}
		}
	}

	//���
	for (int i = 0; i < R; i++)
		cout << photo[i] << "\n";

	return 0;
}