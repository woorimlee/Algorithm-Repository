#include <iostream>
#include <string>

#define alphabet 26

using namespace std;

int main() {
	//사이즈 줄일라고 그냥 char배열 씀
	char ans[alphabet] = { 0 };
	//배열 -1로 채우기
	fill_n(ans, alphabet, -1);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		//처음 입력된 위치를 기억해둘 것임. 
		//배열이 -1이면 아직 단어가 입력된 적이 없는 상황
		if(ans[str[i]-'a'] == -1)
			//단어의 위치를 배열에 저장
			ans[str[i] - 'a'] = i;
	}
	for (int i = 0; i < alphabet; i++) {
		//char 배열로 선언해둔 상태라 출력할 땐 int로 변환
		cout << (int)ans[i] << " ";
	}

	return 0;
}