#include <iostream>
#include <vector>
#include <map>
using namespace std;

//추의 개수
int N;
//추 종류
vector <int> chu_list;
//확인하고자 하는 구슬의 개수
int M;
//구슬 종류
vector <int> gu_list;
//가능한 구슬 종류 저장할 곳
map <pair<int, int>, bool> ans_list;


void scales(int cur, int now_weight) { //cur == current
	// 무게를 구할 수 있는 방법은 두 가지
	//1. 구슬 + 추 == 추
	//2. 구슬 == 추
	if (ans_list[{cur, now_weight}]) {
		return;
	}
	
	ans_list[{cur, now_weight}] = true;

	if (cur >= N) {
		return;
	}
	//1.의 경우 빼기 연산
	//2.의 경우 더하기 연산
	//그 외 : 현재 추 안 쓰기
	scales(cur + 1, now_weight + chu_list[cur]);
	scales(cur + 1, abs(now_weight - chu_list[cur]));
	scales(cur + 1, now_weight);
}

int main() {
	
	//입력
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		chu_list.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		gu_list.push_back(temp);
	}

	//구슬 가능한지 확인s
	scales(0, 0);

	//출력
	for (int i = 0; i < M; i++) {
		if (ans_list[{N, gu_list[i]}]) {
			cout << "Y ";
		}
		else cout << "N ";
	}
	return 0;
}