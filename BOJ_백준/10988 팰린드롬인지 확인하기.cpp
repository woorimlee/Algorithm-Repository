#include <iostream>
#include <string>

using namespace std;

string str;


int main() {
	//str은 소문자로 이뤄짐
	cin >> str;
	//주어진 문자열의 맨 앞과 뒤를 동시에 확인할 거임
	int tail = str.size();
	for (int head = 0; head < str.size()/2; head++) {
		tail--;
		//head는 문자열의 앞에서부터,
		//tail은 문자열의 뒤에서부터 
		//각각 문자열을 검사할 것임.
		//두 문자가 다르다면 0을 출력하고
		if (str[head] != str[tail]) {
			cout << 0;
			return 0;
		}
		//for 구문을 무사히 통과하면 1을 출력함
	}
	cout << 1;
	return 0;
}