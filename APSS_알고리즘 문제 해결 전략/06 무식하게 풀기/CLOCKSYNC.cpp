#include <iostream>
#include <vector>

#define MAXCLOCK 16
#define INF 1234567890

using namespace std;

vector <vector <int> > switches = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

bool areAligned(const vector<int> & final) {
	for (int it : final) {
		if (it != 12) return false;
	}
	return true;
}

int nth_switch(int swi_num, vector <int>& cur_clocks) {
	if (swi_num == switches.size())
		return areAligned(cur_clocks) ? 0 : INF;

	//swi_num번째 스위치를 0~3번 사이로 누르고 다음 스위치 검사
	int cnt = INF;
	for (int i = 0; i < 4; i++) {
		cnt = min(cnt, nth_switch(swi_num + 1, cur_clocks) + i);
		/*if (cnt != INF) {
			for (auto it : cur_clocks) {
				cout << it << " ";
			}cout << "\n";
		}*/
		//누르기
		for (auto it : switches[swi_num]) {
			cur_clocks[it] = (cur_clocks[it] % 12) + 3;
		}
	}
	return cnt;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		vector <int> clocks;
		clocks.resize(MAXCLOCK);
		for (int i = 0; i < MAXCLOCK; i++) {
			cin >> clocks[i];
		}
		int ans = nth_switch(0, clocks);
		ans == INF ? cout << -1 << "\n" : cout << ans << "\n";
	}


	return 0;
}