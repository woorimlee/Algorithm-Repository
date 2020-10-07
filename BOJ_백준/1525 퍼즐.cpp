#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

char ch;
int ans = 0;
//dir[i][0] == y ��ǥ ����, dir[i][1] == x ��ǥ ����
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

typedef struct _puzzel{
	//blank.first�� �� ĭ�� y��ǥ, second�� x��ǥ ����
	pair<int, int> blank;
	string board = "";
	//����ü ������
	_puzzel(int a, int b, string s) {
		blank.first = a;
		blank.second = b;
		board = s;
	}
}puzzel;

puzzel temp(0, 0, "");
unordered_map <string, bool> checked;

bool bfs() {
	int nx, ny, q_size;
	string ns;
	queue <puzzel> q;
	q.push(temp);
	checked[temp.board] = true;
	while (!q.empty()) {
		q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			temp = q.front();
			q.pop();
			if (temp.board == "123456780") {
				return true;
			}
			//1. 0�� �������� �� ������ �Ʒ� ���� �̵� �������� �˻�
			//2. �̹� �˻��� �� �ִ� ���ڿ����� �˻�
			//3. �� ������ ����ϸ� ���� bfs Ȯ��
			for (int i = 0; i < 4; i++) {
				ny = temp.blank.first + dir[i][0];
				nx = temp.blank.second + dir[i][1];
				ns = temp.board;
				if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
					//�� ������ ��ġ�� �����¿� �ٲ� ��ġ swap�ؼ� ���ڿ� �ٲ���
					swap(ns[ny * 3 + nx], ns[temp.blank.first * 3 + temp.blank.second]);
					//cout << ns << "\n";
					if (checked[ns] != true) {
						q.push(puzzel(ny, nx, ns));
						checked[ns] = true;
					}
				}
			}
		}
		ans++;
	}
	return false;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			temp.board += ch;
			if (ch == '0') {
				temp.blank.first = i;
				temp.blank.second = j;
			}
		}
	}

	//cout << temp.board << " " << temp.blank.first << " " << temp.blank.second;
	if (bfs()) {
		cout << ans;
	}
	else {
		cout << -1;
	}
	
	return 0;
}