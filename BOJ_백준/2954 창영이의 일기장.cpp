#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	string content;
	getline(cin, content);

	smatch sm;
	regex rgx("([aeiou])p[aeiou]"); //�ҹ��ڸ� �Է�
	content = regex_replace(content, rgx, "$1");
	cout << content;

	return 0;
}