#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	vector <int> coin_value(N, 0);

	// 동전의 종류(가치) 입력
	for (int i = 0; i < N; i++)
		cin >> coin_value[i];

	int ans = 0;
	for (vector <int>::reverse_iterator rit = coin_value.rbegin(); rit != coin_value.rend(); rit++) {
		// for 구문이 어떻게 구성된 것인지 아래의 코드를 실행시켜 참고해보세요.
		// cout << *rit; 
		ans += K / (*rit);
		K %= (*rit);
	}

	cout << ans;

	return 0;
}
