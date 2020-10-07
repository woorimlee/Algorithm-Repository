#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M, ans=INT_MAX;
string board[51];

//ü���� �� ������ �̸� �����صΰ�
//N*M ü���ǿ��� 8*8 �����Ϸ� �ٽ� ĥ�ϱ� �˻縦 �ϳ��� �� �غ�
//�̸� �����ص� ü���ǰ� 8*8 �����Ϸ� �ڸ� ü������ �ٸ� Ƚ����ŭ ���� ���
//�ּڰ��� ��
string WB[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

string BW[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

int WB_Check(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != WB[i - y][j - x])
				cnt++;
	return cnt;
}

int BW_Check(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != BW[i - y][j - x])
				cnt++;
	return cnt;
}



int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			ans = min(ans, min(WB_Check(i, j), BW_Check(i, j)));
		}
	}

	cout << ans;
	return 0;

}