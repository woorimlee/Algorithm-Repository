#include <iostream>
#include <algorithm>
using namespace std;

int arr[1002][1002] = { 0, };
int board[1002][1002] = { 0, };

int main(void)
{
	int answer = 0;

	int row, column;
	cin >> column >> row;


	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			scanf_s("%1d", &board[i][j]);
		}
	}

	for (int i = 1; i <= column; i++) {
		for (int j = 1; j <= row; j++) {
			if (board[i - 1][j - 1] == 1) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
				if (arr[i][j] > answer) answer = arr[i][j];
			}
		}
	}

	cout << answer * answer << endl;
	return 1;
}