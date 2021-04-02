#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int K, num;
	stack <int> st;
	cin >> K;

	while (K--) {
		cin >> num;
		if (num)
			st.push(num);
		else
			st.pop();
	}

	long long ans = 0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << "\n";
	return 0;
}