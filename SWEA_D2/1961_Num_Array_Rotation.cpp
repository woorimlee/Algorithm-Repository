#include <iostream>

using namespace std;

int T, N;

void rotateMatrix(int **& Matrix);// 90�� ȸ��
void printMatrix(int ** &Matrix, int row); // row �� �� ���

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
		for (int i = 0; i < N; i++) { // 0����� N-1����� ���
			for (int j = 0; j < 3; j++) { // 90�� ȸ�� �� ����ϴ� �� �� �� �� ��.
				rotateMatrix(Matrix);
				printMatrix(Matrix, i);
				cout << " ";
			}
			rotateMatrix(Matrix); // ���󺹱�(360�� ȸ��)
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