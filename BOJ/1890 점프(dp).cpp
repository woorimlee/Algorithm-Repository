#include <iostream>

using namespace std;

int N;
int board[101][101];
long long cache[101][101];

//dp�� ������ �Լ� 
//dp(y, x) = �������� ������ �� �ִ� ����� ��.
//�������� ������ ��� �� ���� ����� ��Ÿ�� �������� 1�� �����ϰ�
//1�� ���� ���� ��ġ(jump �Լ��� ������ ��)���� �ڽ��� ��ġ���� ������ �� �ִ� ��쿡 1�� �����ش�.
//�������������� dp�� �����س����ٰ� ��������.
long long jump(int y, int x) {
	if (y >= N || x >= N) {
		return 0;
	}
	if (y == N - 1 && x == N - 1) {
		return 1;
	}
	if (cache[y][x] != -1) {
		return cache[y][x];
	}

	//ret�� cache�� ������ ������ cache[y][x]�� �� ��ü�� �ٲ��� �� ����.
	long long& ret = cache[y][x];
	ret = 0;
	ret += jump(y + board[y][x], x);
	ret += jump(y, x + board[y][x]);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//dp�� ��� ���� -1�� �ٲ����, ������ �� ���� ��� 0��, ������ �� �ִ� ��� 1�� return �ϴ� ����.
	fill(&cache[0][0], &cache[100][100], -1);
	cout << jump(0, 0);
	return 0;
}