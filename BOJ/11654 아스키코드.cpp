#include <iostream>
#include <string>

using namespace std;

int main() {
	int ans = 0;
	string str;
	//공백이 포함된 한 줄을 입력받는 방법
	getline(cin, str, '\n');
	//str.front와 str.back할 때 str이 empty상태면 안 됨
	while (!str.empty()) {	//while문 안 쓰고 14번, 20번, 25번째 줄부터를 각각 if(!str.empty())로 묶어줘도 됨 
		//맨 처음 공백 제거
		if (str.front() == ' ') {
			str.erase(str.begin());
			continue;
		}
		
		//맨 마지막 공백 제거
		if (str.back() == ' ') {
			str.erase(str.end() - 1);
			continue;
		}
		
		//find는 찾은 문자의 위치를 반환함
		size_t pos = str.find(' ');
		while (pos != string::npos) {
			ans++;
			//찾은 위치 다음부터 찾아라
			pos = str.find(' ', pos + 1);
		}
		ans++;
		break;
	}
	cout << ans;
	return 0;
}