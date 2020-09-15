#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

void tokenize(string a) {
	int len = a.length();
	string sub_a = a.substr(0, len/2);
	string sub_b = a.substr(len/2);
	cout << sub_a << " " << sub_b << "\n";
}

int main() {
	string s;
	cin >> s;
	tokenize(s);
	
}