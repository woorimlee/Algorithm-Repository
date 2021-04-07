#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	// 1. regex_match(string, regex, flags) : 정규식이 문자열 전체와 일치하는지 검사
	// regex 인스턴스에 정규표현식 입력 후 이용
	// smatch 인스턴스를 이용하면 매칭된 문자열과 매칭 된 횟수 파악 가능
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

	// 2. regex_search(string, regex, flags) : 문자열 일부분 매칭 검사
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
	while (regex_search(s, sm, rgx)) { //한 문장 안에서 여러 번 찾는 경우
		for (auto matched_s : sm)
			cout << matched_s << ", ";
		cout << "\n"; 
		s = sm.suffix(); //suffix() 문자열에서 매칭된 부분의 접미사 부분을 return
						//이걸 안해주면 맨 처음에서부터 다시 검사
	}
	cout << "\n======================\n";

	// 3. regex_replace(string, regex, format, flags) : 일치하는 일부분을 다른 문자열로 치환
	s = "HELLO boy, hello girl, Hello?";
	regex rgx2("Hello", regex::icase); //대소문자 구문 X
	cout << regex_replace(s, rgx2, "Hi") << "\n";
	cout << "\n======================\n";

	// 예제
	//1. 0-9와 A-F를 사용하고 맨 앞에 0x나 &H가 붙는 16진수 찾기.
	rgx_test = { "0x12", "&HA", "abcdefg", "0xabH", "0xx" };
	rgx = "(\\b0x|&H)?([0-9A-F]+|[0-9a-f]+)\\b";
	for (string it : rgx_test) {
		if (regex_search(it, rgx))
			cout << it << " matched\n";
		else
			cout << "False\n";
	}
	cout << "\n======================\n";
	
	//2. 010으로 시작하는 핸드폰 번호 검색, 중간 숫자와 마지막 숫자는 4개.
	rgx_test = { "010-4123-1234", "010-12345-1111", "011-123-12", "123-9421-1254" };
	rgx = "\\b010-[0-9]{4}-\\d{4}\\b";
	for (string it : rgx_test) {
		if (regex_search(it, rgx))
			cout << it << " matched\n";
		else
			cout << "False\n";
	}
	cout << "\n======================\n";

	//3. 십진수 앞에 오는 0들을 제거
	rgx_test = { "00012345", "123", "12300", "0"};
	rgx = "\\b0*([1-9][0-9]*|0)\\b";
	for (string it : rgx_test) {
		cout << regex_replace(it, rgx, "$1") << " ";
	}

	return 0;
}