#include <vector>
#include <iostream>

using namespace std;

int T;
int N;
vector <int> value;

void millionaire();

int main(void) {

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		value.clear();
		value.resize(N);
		for (int j = 0; j < N; j++)
			cin >> value[j];
		cout << "#" << i + 1 << " ";
		millionaire();
	}

	return 0;
}

void millionaire() {
	long long ans = 0;
	int max_price = value[value.size() - 1];
	for (int cur = value.size() - 2; cur >= 0; cur--) { //cur = current
		if (max_price > value[cur]) {
			//to do : ans 계산
			ans += max_price - value[cur];
		}
		else {
			//to do : 최대 값 위치 기억
			max_price = value[cur];
		}
	}

	cout << ans << "\n";
}