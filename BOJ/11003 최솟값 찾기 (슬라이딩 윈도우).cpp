#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, L;

void solve_1();
void solve_2();
int find_min(deque <int>& dq);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;

	//슬라이딩 윈도우 
	//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
	//simple하지만 느린 방법
	//solve_1();
	solve_2();
	return 0;
}

void solve_1() {
	vector <int> v;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector <int> ans;
	deque <int> dq;
	int min;
	for (int i = 0; i < N; i++) {
		if (i < L - 1) {
			dq.push_back(v[i]);
			min = find_min(dq);
			ans.push_back(min);
		}
		else {
			dq.push_back(v[i]);
			min = find_min(dq);
			ans.push_back(min);
			dq.pop_front();
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return;
}

int find_min(deque <int> &dq) {
	int min = 10000000000;
	for (int i = 0; i < dq.size(); i++) {
		if (min > dq[i]) {
			min = dq[i];
		}
	}
	return min;
}

void solve_2() {
	//Deque(Double ended queue)을 이용한 기법으로,
	//주어진 배열에 슬라이딩 윈도우를 적용시켜서 해당 윈도우내에 있는 최솟값을 덱의 front에 둘 예정.
	vector <int> arr(N);
	int i;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//덱에는 arr 배열의 슬라이딩 인덱스가 적용된 부분에서
	//최솟값과 관계된 부분의 인덱스를 저장할 것임.
	deque <int> dq;

	/*
	//첫 번째 슬라이딩 윈도우를 만들기까지 처리
	for (i = 0; i < L; i++) {
		//dq의 front에는 가장 작은 값이 들어있을 것임.
		//dq의 back에는 작은 값 후보들(윈도우가 슬라이딩되며 front가 인덱스 초과시 pop 됨)
		//이 있는데, 그 후보보다 새로 검사하는 arr[i] 값이 더 작으면
		//후보 갱신
		while ((!dq.empty()) && arr[dq.back()] > arr[i]) {
			dq.pop_back();
		}

		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}

	//k개의 배열을 바라보는 슬라이딩 윈도우가 생성된 이후임.
	//한 칸씩 밀어가면서 최솟값 찾기
	for (; i < N; i++) {
		//인덱스가 윈도우 넘어갔으면 pop
		while ((!dq.empty()) && dq.front() <= i - L) {
			dq.pop_front();
		}
		while ((!dq.empty()) && arr[dq.back()] > arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}*/

	//보통은 위 두 개로 나눠야하는 데,
	//이 문제는 하나로 합쳐도 상관없어서 아래처럼 함.
	for (i = 0; i < N; i++) {
		//인덱스가 윈도우 넘어갔으면 pop
		while ((!dq.empty()) && dq.front() <= i - L) {
			dq.pop_front();
		}
		while ((!dq.empty()) && arr[dq.back()] > arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}

	return;
}