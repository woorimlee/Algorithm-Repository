#include <iostream>
#include <vector>
using namespace std;

int M, N;

void zeroify(int ** matrix, vector <bool> &row, vector <bool> &column) {

	for (int i = 0; i < M; i++) {
		if (row[i]) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (column[i]) {
			for (int j = 0; j < M; j++) {
				matrix[j][i] = 0;
			}
		}
	}

	return;
}

void make_zero_matrix(int ** matrix) {
	vector <bool> row(M, false);
	vector <bool> column(N, false);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 0) {
				row[i] = true;
				column[j] = true;
			}
		}
	}

	zeroify(matrix, row, column);
	
	return;
}

void print_matrix(int ** matrix) {
	cout << "\n";

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	
	return;
}

int main() {
	cin >> M >> N;
	int ** matrix = new int *[M];
	for (int i = 0; i < M; i++) {
		matrix[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}

	make_zero_matrix(matrix);
	print_matrix(matrix);

	return 0;
}