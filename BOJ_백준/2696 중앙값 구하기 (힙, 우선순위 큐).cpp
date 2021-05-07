#include <iostream>
#include <queue>

using namespace std;

void solve() {
	int n, m;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	cin >> n;
	cout << (n + 1) / 2 << "\n";
	for (int i = 1; i <= n; i++) {
		cin >> m;
		if (maxHeap.size() <= minHeap.size()) 
			maxHeap.push(m);
		else 
			minHeap.push(m);
		
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int maxTop = maxHeap.top(), minTop = minHeap.top();
			maxHeap.pop(), minHeap.pop();
			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		if (i % 2) {
			cout << maxHeap.top() << " ";
			if (i != 0 and i % 10 == 0)
				cout << "\n";
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) 
		solve();
}