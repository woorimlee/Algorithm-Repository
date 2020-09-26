#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define loop(i, n, m) for(int i = n; i < m; i++)
using namespace std;

string s;
int cache[2001][2001];

bool check_palindrome(int lft, int rgt) {
	while (lft < rgt) {
		if (s[lft++] != s[rgt--])
			return false;
	}
	return true;
}

int find_palindrome(int lft, int rgt) {

	int& ret = cache[lft][rgt];
	if (ret != 1234567890) {
		return ret;
	}

	if (lft > rgt || rgt < 0)
		return 0;

	/*loop(i, lft, rgt + 1) {
		cout << s[i] << " ";
	}*/
	if (check_palindrome(lft, rgt)) {
		//cout << " -> palin\n";
		return ret = 1;
	}
	//cout << "\n";

	//ret = min(find_palindrome(lft, rgt - 1) + find_palindrome(rgt + 1, s.size() - 1), ret);
	loop(i, lft, rgt) {
		ret = min(find_palindrome(lft, i) + find_palindrome(i + 1, rgt), ret);
	}
	/*loop(i, lft, rgt + 1) {
		cout << s[i] << " ";
	}cout <<" : " << ret << "\n";*/
	return ret;
}

int main() {
	cin >> s;
	fill(&cache[0][0], &cache[2000][2000], 1234567890);
	cout << find_palindrome(0, s.size() - 1);
	return 0;
}