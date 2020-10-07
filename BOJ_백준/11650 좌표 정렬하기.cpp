#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else 
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int x, y;
	cin >> N;
	vector <pair <int, int> > vec;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vec.emplace_back(pair<int, int>{ x ,y });
	}
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	return 0;
}