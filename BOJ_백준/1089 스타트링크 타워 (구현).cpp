#include <iostream>
#include <vector>
#include <string>

using namespace std;

string digitNum[10][5] = {
	{"###","#.#","#.#","#.#","###"}, // 0
	{"..#","..#","..#","..#","..#"},
	{"###","..#","###","#..","###"},
	{"###","..#","###","..#","###"},
	{"#.#","#.#","###","..#","..#"},
	{"###","#..","###","..#","###"},
	{"###","#..","###","#.#","###"},
	{"###","..#","..#","..#","..#"},
	{"###","#.#","###","#.#","###"},
	{"###","#.#","###","..#","###"} // 9
};

int N;
string sign[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (string& s : sign)
		cin >> s;

	double ans = 0.0, floor = 1.0;
	for (int i = N - 1; i >= 0; i--) { // 1의자리 층수부터 탐색
		int pNum = 0; //pNum : total possible number 
		int pCnt = 0; //pCnt : possible counter
		//숫자 10개 검사
		for (int number = 0; number <= 9; number++) {
			bool flag = true;
			for (int row = 0; row < 5; row++) {
				for (int col = 0; col < 3; col++) {
					if (digitNum[number][row][col] == '.' && sign[row][4 * i + col] == '#')
						flag = false;
				}
			}
			if (flag) {
				pCnt++;
				pNum += number;
				//cout << number << ", ";
			}
		}

		if (pCnt != 0)
			ans += pNum * floor / pCnt;
		else {
			cout << -1;
			return 0;
		}
		floor *= 10;
	}
	
	cout << ans;
	return 0;
}