#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NUM 9999999

int answer = 0;
bool prime[MAX_NUM + 1] = { false, };
bool visited[MAX_NUM + 1] = { false, };
bool selected[8] = { false };

void dfs(const string& num, string now_s) {
	if (now_s != "") {
		int now_n = stoi(now_s);
		if (!visited[now_n]) {
			visited[now_n] = true;
			if (!prime[now_n]) {
				answer++;
			}
		}
	}
	for (int i = 0; i < num.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			dfs(num, now_s + string(1, num[i]));
			selected[i] = false;
		}
	}
}

int solution(string numbers) {
	prime[0] = true; 
	prime[1] = true;
	for (int i = 2; i * i <= MAX_NUM; i++) {
		if (prime[i] == false)
			for (int j = i * i; j <= MAX_NUM; j += i) {
				prime[j] = true;
			}
	}
	//모든 순열 만들기
	dfs(numbers, ""); //idx, numbers, 만든 문자

    return answer;
}

int main() {
    int s = solution("011");
    cout << s;
    return 0;
}