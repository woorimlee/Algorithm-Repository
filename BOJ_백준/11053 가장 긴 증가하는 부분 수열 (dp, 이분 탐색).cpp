#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> seq;
int cache[1001];

int findLisDP(int idx) {
	int& ret = cache[idx + 1];
	if (ret != 0)
		return ret;

	ret = 1;

	for (int i = idx + 1; i < N; i++) {
		if (idx == -1 || seq[i] > seq[idx]) {
			ret = max(ret, findLisDP(i) + 1);
		}
	}
	return ret;
}

int findLisBS() {
	vector <int> retLis = { seq[0] };
	for (int i = 1; i < N; i++) {
		if (retLis.back() >= seq[i]) {
			vector <int>::iterator it = 
				lower_bound(retLis.begin(), retLis.end(), seq[i]);
			*it = seq[i];
		}
		else 
			retLis.push_back(seq[i]);
	}
	return retLis.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		seq.push_back(num);
	}
	
	// cout << findLisDP(-1) - 1;
	cout << findLisBS();
	return 0;
}