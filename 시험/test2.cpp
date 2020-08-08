#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int R, S; //R = 세로, S = 가로
	cin >> R >> S;
	//배열 입력받음
	vector <string> photo;
	photo.resize(R + 1);
	for (int i = 0; i < R; i++) cin >> photo[i];
	//유성과 땅 사이의 거리를 계산
	int gnd = 0;
	int dis = 300000;
	//한 열마다 거리를 계산
	for (int i = 0; i < S; i++) {
		for (int j = R-1; j >= 0; j--) {
			if (photo[j][i] == '#') gnd = j;
			else if (photo[j][i] == 'X') {
				dis = min(dis, gnd - j - 1);
				break;
	}	}	}
	//사진 복원을 위해서 땡기기
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