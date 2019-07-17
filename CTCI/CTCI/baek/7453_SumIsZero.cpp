#include <iostream>
#include <vector>

using namespace std;
int n;
vector <int> A, B, C, D;
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;

	A.resize(n);
	B.resize(n);
	C.resize(n);
	D.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	}
	//A + B = -(C + D)
	


	return 0;
}