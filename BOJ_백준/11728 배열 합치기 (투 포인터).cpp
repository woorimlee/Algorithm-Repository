#include <iostream>
#include <vector>
#include <limits> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <int> A(N, 0), B(M, 0);

	for (int& i : A)
		cin >> i;
	for (int& i : B)
		cin >> i;

	A.push_back(INT_MAX);
	B.push_back(INT_MAX);

	int Ap = 0, Bp = 0; //A pointer, B pointer

	while (Ap < N || Bp < M) {
		if (A[Ap] <= B[Bp]) {
			cout << A[Ap++] << " ";
		}
		else {
			cout << B[Bp++] << " ";
		}
	}

	return 0;
}