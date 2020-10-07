#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_file_name(vector <string> & sv, int index) {
	char temp = sv[0][index];
	for (int j = 0; j < sv.size(); j++) {
		if (temp != sv[j][index])
			return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector <string> sv; // str_vector
	sv.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> sv[i];
	}
	//이중 포문으로 검사할 것임.
	//첫 번째 포문은 문자열 길이만큼 돌리고
	for (int i = 0; i < sv[0].length(); i++) {
		//두 번째 포문(check_file_name 함수)은 입력받은 문자의 갯수만큼 돌려
		//check_file_name 함수는 입력받은 문자들의 i 번째 인덱스 값이
		//모두 동일하면 true를 리턴하고,
		//하나라도 다르면 false를 리턴하는 bool형의 함수.
		if (check_file_name(sv, i)) {
			cout << sv[0][i];
		}
		else {
			cout << "?";
		}
	}
	return 0;
}