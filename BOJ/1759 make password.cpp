#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
문자를 입력받고,
알파벳 순서로 작은 것부터 큰 것까지
최소 한 개의 모음과 두 개의 자음을 만족하는 조건의 L 개의 문자를 뽑아내서
(재귀적으로 조건 만족하는거 발견 후 백트래킹해서 다음으로 넘어가고 ...)
출력하는 것을 끝까지 반복.

이를 위해 자음, 모음 갯수 검사하는 함수 하나 추가 (check 함수)
재귀 함수 돌릴 함수 하나 추가(make_password 함수)
*/

string str;
int L, C;

bool check(string test) {
	int consonant = 0;
	int collection = 0;
	for (auto it : test) {
		if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') collection++;
		else consonant++;
	}

	return (collection >=1 && consonant >= 2);
}

int make_password(string word, int count) {

	//1. base case는 재귀 함수로 만든 문자열 길이가 L일 때.
	if (word.length() == L) {
		if (check(word)) {
			cout << word << endl;
		}
		return 0;
	}

	//5. 아래의 ex 상황에서 C는 6이고, count는 6이 되면 안되니까 return 조건 추가.
	if (count >= str.length()) return 0;
	//6. 4개의 비밀번호를 만드는 데 맨 앞 단어가 d면 더 이상 검사할 필요가 없음.
	//   따라서 word[0]이 str[3]이면 return.
	//   str[3]의 3은 C - L + 1로 구해진다.
	if (word[0] == str[C - (L - 1)]) return 0;
	
	//2. 재귀적으로 암호를 만듦.
	//ex) abcdef가 주어진 단어라면, "" -> "a" -> "ab" -> "abc" -> "abcd" 까지 진행하고 1번 조건에 걸려서 cout << "abcd"
	make_password(word + str[count], count + 1);
	//3. "abcd" 출력 후 return되면 이 위치로 돌아옴. 
	//   이때 word는 "abc"인 상황. "abce"를 만들기 위해 count는 +1 해주지만, word는 "abc"를 넘긴다.
	make_password(word, count + 1);
	//4. 위의 상황을 계속 진행하면 언젠가 "abcf"까지 올 것이고, 이 다음의 return 조건은 따로 만들어줘야한다. 
	//   (바로 abcf 출력 후 abc 상태로 다시 돌아오면 make_paseword("abc", count + 1) 이 진행되는데, count는 6이 되면 안 된다.)

	return 0;
}

int main(void) {
	cin >> L >> C;

	char temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		str += temp;
	}
	sort(str.begin(), str.end());

	make_password("", 0);

	return 0;
}