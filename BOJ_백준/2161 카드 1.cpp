#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	int discard = 0;
	int cur = 0;
	while (q.size() != 1) {
		discard = q.front(); q.pop();
		cout << discard << " ";

		if (q.size() == 1)
			break;

		cur = q.front(); q.pop();
		q.push(cur);
	}

	cout << q.front();
	return 0;
}