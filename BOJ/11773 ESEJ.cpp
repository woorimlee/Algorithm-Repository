#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int temp = 0;

	string str;
	for (int i = 1; i <= B; i++) {
		str = "";
		temp = i;
		//중복 문자경우의 수가 있어서 새 a나 b부터 z까지 출력해놓은 상태라고 하면,
		//다음에는 aa, 이런 식으로 다른 문자를 출력할 수 있게 수정해야함.
		while (temp > 0) {
			str += (char)(temp % 26 + 'a');
			temp /= 26;
		}
		cout << str << " ";
	}
	cout << "\n";
	return 0;
}