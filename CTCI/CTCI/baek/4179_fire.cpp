#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair < char, pair <int, int> > > fM; //초, F와J, x, y
int R, C;
char maze[1001][1001] = { '\0', };
int direct[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

priority_queue<fM, vector<fM>, greater<fM> > pq;

void findCordination(char target) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == target)
				pq.push();
		}
	}
}

int fireMaze() { 
	pair <int, int> xy;
	//맨 처음의 J와 F위치 찾아서 넣어주자
	findCordination('F');
	findCordination('J');
	

	return 0;
}

void printMaze();

int main(void) {

	cin >> R >> C;
	
	char temp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			maze[i][j] = temp;
		}
	}
	
	cout << fireMaze();

	return 0;
}

void printMaze() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}