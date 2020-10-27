#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C;
char cache[19683];

//turn인 애가 이겼으면 2, 비겼으면 1, 게임을 더 해야하면 0
char isFinished(string nb, char t) {
	//가로
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
	//세로
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = j * 3 + i;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 2;
		}
	}
	//대각선 왼쪽 위 -> 오른쪽 아래
	for (int i = 0; i <= 8; i += 4) {
		if (nb[i] != t)
			break;
		if (i == 8)
			return 2;
	}
	//대각선 오른쪽 위 -> 왼쪽 아래
	for (int i = 2; i <= 6; i += 2) {
		if (nb[i] != t)
			break;
		if (i == 6)
			return 2;
	}

	//비김 검사.
	//1이면 비김, 게임을 더 해야하면 0을 return;
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

//now_b = now_board. 현재 보드의 상태
//turn = 누구 차례?
char game_result(string& now_b, char turn) { //이 상태에서 게임의 결과를 return.
	//base case
	char check = isFinished(now_b, turn);
	if (check == 2)
		return 0;
	if (check == 1)
		return 1;

	//nb -> int로 변환
	char& ret = cache[nb_to_int(now_b)];
	//새로운 보드를 만들 경우의 수
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (now_b[idx] == '.') {
				now_b[idx] = turn;
				//이길 수 있으면 이기고, 아니면 비기고, 아니면 진거지.
				ret = max(ret, game_result(now_b, 'o' + 'x' - turn));
				now_b[idx] = '.';
			}
		}
	}
	if (ret == 0)  //다음 턴인애가 졌으면
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
		board를 9자리의 3진수로 보자 3^9 = 19683
		cache[틱택토상태] == 2 : 현재 turn인 애가 이김, 1 : 비김, 0 : 다른애가 이김
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