#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M, ans=INT_MAX;
string board[51];

//체스판 두 종류를 미리 정의해두고
//N*M 체스판에서 8*8 스케일로 다시 칠하기 검사를 하나씩 다 해봄
//미리 정의해둔 체스판과 8*8 스케일로 자른 체스판의 다른 횟수만큼 값을 세어서
//최솟값을 비교
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