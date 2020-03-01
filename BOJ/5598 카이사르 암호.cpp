#include <iostream>
#include <string>

using namespace std;

//alphabet 배열의 0번째 인덱스는 D를 뜻함.
//... 25번째 인덱스는 C를 뜻함.
char alphabet[26];
string str;

int main() {
	cin >> str;
	//D부터 Z에 해당하는 인덱스를 알파벳 A부터 W까지 넣음
	for (int i = 3; i < 26; i++) {
		alphabet[i] = 'A' + i - 3;
	}
	//A부터 C에 해당하는 인덱스를 알파벳 X부터 Z까지 넣음
	for (int i = 0; i < 3; i++) {
		alphabet[i] = 'X' + i;
	}
	/*배열 확인용 코드
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	*/
	for (int i = 0; i < str.size(); i++) {
		//str이 MRL이라고 하면,
		//str[i]에는 M, R, L이 들어있고
		//i == 0일 때, str[0] == 'M'
		//문자 M의 인덱스 값은 'M' - 'A' 값. (문자 A의 인덱스 값은 'A' - 'A'인 0)
		cout << alphabet[str[i] - 'A'];
	}
	return 0;
}