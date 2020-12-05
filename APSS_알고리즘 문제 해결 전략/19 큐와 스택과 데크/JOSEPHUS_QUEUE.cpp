#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//기존에 풀었던 방식. O(N^2)
void josephus(int N, int K) { 
	queue <int> survivors;
	for (int i = 1; i <= N; i++) {
		survivors.push(i);
	}

	int survive;
	while (survivors.size() > 2) { 
		survivors.pop(); //자살
		for (int i = 0; i < K - 1; i++) {
			survive = survivors.front();
			survivors.pop();
			survivors.push(survive);
		}
	}
	vector <int> answer = { survivors.front(), survivors.back() };
	sort(answer.begin(), answer.end());
	cout << answer[0] << " " << answer[1] << "\n";
}

int main() {
	int C, N, K;
	cin >> C;
	while (C--) {
		cin >> N >> K;
		josephus(N, K);
	}
	return 0;
}