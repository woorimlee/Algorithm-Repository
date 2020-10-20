#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cache[501][501];

int search_path(vector<vector<int>>& tri, int y, int x) {
    if (y == tri.size())
        return 0;

    int& ret = cache[y][x];
    if (ret != -1)
        return ret;

    ret = 0;
    ret = max(ret, search_path(tri, y + 1, x) + tri[y][x]);
    ret = max(ret, search_path(tri, y + 1, x + 1) + tri[y][x]);
    return ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    fill(&cache[0][0], &cache[500][501], -1);
    answer = search_path(triangle, 0, 0);
    cout << answer;
    return answer;
}

int main() {
    //[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	
    vector<vector <int> > t = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };
    solution(t);
    return 0;
}