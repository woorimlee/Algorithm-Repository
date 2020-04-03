#include <iostream>
#include <queue>

using namespace std;

int N, L;

void solve_1();
int find_min(deque <int>& dq);

int main() {
	cin >> N >> L;

	//슬라이딩 윈도우 
	//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
	//simple하지만 느린 방법
	//solve_1();
	
	return 0;
}

void solve_1() {
	vector <int> v;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector <int> ans;
	deque <int> dq;
	int min;
	for (int i = 0; i < N; i++) {
		if (i < L - 1) {
			dq.push_back(v[i]);
			min = find_min(dq);
			ans.push_back(min);
		}
		else {
			dq.push_back(v[i]);
			min = find_min(dq);
			ans.push_back(min);
			dq.pop_front();
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}

int find_min(deque <int> &dq) {
	int min = 10000000000;
	for (int i = 0; i < dq.size(); i++) {
		if (min > dq[i]) {
			min = dq[i];
		}
	}
	return min;
}