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

	//�����̵� ������ 
	//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
	//simple������ ���� ���
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
	//Deque(Double ended queue)�� �̿��� �������,
	//�־��� �迭�� �����̵� �����츦 ������Ѽ� �ش� �����쳻�� �ִ� �ּڰ��� ���� front�� �� ����.
	vector <int> arr(N);
	int i;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//������ arr �迭�� �����̵� �ε����� ����� �κп���
	//�ּڰ��� ����� �κ��� �ε����� ������ ����.
	deque <int> dq;

	/*
	//ù ��° �����̵� �����츦 �������� ó��
	for (i = 0; i < L; i++) {
		//dq�� front���� ���� ���� ���� ������� ����.
		//dq�� back���� ���� �� �ĺ���(�����찡 �����̵��Ǹ� front�� �ε��� �ʰ��� pop ��)
		//�� �ִµ�, �� �ĺ����� ���� �˻��ϴ� arr[i] ���� �� ������
		//�ĺ� ����
		while ((!dq.empty()) && arr[dq.back()] > arr[i]) {
			dq.pop_back();
		}

		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}

	//k���� �迭�� �ٶ󺸴� �����̵� �����찡 ������ ������.
	//�� ĭ�� �о�鼭 �ּڰ� ã��
	for (; i < N; i++) {
		//�ε����� ������ �Ѿ���� pop
		while ((!dq.empty()) && dq.front() <= i - L) {
			dq.pop_front();
		}
		while ((!dq.empty()) && arr[dq.back()] > arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}*/

	//������ �� �� ���� �������ϴ� ��,
	//�� ������ �ϳ��� ���ĵ� ������ �Ʒ�ó�� ��.
	for (i = 0; i < N; i++) {
		//�ε����� ������ �Ѿ���� pop
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