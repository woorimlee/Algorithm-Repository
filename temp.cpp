#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	/*
	
	* : 바로 앞의 문자를 0 번 이상 반복
	+ : 앞의 문자가 한 번 이상 반복
		ex) a+ == aa*
	? : 앞에 나오는 정규 표현식이 없거나 한 개인 것과 일치
	^ : 행의 시작
	$ : 행의 끝
		ex) ^$ == 빈 줄과 일치
	\ : 특수 문자를 일반 문자로 치환
		ex) \\ == \ 문자 그 자체를 찾음
	[, ] : 대괄호는 여러 문자 중 하나와 일치하는 것을 찾음
		   대괄호 안에서 - : 범위를 나타냄
		   대괄호 안에서 ^ : 바로 뒤에 나오는 표현의 반대를 의미함
		   ex) [^0-9] : 숫자를 제외한 모든 문자를 의미
	{, } : 정규 표현식의 빈도수
		   중괄호 안에서 n, : n번 이상 반복
		   중괄호 안에서 n, m : n번 이상 m번 이하 반복
	(, ) : 정규 표현식 그룹을 묶어줌
		   ex) (abc){1, 3} == abc, abcabc, abcabcabc
	| : OR 연산

	1. regex_match : 정규식이 문자열 전체와 일치하는지 검사

	2. regex_search : 문자열 일부분 매칭 검사

	3. regex_replace : 일치하는 일부분을 다른 문자열로 치환

	4. sregex_iterator : 이터레이터 형식으로 매칭된 문자 모두 검사
	*/

	return 0;
}