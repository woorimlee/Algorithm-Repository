#include <iostream>
#include <vector>

using namespace std;

/*
�ִ� 20x20�� board�� ���� �ű⿡ ���ĺ��� �Է¹޴´�.
���� ���� �� �ִ� �ִ� ĭ�� ���ϱ� ���ؼ�
���� ������ ��θ� ���� vector �� ���� vec�� �ϳ� �����.
���� ���� ����ĭ���� �̵� �� ������ board�� �ִ� ���ĺ��� vec�� �ִ� �����̸� �̵����� ���ϴ� ������ �Ǻ��Ѵ�.
����ĭ���� �Դµ� vec�� ���� �����̸�, vec�� �߰��ϰ� �ٽ� ���� ����� �̵��Ѵ�.
�� �������� ���� �̵��ϴ� �Ϳ� ���� ��� ȣ����
1. �� ó�� ���������� �����¿� �� �������� ���� �����δ�.
2. ex. ���� �� �������� ���� �����̸�, ���� ������ ��ġ���� �� ������ ������ ������ �� �������� ���� �����δ�.
���� �� �������� �־��� Board ������ ����� �� �ȴ�.
*/

int answer = 1; //�ּ� ���� ��ġ���� �ִٴ� �� ������ 1����
int R, C;
char board[20][20];
int direct[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

bool check(vector <char> &vec, int x, int y) {
	for (auto it : vec) {
		if (it == board[x][y]) return false;
	}
	return true;
}

//�� ó���� vec�� board[0][0]�� ���� ����ִ� ���´�.
void run(vector <char> &vec, int x, int y, int count) {
	int nx, ny;

	for (int i = 0; i < 4; i++) { //�����¿��
		nx = x + direct[i][0];	
		ny = y + direct[i][1];
		if (0 <= nx && nx < R && 0 <= ny && ny < C) { //�迭 ���� ����� ������
			//cout << "If : " << nx << ny << endl;
			if (check(vec, nx, ny)) { //������ ���� �ƴϸ�
				vec.push_back(board[nx][ny]); // �ְ�
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
	//R�� ���� C�� ����
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	//0, 0���� ���� ������ �Ȱ��� �ܾ� �� ��� �����¿� �̵� �����ϸ� �̵�
	//�̵��� ���� ���� �� �ָ� ���
	vector <char> vec;
	vec.push_back(board[0][0]);
	run(vec, 0, 0, 1);
	cout << answer << endl;
	return 0;
}