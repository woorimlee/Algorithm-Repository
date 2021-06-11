#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int N;
string blog;

int main() {
	cin >> N >> blog;

	// 일우의 최적화 색칠 방법을 분석해보면
	// 두 색 중 가장 부분 색이 많은 걸로 한 번 쫙 칠하고
	// 나머지를 남은 색으로 칠함
	
	unordered_map <char, int> cnt;
	char c = blog[0];
	for (int i = 1; i < blog.size(); i++) 
		if (c != blog[i]) {
			cnt[c]++;
			c = blog[i];
		}
	cnt[c]++;

	int ans = 1 + min(cnt['B'], cnt['R']);
	cout << ans;

	return 0;
}