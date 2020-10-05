/*
분할 정복을 할 거면
반 쪼개고 쪼갠거에 대해서 문제를 어떻게 풀 건지 생각해보고
답을 어떻게 합 칠지 생각해보면 되겠구나.

N^2꼴로는 문제를 풀기 힘드니 문제를 반씩 쪼개보자.
나무 판자의 중간 경계선을 기준으로 다음의 세 가지 경우의 수가 있음.
1) 왼쪽 구역에서 최대 크기의 직사각형이 나온다.
2) 오른쪽 구역에서 최대 크기의 직사각형이 나온다.
3) 경계선이 포함된 부분에서 최대 크기의 직사각형이 나온다.

이를 가장 base case인 판자 두 개로 이뤄진 울타리에 적용해보자.

find_max_fence(left, right) {
	if left == right
		return plank[left]; // 높이 return

	//경계선 기준 왼쪽 판자와 오른쪽 판자 left, right 값 가르기
	//1)과 2)를 아래에서 해결
	int ret = max( find_max_fence(왼쪽 판자), find_max_fence(오른쪽 판자) );

	//3) 경계선이 포함된 부분에서 전체 울타리를 살펴보며 최대 직사각형 크기 구하기
	int mid = (right + left) / 2
	//짝수개면 중간왼쪽, 홀수면 중간
	중간 기준 왼쪽 or 오른쪽 중 자기보다 큰 곳을 찾아


	//1) & 2)의 결과와 3)의 결과 중 max 확인해서 return

	//1 2 3 -> m 기준으로 왼쪽 확장
	//1 3 2 -> 노 상관
	//2 1 3 -> m 기준으로 왼쪽 확장
	//2 3 1 -> 노상관
	//3 1 2 -> m 기준으로 오른쪽 확장
	//3 2 1 -> m 기준으로 오른쪽 확장
	//왼쪽 오른쪽 중 더 큰 곳 찾아서 확장하자.
	lp = mid, rp = mid + 1;
	height = min(plank[lp], plank[rp]);
	while( left <= lp && rp <= right) {
		ret = max(ret, height * (rp - lp + 1));
		//lp-- : 왼쪽이 오른쪽보다 더 크거나, 오른쪽 다 찾은 경우.
		if((lp - 1) >= left && (plank[lp] > plank[rp] || rp == right)) {
			lp--;
			height = min(height, plank[lp]);
		}
		else {
			rp++;
			height = min(height, plank[rp]);
		}
	}
	return ret;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;

int find_max_fence(const vector <int>& plank, int left, int right) {
	//cout << left << " " << right << "\n";
	if (left == right)
		return plank[left];

	int mid = (left + right) / 2;
	int ret = max(find_max_fence(plank, left, mid), find_max_fence(plank, mid + 1, right));
	//cout << " left & right & ret : " << left << " " << right << " " << ret << " ";
	int lp = mid;
	int rp = mid + 1;
	int height = min(plank[lp], plank[rp]);
	ret = max(ret, height * (rp - lp + 1));

	//cout << "-> lp, rp, ret : ";
	while (left < lp || rp < right) {
		//cout << lp << " " << rp << " " << ret << " / ";
		if (rp < right && (lp == left || plank[lp - 1] < plank[rp + 1])) {
			rp++;
			height = min(height, plank[rp]);
		}
		else {
			lp--;
			height = min(height, plank[lp]);
		}
		ret = max(ret, height * (rp - lp + 1));
	}
	//cout << " last ret : " << ret << "\n";
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector <int> plank;
		int h;
		for (int i = 0; i < N; i++) {
			cin >> h;
			plank.push_back(h);
		}
		cout << find_max_fence(plank, 0, N - 1) << "\n";
	}
	return 0;
}