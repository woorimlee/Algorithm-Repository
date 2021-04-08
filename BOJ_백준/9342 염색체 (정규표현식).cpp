#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	int T;
	string cs;
	regex rgx("\\b[A-F]?A+F+C+[A-F]?\\b");
	cin >> T;
	while (T--) {
		cin >> cs;
		if (regex_match(cs, rgx))
			cout << "Infected!\n";
		else
			cout << "Good\n";
	}

	return 0;
}