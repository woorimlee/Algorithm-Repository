#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, N, M, temp, answer;
int arr[16][16] = { 0, };

int main() {

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N >> M;

		answer = 0, temp = 0;
		memset(arr, 0, sizeof(arr));

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				cin >> arr[j][k];
		}

		for (int j = 0; j < N - M + 1; j++)
		{
			for (int k = 0; k < N - M + 1; k++)
			{
				for (int l = j; l < j + M; l++)
				{
					for (int m = k; m < k + M; m++)
					{
						temp += arr[l][m];
					}
				}
				answer = max(answer, temp);
				temp = 0;
			}
		}
		cout << "#" << i << " " << answer << endl;
	}
	return 0;
}