#include <iostream>
#include <algorithm>

using namespace std;

int spot[100001], sum_of_honey[100001];
int N, ans;

int main() {
	/*
	벌 통을 양 끝에 놓는게 쉽게 생각할 수 있는 가장 이상적인 상황.
	하지만 입력이 아래같이 들어온 경우,
	N = 3
	1 10000 1
	벌통을 0번째 위치나 2번째 위치에 놓으면 10000이나 되는 꿀을 못먹게 됨

	따라서 경우를 총 세 개로 나눈다.
	경우 1 : 벌통이 오른쪽 끝에 있는 경우
		1번 벌(a)은 0번째 위치에 놓고
		2번 벌(b)은 1 ~ N-1 사이의 어딘가에 위치시키면서 답을 찾음
		- sum_of_honey[i] : 0번째 위치부터 i번째 위치까지 꿀의 합
		- spot[N] : N개의 꿀 정보가 저장된 배열
		a가 얻을 수 있는 꿀의 양 : sum_of_honey[N-1] - spot[a] - spot[b]
		b가 얻을 수 있는 꿀의 양 : sum_of_honey[N-1] - sum_of_honey[b]

	경우 2 : 벌통이 왼쪽 끝에 있는 경우
		1번 벌(a)은 N-1에 있고
		2번 벌(b)은 1 ~ N-1 사이의 어딘가에 위치시킴
		a가 얻을 수 있는 꿀의 양 : sum_of_honey[N-2] - spot[b]
		b가 얻을 수 있는 꿀의 양 : sum_of_honey[b-1]

	경우 3 : 벌통이 중간에 있는 경우
		1번 벌(a)은 왼쪽 끝에
		2번 벌(b)은 오른쪽 끝에 있는게 제일 이득
		벌통의 위치를(c) 1 ~ N-1 사이의 어딘가에 위치시킴
		a가 얻을 수 있는 꿀의 양 : sum_of_honey[c] - spot[a]
		b가 얻을 수 있는 꿀의 양 : sum_of_honey[N-2] - sum_of_honey[c-1]

	각 경우에 대해서 for 구문으로 1 ~ N-1 값을 바꾸고,
	최대 값을 갱신함
	*/

	//sum_of_honey 계산의 편의성을 위해 0번 째 인덱스를 비움 
	//위의 식은 0부터 시작, 아래 코드는 1부터 시작
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> spot[i];
		sum_of_honey[i] = sum_of_honey[i - 1] + spot[i];
	}

	// 경우 1
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[N] - spot[1] - spot[i]) + (sum_of_honey[N] - sum_of_honey[i]));

	// 경우 2
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[N - 1] - spot[i]) + (sum_of_honey[i - 1]));

	// 경우 3
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[i] - spot[1]) + (sum_of_honey[N - 1] - sum_of_honey[i - 1]));

	cout << ans;
	return 0;
}