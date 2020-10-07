#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string N;
//0 ~ 9까지 숫자 나온 횟수를 저장할 배열
int room_num[10] = { 0 };
int max_num=INT_MIN;

int main() {
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		//N에 9999가 string 형태로 입력되었고,
		//N을 각 인덱스로 접근하면 '9'라는 char로 취급되니까
		//-'0'을 해서 숫자로 바꿔줌.
		room_num[N[i] - '0']++;
	}
	//6과 9는 바꿔쓸 수 있으니 9999 -> 6 두 개, 9 두 개, 
	// 99999 -> 6 세 개, 9 두 개 -> 총 세 세트를 계산하기 위한 식
	int temp_max = (room_num[6] + room_num[9] + 1) / 2;
	for (int i = 0; i <= 9; i++) {
		//최대 필요한 세트 갯수 파악
		(i != 6 && i != 9) ? max_num = max(max_num, room_num[i]) : max_num = max(max_num,temp_max);
	}
	cout << max_num;
	return 0;
}