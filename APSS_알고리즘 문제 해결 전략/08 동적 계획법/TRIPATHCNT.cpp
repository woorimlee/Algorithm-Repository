//캐시 배열을 두 개 만들자.
//하나만 만들어도 (이전에 풀었을 때 썼던 cache) 문제는 풀린다만,
//속도 차이가 100배가 남.

#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i, n) for(int i = 0; i < n; i++)
using namespace std;

int C, n;
int cache[101][101];
vector <vector <int>> triangle;

int search_path(int y, int x) {
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	if (y == n - 1) {
		return ret = triangle[y][x];
	}

	ret = max(search_path(y + 1, x + 1), search_path(y + 1, x)) + triangle[y][x];
	return ret;
}

int cnt_cache[101][101];
int cnt_path(int y, int x) {
	if (y == n - 1)
		return 1;
	int& ret = cnt_cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	if(search_path(y+1, x+1) >= search_path(y + 1, x))
		ret += cnt_path(y + 1, x + 1);
	if (search_path(y + 1, x) >= search_path(y + 1, x + 1))
		ret += cnt_path(y + 1, x);
	return ret;
}

int main() {

	cin >> C;
	while (C--) {
		cin >> n;
		fill(&cache[0][0], &cache[n][n + 1], -1);
		fill(&cnt_cache[0][0], &cnt_cache[n][n + 1], -1);
		triangle.clear();
		triangle.resize(n);
		int num;
		loop(i, n) {
			loop(j, i + 1) {
				cin >> num;
				triangle[i].push_back(num);
			}
		}
		cout << cnt_path(0, 0) << "\n";
	}
	return 0;
}