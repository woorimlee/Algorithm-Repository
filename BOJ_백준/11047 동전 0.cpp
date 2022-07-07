#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	vector <int> coin_value(N, 0);

	// ������ ����(��ġ) �Է�
	for (int i = 0; i < N; i++)
		cin >> coin_value[i];

	int ans = 0;
	for (vector <int>::reverse_iterator rit = coin_value.rbegin(); rit != coin_value.rend(); rit++) {
		// for ������ ��� ������ ������ �Ʒ��� �ڵ带 ������� �����غ�����.
		// cout << *rit; 
		ans += K / (*rit);
		K %= (*rit);
	}

	cout << ans;

	return 0;
}
