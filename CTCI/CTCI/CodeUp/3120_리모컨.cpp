#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int now, goal;
	cin >> now >> goal;
	//ù ��° int = Ƚ��, �� ��° int = �µ�
	queue<pair<int, int> > que;
	que.push({ 0, now });
	int n, t;
	while (!que.empty()) {
		n = que.front().first;
		t = que.front().second;
		que.pop();
		if (t == goal) {
			cout << n;
			break;
		}
		que.push({ n + 1, t + 1 });
		que.push({ n + 1, t + 5 });
		que.push({ n + 1, t + 10 });
		que.push({ n + 1, t - 1 });
		que.push({ n + 1, t - 5 });
		que.push({ n + 1, t - 10 });
	}

	return 0;
}