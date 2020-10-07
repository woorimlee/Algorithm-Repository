#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//조건을 만족하는 최대, 최소 숫자를 찾을 것이니
//현재 찾은 정답을 저장할 str
//min_str, max_str 세 개 변수 필요

int n;
char inequal[10];
bool visited[10] = { false, };
string str = "";
string min_str = "9999999999";
string max_str = "-1";

//prev에 이전 숫자 값
void dfs(int prev, int current) {
	if (current == n + 1) {
		min_str = min(min_str, str);
		max_str = max(max_str, str);
		return;
	}

	if (inequal[current - 1] == '>') {
		//이전에 온 값보다 작은 걸 넣어
		for (int i = 0; i < prev; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				dfs(i, current + 1);
				visited[i] = false;
				str.erase(current, 1);
			}
		}
	}
	else if (inequal[current - 1] == '<') {
		//이전에 온 값보다 큰 걸 넣어
		for (int i = prev + 1; i <= 9; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				dfs(i, current + 1);
				visited[i] = false;
				str.erase(current, 1);
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	//2를 받음
	//최소 값인 021과 최대 값인 897을 출력하고 싶어.
	//0에서 시작, 9에서 시작 두 번 돌리자
	for (int i = 0; i < n; i++) {
		cin >> inequal[i];
	}

	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		str += (char)(i + '0');
		dfs(i, 1);
		visited[i] = false;
		str.erase(0, 1);
	}

	cout << max_str << "\n" << min_str;

	return 0;
}