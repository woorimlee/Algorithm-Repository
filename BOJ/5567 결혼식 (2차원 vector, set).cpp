#include <iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	vector < vector <int> > vec;
	set <int> invite;

	cin >> n >> m;
	vec.resize(n + 1);

	while (cin >> a >> b) {
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (auto i : vec[1]) {
		invite.insert(i);
		for (auto j : vec[i]) {
			invite.insert(j);
		}
	}
	cout << invite.size() - 1;
	return 0;
}