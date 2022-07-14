#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int N_card[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector <int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	cin >> M;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (binary_search(arr.begin(), arr.end(), temp))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	return 0;
}