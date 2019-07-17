#include <iostream>

using namespace std;

int N;

void rotate_arr(int ** arr) {
	int temp;
	int index = 0;

	for (int i = 0; i < (N / 2); i++) {
		for (int j = i; j < (N - 1 - i); j++) {
			temp = arr[i][j];
			arr[i][j] = arr[N - 1 - j][i];
			arr[N - 1 - j][i] = arr[N - 1 - i][N - 1 - j];
			arr[N - 1 - i][N - 1 - j] = arr[j][N - 1 - i];
			arr[j][N - 1 - i] = temp;
		}
		index++;
	}

	return;
}

void print_arr(int ** arr) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return;
}

void main() {
	cin >> N;
	int ** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	rotate_arr(arr);
	print_arr(arr);

	return;
}