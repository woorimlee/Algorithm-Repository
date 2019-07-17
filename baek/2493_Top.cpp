#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n, value;
	cin >> n;
	stack < pair <int, int>  > mp;
	queue <int> answer;

	for (int i = 1; i <= n; i++) {
		cin >> value;

		while (!mp.empty()) {
			
			//1:6보다 작은 2:5가 왔다면
			if (mp.top().second > value) {
				//그냥 바로 출력
				answer.push(mp.top().first);
				break;
			}
			//1:6보다 큰 게 왔다면
			else if (mp.top().second <= value) {
				mp.pop();
			}
		}

		if (mp.empty()) answer.push(0);

		mp.push(make_pair(i, value)); // 1 : 6

	}

	for (int i = 0; i < n; i++) {
		cout << answer.front() << " ";
		answer.pop();
	}


	return 0;
}