#include <iostream>

using namespace std;

int arr[7];
int n;

void dfs(int k) {
	if (k > 7) {
		cout << n << " ";
		for (int i = 0; i < 7; i++) {
			cout << arr[i] << " ";
		}
		return;
	}

	arr[k] = 1;
	dfs(k + 1);
}

int main() {
	cin >> n;
	dfs(0);
	return 0;
}