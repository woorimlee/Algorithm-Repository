#include <string>
#include <iostream>
#include <vector>
using namespace std;

string str; // 입력 받을 문자열
string bomb; // 폭발 문자열
vector <char> ans; // 답 저장할 스택

int main() {

	cin >> str >> bomb;
	ans.resize(str.size());
	int bs = bomb.size() - 1; //bs == bombsize, bomb의 마지막 index.
	
	bool flag = false; //false == 폭발문자열 아님, true == 폭발 문자열임
	int i = 0, j = 0, k = 0, index = 0;
	for (i = 0; i < str.size(); i++) {
		flag = false;
		//정답을 저장할 배열에 입력받은 문자열을 하나씩 넣음
		ans[index] = str[i]; 
		
		//스택 구조처럼 문제를 풀 예정.
		//str == ABC4D
		//bomb == C4라면, 
		//ans == ABC4가 되는 순간 4부터 거꾸로 ans 배열 검사. (4 다음이 C인지 찾음)
		//입력받은 문자의 현재 값이 폭발 문자열의 맨 마지막 문자라면,
		if (str[i] == bomb[bs]) { 
			//폭발 문자열인지 검사함.
			flag = true;
			k = 1;
			for (j = bs - 1; j >= 0; j--) {
				if (ans[index - k] != bomb[j]) {
					flag = false;
					break;
				}
				k++;
			}
		} //이 if문이 끝나면 폭발 문자열이 존재한다 ? flag = true : flag = false  

		//폭발 문자열이 존재하면
		if (flag) {
			//정답을 저장할 배열의 index 값을 폭발 문자열이 시작하는 위치로 옮김
			index -= bs;
			continue;
		}
		index++;
	}
	if (index == 0) {
		cout << "FRULA";
		return 0;
	}
	for (int i = 0; i < index; i++) {
		cout << ans[i];
	}

	return 0;
}