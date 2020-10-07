#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map <int, bool> check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		check[temp] = true;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		cout << check[temp] << "\n";
	}
	return 0;
}