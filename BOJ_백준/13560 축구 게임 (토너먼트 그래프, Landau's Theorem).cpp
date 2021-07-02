#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;
	cin >> n;
	vector <int> team(n, 0);
	for (int& it : team) {
		cin >> it;
	}
	sort(team.begin(), team.end());
	for (int i = 1; i <= n; i++) {
		sum += team[i - 1];
		
		if ((sum < i * (i - 1) / 2)) {
			cout << -1;
			return 0;
		}
	}

	cout << (sum == n * (n - 1) / 2 ? 1 : -1);
	return 0;
}