/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string board[51];

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

int whiteFirstChange(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != WB[i - y][j - x])
				cnt++;
	return cnt;
}

int blackFirstChange(int y, int x)
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



	int result = INF;



	for (int i = 0; i + 7 < N; i++)

		for (int j = 0; j + 7 < M; j++)

			result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));



	cout << result << endl;

	return 0;

}*/