#include <iostream>

using namespace std;

int T, N;

void rotateMatrix(int **& Matrix);// 90도 회전
void printMatrix(int ** &Matrix, int row); // row 행 다 출력

int main() {
	cin >> T;
	for (int now = 1; now < T; now++) {
		cin >> N;
		int ** Matrix = new int *[N];
		for (int i = 0; i < N; i++) {
			Matrix[i] = new int[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Matrix[i][j];
			}
		}
		cout << "#" << now << "\n";
		for (int i = 0; i < N; i++) { // 0행부터 N-1행까지 출력
			for (int j = 0; j < 3; j++) { // 90도 회전 후 출력하는 걸 총 세 번 함.
				rotateMatrix(Matrix);
				printMatrix(Matrix, i);
				cout << " ";
			}
			rotateMatrix(Matrix); // 원상복귀(360도 회전)
			cout << "\n";
		}


	}

	return 0;
}

void rotateMatrix(int ** &Matrix) {
	int temp = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N - 1 - i; j++) {
			temp = Matrix[i][j];
			Matrix[i][j] = Matrix[N - 1 - j][i];
			Matrix[N - 1 - j][i] = Matrix[N - 1 - i][N - 1 - j];
			Matrix[N - 1 - i][N - 1 - j] = Matrix[j][N - 1 - i];
			Matrix[j][N - 1 - i] = temp;
		}
	}
}

void printMatrix(int ** &Matrix, int row) {
	for (int i = 0; i < N; i++) {
		cout << Matrix[row][i];
	}
}