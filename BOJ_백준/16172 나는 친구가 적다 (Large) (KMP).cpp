#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, k;

vector <int> getPartialMatch() {
	int n = k.size();
	vector <int> pi(n, 0);

	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (k[begin + matched] == k[matched]) {
			pi[begin + matched - 1] = ++matched;
		}
		else if (matched) {
			begin += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
		else {
			begin++;
		}
	}
	return pi;
}

bool kmpSearch() {
	int n = s.size();
	int m = k.size();
	bool ans = false;
	vector <int> pi = getPartialMatch();

	int begin = 0, matched = 0;
	while (begin + matched < n) {
		//cout << begin << ", " << matched << " : " << s[begin + matched] << ", " << k[matched] << "\n";
		if (isalpha(s[begin + matched])) {
			if (matched < m && s[begin + matched] == k[matched]) {
				matched++;
				if (matched == m)
					ans = true;
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		else {
			begin++;
		}
	}
	return ans;
}

int main() {
	cin >> s >> k;
	if (kmpSearch())
		cout << 1;
	else
		cout << 0;
	
	return 0;
}