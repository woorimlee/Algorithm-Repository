#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C;
char cache[19683];

//turn�� �ְ� �̰����� 2, ������� 1, ������ �� �ؾ��ϸ� 0
char isFinished(string nb, char t) {
	//����
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = i * 3 + j;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 2;
		}
	}
	//����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = j * 3 + i;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 2;
		}
	}
	//�밢�� ���� �� -> ������ �Ʒ�
	for (int i = 0; i <= 8; i += 4) {
		if (nb[i] != t)
			break;
		if (i == 8)
			return 2;
	}
	//�밢�� ������ �� -> ���� �Ʒ�
	for (int i = 2; i <= 6; i += 2) {
		if (nb[i] != t)
			break;
		if (i == 6)
			return 2;
	}

	//��� �˻�.
	//1�̸� ���, ������ �� �ؾ��ϸ� 0�� return;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = i * 3 + j;
			if (nb[i] == '.')
				return 0;
		}
	}
	return 1;
}

int nb_to_int(const string& nb) {
	int n = 0;
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			n = n * 3;
			idx = i * 3 + j;
			if (nb[idx] == '0') 
				n++;
			else if (nb[idx] == 'x')
				n += 2;
		}
	}
	return n;
}

//now_b = now_board. ���� ������ ����
//turn = ���� ����?
char game_result(string& now_b, char turn) { //�� ���¿��� ������ ����� return.
	//base case
	char check = isFinished(now_b, turn);
	if (check == 2)
		return 0;
	if (check == 1)
		return 1;

	//nb -> int�� ��ȯ
	char& ret = cache[nb_to_int(now_b)];
	//���ο� ���带 ���� ����� ��
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (now_b[idx] == '.') {
				now_b[idx] = turn;
				//�̱� �� ������ �̱��, �ƴϸ� ����, �ƴϸ� ������.
				ret = max(ret, game_result(now_b, 'o' + 'x' - turn));
				now_b[idx] = '.';
			}
		}
	}
	if (ret == 0)  //���� ���ξְ� ������
		return ret = 2;
	else if (ret == 2)
		return ret = 0;
	else 
		return ret;
}

int main() {
	cin >> C;
	fill(&cache[0], &cache[19683], -1);
	while (C--) {
		string board = "";
		string s;
		for (int i = 0; i < 3; i++) {
			cin >> s;
			board += s;
		}
		/*board = "...xx.oo."
		board�� 9�ڸ��� 3������ ���� 3^9 = 19683
		cache[ƽ�������] == 2 : ���� turn�� �ְ� �̱�, 1 : ���, 0 : �ٸ��ְ� �̱�
		*/
		char res = game_result(board, 'o');
		if (res == 2)
			cout << "o\n";
		else if (res == 1)
			cout << "TIE\n";
		else if (res == 0)
			cout << "x\n";
		else
			cout << "error\n";
	}
	return 0;
}