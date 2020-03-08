#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

string str;

bool check_Blanced() {
	stack <char> bracket;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			bracket.push(str[i]);
		}
		else if (str[i] == ')') {
			//스택이 비어있으면 균형이 안맞음
			//현재 문자열의 문자가 )인데 스택의 탑 값이 [면 불균형
			if (bracket.empty() || bracket.top() != '(')
				return false;
			bracket.pop();
		}
		else if (str[i] == ']') {
			if (bracket.empty() || bracket.top() != '[')
				return false;
			bracket.pop();
		}
	}
	//아래 조건 처리를 안 하면 ((). 같은거 못 걸러냄
	if (!bracket.empty()) {
		return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while (getline(cin, str)) {
		if (str==".")
			return 0;
		//한 줄 입력받았고,
		//( 또는 [가 오면 스택에 넣고 ) 또는 ]가 오면 스택 가장 마지막 값과 비교해.
		//균형이 잡히지 않았다면 바로 no 출력하고
		//문자열 모두 무사히 탐색했다면 yes 출력하고
		if (check_Blanced()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}