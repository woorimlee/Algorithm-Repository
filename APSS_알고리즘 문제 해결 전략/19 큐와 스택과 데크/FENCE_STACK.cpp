#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;

int fence_max_size(vector <int>& fence) {
	stack <int> st;
	int ans = 0;

	for (int i = 0; i < fence.size(); i++) {
		while (!st.empty() && fence[st.top()] >= fence[i]) {
			int j = st.top(); st.pop();
			int width = -1;
			if (st.empty())
				width = i;
			else
				width = (i - 1 - st.top());
			ans = max(ans, fence[j] * width);
		}
		st.push(i);
	}
	return ans;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N;
		vector <int> fence(N+2, 0);
		for (int i = 1; i <= N; i++)
			cin >> fence[i];
		cout << fence_max_size(fence) << "\n";
	}
	return 0;
}