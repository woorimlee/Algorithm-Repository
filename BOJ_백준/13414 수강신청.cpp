#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int K, L;

bool comp(const pair <string, int>& lhs, const pair <string, int>& rhs) {
	return lhs.second < rhs.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> L;
	
	unordered_map <string, int> s_num;
	string temp;
	for (int i = 1; i <= L; i++) {
		cin >> temp;
		s_num[temp] = i;
	}

	vector <pair <string, int> > sorted_s_num(s_num.begin(), s_num.end());
	sort(sorted_s_num.begin(), sorted_s_num.end(), comp);

	for (int i = 0; i < K && i < sorted_s_num.size(); i++) {
		cout << sorted_s_num[i].first << "\n";
	}

	return 0;
}