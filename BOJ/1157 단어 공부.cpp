#include <iostream>
#include <string>
using namespace std;
#define alphabet 26
int main() {
	string str;
	cin >> str;
	bool flag = false; //true면 ?출력
	char find_char = str[0]; //가장 많이 나온 문자 저장하기
	int max_num = -1; //가장 많이 나온 문자의 횟수 저장하기
	int change_char = 0; //소문자와 대문자일때 각각 다른 계산을 하기 위해서
	int ans[alphabet] = { 0 }; //나온 횟수 저장해둘 배열

	for (int i = 0; i < str.size(); i++) {
		//대문자를 기본 경우라고 생각하고
		//소문자의 경우 대문자로 바꿈
		if ('a' <= str[i] && str[i] <= 'z')
			change_char = 'a';
		else
			change_char = 'A';

		ans[str[i] - change_char]++;
		//가장 많이 사용된 알파벳 찾기
		if (max_num == ans[str[i] - change_char]) {
			flag = true;
		}
		else if (max_num < ans[str[i] - change_char]) {
			flag = false;
			find_char = str[i] - change_char + 'A'; //찾은 문자를 대문자로 바꾸기
			max_num = ans[str[i] - change_char];
		}
	}
	flag ? cout << "?" : cout << find_char;
	
	return 0;
}