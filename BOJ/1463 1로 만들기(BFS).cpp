#include <iostream>
#include <queue>

using namespace std;

int N;
bool visited[1000001] = { false };

void bfs() {
	/*
	N���� ���� --> 1�� �������. 
	�����⸦ �ϱ� �Ⱦ ���ϱ�� �ٲܿ�����.
	������ 3�̳� 2�� ������ �������ٴ� ���� 3�� 2�� �����.
	1�� --> N���� ���� ����
	
	�� �� �ִ� ����
	1. ���� �� * 3
	2. ���� �� * 2
	3. ���� �� + 1
	*/
	
	//q.first == ���� ��, second == ���� Ƚ��
	queue <pair <int, int> > q;
	//1���� ����
	q.push({ 1, 0 });
	visited[1] = true;
	pair<int, int> now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		//����� ���� ���� N�̸� ���� Ƚ�� ��� �� ����
		if (now.first == N) {
			cout << now.second;
			return;
		}
		//if�� �� �� ���� �Ⱦ �迭�� ����ؾ� �� �� �־��
		int cal[3] = { now.first * 3, now.first * 2, now.first + 1 };
		for (int i = 0; i < 3; i++) {
			//�ε��� �ʰ��ߴ��� �˻� ���ϸ� ��Ÿ�� ����
			if (cal[i] <= 1000000) {
				//�� ���� ���� �湮 �� �� ���̸�
				if (visited[cal[i]] == false) {
					//�湮�ϰ� push
					visited[cal[i]] = true;
					q.push({ cal[i], now.second + 1 });
				}
			}
		}
	}

}

int main() {
	cin >> N;
	bfs();
}