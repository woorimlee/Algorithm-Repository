#include <iostream>
#include <string>

using namespace std;

//숫자 비교 쉽게 하기 위해 string 형식으로 사용.
//짝수 개씩 검사하면 됨.
//좋은 수열 검사 통과? 다음 수열 찾기
//통과 못하면? 백트랙킹

int N;
bool flag = false;

void make_seq(string seq) {
	if (flag == true)
		return;
	string str1, str2;
	//가장 끝의 두 수열 비교
	//검사할 때 만들어진 수열 길이가 6이면
	//맨 끝에 새로 추가된 숫자 기준으로 총 세 번만 계산하면 됨.
	//ex) 1 2 1 3 1 2 가 만들어졌으면
	//    맨 끝의 1 | 2 검사
	//    맨 끝에서부터 1 3 | 1 2 검사
	//    맨 끝에서부터 1 2 1 | 3 1 2 검사
	//str1은 검사 대상의 앞 부분, str2는 뒷 부분이라 하면 
	//str1의 substr에 첫 번째 parameter pos에 넣을 값은 str2의 pos - (i+1)
	//적기 편하게 seq.length - 1을 seq_len으로 지정
	int seq_len = seq.length() - 1;
	for (int i = 0; i < seq.length() / 2; i++) {
		str2 = seq.substr(seq_len - i, i+1);		
		str1 = seq.substr(((seq_len - i) - (i + 1)), i+1);	
		if (str1.compare(str2) == 0) 
			return; //str1하고 str2가 같으면 리턴
	}
	//위의 구문을 통과한 seq는 좋은 수열

	if (seq.length() == N) {
		cout << seq;
		//하나만 찾으면 되니까... 종료시키자.
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++)
		make_seq(seq + (char)(i + '0'));

	return;
}

int main(void) {
	cin >> N;

	//인접 길이가 1일 때, 2일 때, ... n/2일 때까지 검사
	//맨 앞이 1인 수열부터 시작
	make_seq("1");

	return 0;
}