#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	int T;
	string signal;
	cin >> T;
	while (T--) {
		cin >> signal;
		regex rgx("\\b((100+1+)|01)+\\b");
		if (regex_match(signal, rgx))
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}