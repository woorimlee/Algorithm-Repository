#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C;
char cache[19683];

//turn�� �ְ� �̰����� 1, ������ �� �ؾ��ϸ� 0
bool isFinished(string nb, char t) {
	//����
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = i * 3 + j;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 1;
		}
	}
	//����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = j * 3 + i;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 1;
		}
	}
	//�밢�� ���� �� -> ������ �Ʒ�
	for (int i = 0; i <= 8; i += 4) {
		if (nb[i] != t)
			break;
		if (i == 8)
			return 1;
	}
	//�밢�� ������ �� -> ���� �Ʒ�
	for (int i = 2; i <= 6; i += 2) {
		if (nb[i] != t)
			break;
		if (i == 6)
			return 1;
	}

	return 0;
}

int nb_to_int(const string& nb) {
	int n = 0;
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			n = n * 3;
			idx = i * 3 + j;
			if (nb[idx] == 'o') 
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
	if (isFinished(now_b, 'o' + 'x' - turn)) //true : ���� turn�̾��� �ְ� �̱�
		return -1;

	//now_b -> int ������ ��ȯ
	char& ret = cache[nb_to_int(now_b)];
	if (ret != -2)
		return ret;

	ret = 2; //��� �� ä���� �� TIE�� isFinished�� �˻簡 �ȵ�. -> ret == 2�� ����
	for (int i = 0; i < 3; i++) { //���� ����� �� �˻�
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (now_b[idx] == '.') {
				now_b[idx] = turn;
				ret = min(ret, game_result(now_b, 'o' + 'x' - turn)); //-1�� ���ϵǸ� turn�ξְ� �̱� �� �ִٴ� ��.
				//�켱���� : �ڱⰡ �̱� > ��� > ��밡 �̱�
				now_b[idx] = '.';
			}
		}
	}

	if (ret == 0 || ret == 2)
		return ret = 0; // �̰� ������
	else
		return ret = -ret; // �̰� ������
}

int main() {
	cin >> C;
	while (C--) {
		string board = "";
		string s;
		int cnt_dot = 0;
		for (int i = 0; i < 3; i++) {
			cin >> s;
			for (int j = 0; j < s.size(); j++) //�� ���� �ľ�
				if (s[j] == '.')
					cnt_dot++;
			
			board += s; //���� �� �Է¹ޱ�
		}
		fill(&cache[0], &cache[19683], -2);
		
		/*board = "...xx.oo."
		board�� 9�ڸ��� 3������ ���� 3^9 = 19683
		cache[ƽ�������] ==	1	: �ڱⰡ �̱�
								0	: ��� 
								-1	: ��밡 �̱� 
		*/

		char first_turn;
		if (cnt_dot % 2)
			first_turn = 'x';
		else
			first_turn = 'o';
		
		char res = game_result(board, first_turn);
		if (res == 1)
			cout << first_turn << "\n";
		else if (res == -1)
			cout << (char)('o' + 'x' - first_turn) << "\n";
		else if (res == 0)
			cout << "TIE\n";
		else
			cout << "ERROR\n";
	}
	return 0;
}