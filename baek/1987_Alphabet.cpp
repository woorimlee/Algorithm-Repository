#include <iostream>
#include <vector>

using namespace std;

/*
최대 20x20의 board를 만들어서 거기에 알파벳을 입력받는다.
말이 지날 수 있는 최대 칸을 구하기 위해서
말이 지나는 경로를 담은 vector 형 변수 vec를 하나 만든다.
만약 말이 다음칸으로 이동 시 도착한 board에 있는 알파벳이 vec에 있는 내용이면 이동하지 못하는 곳으로 판별한다.
다음칸으로 왔는데 vec에 없는 내용이면, vec에 추가하고 다시 다음 보드로 이동한다.
네 방향으로 말이 이동하는 것에 대한 재귀 호출은
1. 맨 처음 시작지에서 상하좌우 네 방향으로 말을 움직인다.
2. ex. 만약 우 방향으로 먼저 움직이면, 새로 도착한 위치에서 좌 방향을 제외한 나머지 세 방향으로 말을 움직인다.
물론 이 과정에서 주어진 Board 영역을 벗어나면 안 된다.
*/

int answer = 1; //최소 시작 위치에는 있다는 것 만으로 1점임
int R, C;
char board[20][20];
int direct[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

bool check(vector <char> &vec, int x, int y) {
	for (auto it : vec) {
		if (it == board[x][y]) return false;
	}
	return true;
}

//맨 처음의 vec에 board[0][0]의 값이 들어있는 상태다.
void run(vector <char> &vec, int x, int y, int count) {
	int nx, ny;

	for (int i = 0; i < 4; i++) { //상하좌우로
		nx = x + direct[i][0];	
		ny = y + direct[i][1];
		if (0 <= nx && nx < R && 0 <= ny && ny < C) { //배열 영역 벗어나지 않으면
			//cout << "If : " << nx << ny << endl;
			if (check(vec, nx, ny)) { //지나온 길이 아니면
				vec.push_back(board[nx][ny]); // 넣고
				//cout << "test :" << board[nx][ny] << " !" << endl;
				//cout << vec.size() << endl;
				run(vec, nx, ny, count+1);
				vec.pop_back();
			}
			
		}
	}

	if (answer < count) {
		answer = count;
	}
	return;
}

int main(void) {
	cin >> R >> C;
	//R이 세로 C가 가로
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	//0, 0에서 말이 시작해 똑같은 단어 안 밟고 상하좌우 이동 가능하면 이동
	//이동한 길이 제일 긴 애를 출력
	vector <char> vec;
	vec.push_back(board[0][0]);
	run(vec, 0, 0, 1);
	cout << answer << endl;
	return 0;
}