#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, color;
		cin >> N;
		vector <vector<int> > cnt_edge_colors(N, { 0, 0 });
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				cin >> color;
				cnt_edge_colors[i][color]++;
				cnt_edge_colors[j][color]++;
			}
		} 
		// cnt_edge_colors[i][0] = (i+1)번째 꼭짓점에서 파란색 선 갯수
		// cnt_edge_colors[i][0] = (i+1)번째 꼭짓점에서 빨간색 선 갯수

		int cnt_non_monocolors = 0;
		for (vector <int>& cnt_edge_color : cnt_edge_colors) 
			cnt_non_monocolors += cnt_edge_color[0] * cnt_edge_color[1];
		
		int nCm = (N * (N - 1) * (N - 2)) / (3 * 2 * 1);

		cout << (nCm - cnt_non_monocolors / 2) << "\n";
	}
	return 0;
}