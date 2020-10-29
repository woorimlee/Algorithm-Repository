#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C;
char cache[19683];

//turn인 애가 이겼으면 1, 게임을 더 해야하면 0
bool isFinished(string nb, char t) {
	//가로
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
	//세로
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = j * 3 + i;
			if (nb[idx] != t)
				break;
			if (j == 2)
				return 1;
		}
	}
	//대각선 왼쪽 위 -> 오른쪽 아래
	for (int i = 0; i <= 8; i += 4) {
		if (nb[i] != t)
			break;
		if (i == 8)
			return 1;
	}
	//대각선 오른쪽 위 -> 왼쪽 아래
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

//now_b = now_board. 현재 보드의 상태
//turn = 누구 차례?
char game_result(string& now_b, char turn) { //이 상태에서 게임의 결과를 return.
	//base case
	if (isFinished(now_b, 'o' + 'x' - turn)) //true : 이전 turn이었던 애가 이김
		return -1;

	//now_b -> int 값으로 변환
	char& ret = cache[nb_to_int(now_b)];
	if (ret != -2)
		return ret;

	ret = 2; //모두 다 채웠을 때 TIE는 isFinished로 검사가 안됨. -> ret == 2인 상태
	for (int i = 0; i < 3; i++) { //게임 경우의 수 검색
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (now_b[idx] == '.') {
				now_b[idx] = turn;
				ret = min(ret, game_result(now_b, 'o' + 'x' - turn)); //-1이 리턴되면 turn인애가 이길 수 있다는 뜻.
				//우선순위 : 자기가 이김 > 비김 > 상대가 이김
				now_b[idx] = '.';
			}
		}
	}

	if (ret == 0 || ret == 2)
		return ret = 0; // 이걸 빼먹음
	else
		return ret = -ret; // 이걸 빼먹음
}

int main() {
	cin >> C;
	while (C--) {
		string board = "";
		string s;
		int cnt_dot = 0;
		for (int i = 0; i < 3; i++) {
			cin >> s;
			for (int j = 0; j < s.size(); j++) //점 갯수 파악
				if (s[j] == '.')
					cnt_dot++;
			
			board += s; //게임 판 입력받기
		}
		fill(&cache[0], &cache[19683], -2);
		
		/*board = "...xx.oo."
		board를 9자리의 3진수로 보자 3^9 = 19683
		cache[틱택토상태] ==	1	: 자기가 이김
								0	: 비김 
								-1	: 상대가 이김 
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