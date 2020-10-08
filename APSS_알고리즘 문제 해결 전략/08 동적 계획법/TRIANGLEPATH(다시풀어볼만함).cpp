#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i, n) for(int i = 0; i < n; i++)
using namespace std;

int C, n;
int cache[100][100];
vector <vector <int>> triangle;

int search_tri(int y, int x) {
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	if (y == n - 1) {
		return ret = triangle[y][x];
	}

	ret = max(search_tri(y + 1, x + 1), search_tri(y + 1, x)) + triangle[y][x];
	return ret;
}

int main() {

	cin >> C;
	while (C--) {
		triangle.clear();
		fill(&cache[0][0], &cache[99][99], -1);
		cin >> n;
		triangle.resize(n);
		int num;
		loop(i, n) {
			loop(j, i + 1) {
				cin >> num;
				triangle[i].push_back(num);
			}
		}
		cout << search_tri(0, 0) << "\n"; //y, x 위치에서의 최대 합
	}

}