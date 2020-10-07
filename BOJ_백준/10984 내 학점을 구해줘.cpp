#include <iostream>

using namespace std;

int T, N, C;
double G;

int main() {
	cin >> T;
	//cout << fixed == 소수점을 고정시키겠다
	cout << fixed;
	//cout.precision(1) == 가장 큰 자리수부터 한 자리를 출력하겠다
	cout.precision(1);
	while (T--) {
		cin >> N;
		int GP = 0;
		double GPA = 0.0;
		for(int i = 0; i < N; i++) {
			cin >> C >> G;
			GP += C;
			GPA = GPA + ((double)C * G);
		}
		cout << GP << " " << GPA/(double)GP << "\n";
	}
	return 0;
}