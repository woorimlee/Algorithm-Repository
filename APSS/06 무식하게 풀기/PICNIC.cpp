#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans;
bool friends[11][11] = { false, };

void make_friend_pair(vector <bool> pick_info, int cnt) {
	//base case 
	//조합 다 찾으면 ans+=1;
	if (cnt == 0) {
		ans++;
		return;
	}
	int i = 0;
	for (i = 0; i < n; i++) {
		if (!pick_info[i]) {
			break;
		}
	}

	for (int j = i + 1; j < n; j++) {
		if (!pick_info[j] && friends[i][j]) {
			pick_info[i] = pick_info[j] = true;
			make_friend_pair(pick_info, cnt - 1);
			pick_info[i] = pick_info[j] = false;
		}
	}
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		ans = 0;
		cin >> n >> m; 
		fill(&friends[0][0], &friends[10][10], false);
		int f1, f2;
		for (int i = 0; i < m; i++) {
			cin >> f1 >> f2;
			friends[f1][f2] = friends[f2][f1] = true;
		}
		vector <bool> fi(n, false);
		make_friend_pair(fi, n/2);
		cout << ans << "\n";
	}

	return 0;
}