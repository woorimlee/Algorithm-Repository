#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define loop(i, n) for(int i = 0; i < n; i++)

using namespace std;

int C, N;
int cache[101][101];
string wcp, fs; //wild card pattern, file string
vector <string> ans;

bool match_str(int w, int f) {
	if (f > fs.size())
		return 0;
	//cout << w << " " << f << "\n";
	int& ret = cache[w][f];
	if (ret != -1)
		return ret;
	while (w < wcp.size() && f < fs.size() && (wcp[w] == fs[f] || wcp[w] == '?')) {
		w++;
		f++;
	}
	//cout << w << f << "\n";
	if (w == wcp.size()) {
		ret = (f == fs.size()); //둘 다 끝난 경우.
		return ret;
	}
	if (wcp[w] != '*')
		return 0; //문자가 다른 경우
	else {
		ret = match_str(w + 1, f) || match_str(w , f + 1);
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		ans.clear();
		cin >> wcp;
		cin >> N;
		while (N--) {
			fill(&cache[0][0], &cache[100][100], -1);
			cin >> fs;
			if (match_str(0, 0))
				ans.push_back(fs);
		}
		sort(ans.begin(), ans.end());
		for (string it : ans)
			cout << it << "\n";
	}
}