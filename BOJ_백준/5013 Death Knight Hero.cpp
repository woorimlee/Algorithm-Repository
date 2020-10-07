#include <iostream>
#include <string>
using namespace std;

bool check_dc(string &ki) {
	//i번째와 i+1번째를 동시에 검사하니 for 두 번째 구문에서 -1 해줘야 함.
	for (int i = 0; i < ki.length() - 1; i++) {
		//C뒤에 D가 오는 경우에 문제가 되는 거였음.
		if (ki[i] == 'C' && ki[i + 1] == 'D')
			return false;
	}
	return true;
}

int main() {
	int n, ans = 0;
	cin >> n;
	string ki;
	//n번의 전투를 입력받고 이겼는지 검사함
	while (n--) {
		cin >> ki;
		//n번째 전투가 이겼는지 검사해서 
		//true면 이긴 것으로, false면 진 것으로 처리함.
		//졌을 땐 아무것도 안 함
		if (check_dc(ki)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
