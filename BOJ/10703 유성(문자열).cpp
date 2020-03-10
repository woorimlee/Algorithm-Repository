#include <iostream>
#include <string>

using namespace std;

int R, S;
int dis = 3001;//dis == distance. 땅과 유성 사이의 거리 최소 값

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> S;
	//char 배열로 해도 됨
	//아래는 그냥 R개의 string을 만들어 photo라는 변수로 관리하겠다는 뜻.
	//일차원 string 배열로 생각하자.
	string* photo = new string[R];
	for (int i = 0; i < R; i++)
		cin >> photo[i];

	//유성과 땅 사이의 거리 계산
	int ground = 0;
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (photo[j][i] == '#') {
				//땅의 위치를 변수에 기억해둠
				ground = j;
			}
			else if (photo[j][i] == 'X') {
				//땅과 유성의 위치 사이의 거리를 구하며,
				//동시에 가장 최소가 되는 거리를 찾는다.
				dis = (dis > (ground - j - 1)) ? ground - j - 1 : dis;
				break;
			}
		}
	}

	//사진 복원
	//최소 거리 만큼 유성을 아래로 이동시킴
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (photo[j][i] == 'X') {
				photo[j + dis][i] = 'X';
				photo[j][i] = '.';
			}
		}
	}

	//출력
	for (int i = 0; i < R; i++)
		cout << photo[i] << "\n";

	return 0;
}