#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map <string, double> m;
	string tree;
	
	int cnt = 0;
	while (getline(cin, tree)) {
		m[tree]++;
		cnt++;
	}

	// 소수점 네 번째에서 반올림
	cout << fixed;
	cout.precision(4);

	for (auto it : m) {
		cout << it.first << " " << it.second / cnt * 100 << "\n";
	}
	return 0;
}