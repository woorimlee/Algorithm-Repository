#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	vector <int> sg(N, 0);
	for (auto& it : sg) {
		cin >> it;
	}

	sort(sg.begin(), sg.end());
	

	cin >> M;
	int c;
	for (int i = 0; i < M; i++) {
		cin >> c;
		cout << upper_bound(sg.begin(), sg.end(), c) - lower_bound(sg.begin(), sg.end(), c) << ' ';
	}

	return 0;
}