#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {

	if (a.first < b.first) return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int n; 
	vector <pair <int, string> > vec;
	
	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	//순서를 보장해주는 stable_sort
	stable_sort(vec.begin(), vec.end(), comp);

	for (auto it : vec) {
		cout << it.first << " " << it.second << '\n';
	}
	return 0;
}