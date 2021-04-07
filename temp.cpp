#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	// 1. regex_match(string, regex, flags) : ���Խ��� ���ڿ� ��ü�� ��ġ�ϴ��� �˻�
	// regex �ν��Ͻ��� ����ǥ���� �Է� �� �̿�
	// smatch �ν��Ͻ��� �̿��ϸ� ��Ī�� ���ڿ��� ��Ī �� Ƚ�� �ľ� ����
	// regex_match(string, match_result, regex, flags)
	regex rgx("abc");
	vector <string> rgx_test = { "abc", "abcd", "dabc" , "ab", "abccc"};
	for (string it : rgx_test) {
		if (regex_match(it, rgx))
			cout << it << " matched\n";
		else
			cout << "False\n";
	}
	cout << "\n======================\n";

	rgx = "abc*";
	smatch sm;
	for (string it : rgx_test) {
		if (regex_match(it, sm, rgx)) {
			cout << "match size : " << sm.size() << ", match : ";
			for (int i = 0; i < sm.size(); i++)
				cout << sm[i].str() << ", ";
			cout << "\n";
		}
		else
			cout << "False\n";
	}
	cout << "\n======================\n";

	// 2. regex_search(string, regex, flags) : ���ڿ� �Ϻκ� ��Ī �˻�
	rgx = "abc*";
	for (string it : rgx_test) {
		if (regex_search(it, sm, rgx)) {
			cout << "match size : " << sm.size() << ", match : ";
			for (int i = 0; i < sm.size(); i++)
				cout << sm[i].str() << ", ";
			cout << "\n";
		}
		else
			cout << "False\n";
	}
	cout << "\n======================\n";

	string s = "this subject has a submarine as a subsequence";
	rgx = "\\b(sub)(\\w+)"; 
	while (regex_search(s, sm, rgx)) { //�� ���� �ȿ��� ���� �� ã�� ���
		for (auto matched_s : sm)
			cout << matched_s << ", ";
		cout << "\n"; 
		s = sm.suffix(); //suffix() ���ڿ����� ��Ī�� �κ��� ���̻� �κ��� return
						//�̰� �����ָ� �� ó���������� �ٽ� �˻�
	}
	cout << "\n======================\n";

	// 3. regex_replace(string, regex, format, flags) : ��ġ�ϴ� �Ϻκ��� �ٸ� ���ڿ��� ġȯ
	s = "HELLO boy, hello girl, Hello?";
	regex rgx2("Hello", regex::icase); //��ҹ��� ���� X
	cout << regex_replace(s, rgx2, "Hi") << "\n";
	cout << "\n======================\n";

	// ����
	//1. 0-9�� A-F�� ����ϰ� �� �տ� 0x�� &H�� �ٴ� 16���� ã��.
	rgx_test = { "0x12", "&HA", "abcdefg", "0xabH", "0xx" };
	rgx = "(\\b0x|&H)?([0-9A-F]+|[0-9a-f]+)\\b";
	for (string it : rgx_test) {
		if (regex_search(it, rgx))
			cout << it << " matched\n";
		else
			cout << "False\n";
	}
	cout << "\n======================\n";
	
	//2. 010���� �����ϴ� �ڵ��� ��ȣ �˻�, �߰� ���ڿ� ������ ���ڴ� 4��.
	rgx_test = { "010-4123-1234", "010-12345-1111", "011-123-12", "123-9421-1254" };
	rgx = "\\b010-[0-9]{4}-\\d{4}\\b";
	for (string it : rgx_test) {
		if (regex_search(it, rgx))
			cout << it << " matched\n";
		else
			cout << "False\n";
	}
	cout << "\n======================\n";

	//3. ������ �տ� ���� 0���� ����
	rgx_test = { "00012345", "123", "12300", "0"};
	rgx = "\\b0*([1-9][0-9]*|0)\\b";
	for (string it : rgx_test) {
		cout << regex_replace(it, rgx, "$1") << " ";
	}

	return 0;
}