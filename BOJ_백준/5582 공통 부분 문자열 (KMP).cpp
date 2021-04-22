#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPartialMatch(string& p) {
	int n = p.size();
	vector <int> pi(n, 0);

	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (p[begin + matched] == p[matched]) {
			pi[begin + matched - 1] = ++matched;
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
	return pi;
}

vector<int> kmpSearch(string s, string p) {
	int n = s.size();
	int m = p.size();

	vector <int> pi = getPartialMatch(p);
	vector <int> ret(n, 0);
	int begin = 0, matched = 0;
	while (begin + matched < n) {
		if (matched < m && s[begin + matched] == p[matched]) {
			ret[begin + matched - 1] = ++matched;
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
	return ret;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	vector <int> ret;
	
	//s1 = s, s2 = p
	//s : 대상 문자열, p : 부분 문자열
	if (s1.size() < s2.size()) {
		swap(s1, s2);
	}

	int ans = 0;
	for (int i = 0; i < s2.size(); i++) {
		// cout << s1 << ", " << s2.substr(i) << " : ";
		ret = kmpSearch(s1, s2.substr(i));
		int ret_max = *max_element(ret.begin(), ret.end());
		ans = max(ans, ret_max);
		// cout << ret_max << ", " << ans << "\n";
	}
	cout << ans;

	return 0;
}