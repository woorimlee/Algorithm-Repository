#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, maxNum, countNum;
int N = 1000;
int arr[101];

int main() {
	cin >> T;

	int temp, dump;
	for (int i = 1; i <= T; i++) {
		cin >> dump;
		countNum = 0;
		maxNum = -1;
		memset(arr, 0, sizeof(arr));

		for (int j = 0; j < N; j++) {
			cin >> temp;
			arr[temp]++;

			if (arr[temp] >= countNum) {
				countNum = arr[temp];
				if (countNum == arr[temp])
					maxNum = temp;
			}

		}

		cout << "#" << i << " " << maxNum << endl;
	}
	return 0;
}