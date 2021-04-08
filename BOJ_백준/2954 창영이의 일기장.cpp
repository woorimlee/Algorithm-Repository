#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	string content;
	getline(cin, content);

	smatch sm;
	regex rgx("([aeiou])p[aeiou]"); //소문자만 입력
	content = regex_replace(content, rgx, "$1");
	cout << content;

	return 0;
}