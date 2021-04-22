#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	string signal;
	cin >> signal;
	
	regex rgx("\\b((100+1+)|01)+\\b");
	if (regex_match(signal, rgx))
		cout << "SUBMARINE";
	else
		cout << "NOISE";

	return 0;
}