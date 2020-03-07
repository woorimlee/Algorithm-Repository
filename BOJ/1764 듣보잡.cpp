#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M, ans = 0;
//bool 값이 true면 듣도 못하거나 보도 못한 사람 (둘 중 하나)
//bool 값이 false면 듣보잡
//map은 기본 false로 초기화
map <string, bool> emeqh; //듣보 = emeqh
int main() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N + M; i++) {
		cin >> str;
		//듣도 못한 사람 혹은 보도 못한 사람으로
		//이름이 한 번 주어지면 true로 바꿈
		if (emeqh[str] == false) {
			emeqh[str] = true;
		}
		//듣도 못한 사람 & 보도 못한 사람
		//명단으로 두 번 주어진 경우에 해당 
		else {
			emeqh[str] = false;
			ans++;
		}
	}
	cout << ans << "\n";
	for (auto it : emeqh) {
		if (it.second == false) {
			cout << it.first << "\n";
		}
	}

	return 0;
}