#include <iostream>
#include <string>

using namespace std;

int N, ans=0;
bool check[26] = { false };

bool group_word_check(string &str) {
	//맨 처음 글자는 true로 설정하고 다음 글자부터 검사 시작
	check[str[0] - 'a'] = true;
	for (int i = 1; i < str.length(); i++) {
		//현재 글자와 이전 글자가 다른 상황인데
		//현재 글자의 bool 배열 값이 true면 예전에 나온 적 있는 단어
		if (str[i] != str[i - 1] && check[str[i] - 'a']) {
			return false;
		}
		//나머지 경우에는 그냥 현재 단어의 bool 배열을 true로 만들어줌
		check[str[i] - 'a'] = true;
	}
	//위 for 구문을 무사히 통과하면 띄어져 나온 중복 단어는 없는 상태
	return true;
}

int main() {
	cin >> N;
	string str;
	while (N--) {
		cin >> str;
		//매 시행마다 bool 배열 false로 초기화
		fill_n(check, 26, false);
		//조건 검사해서 참인 경우 답 증가
		if (group_word_check(str)) {
			ans++;
		}
	}
	cout << ans;
}