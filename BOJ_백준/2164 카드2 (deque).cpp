#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 1;
	cin >> N;

	deque<int> dq;
	
	//[0]��° �ε����� ���� ���� �ִ� ī���� ����
	//1���� N���� ī�� ��ȣ�� dq�� ������ ��
	dq.resize(N);
	for (int i = 0; i < N; i++) {
		dq[i] = i + 1;
	}

	int card;
	//�� �� ī��� ������ �� �������� ���� �ִ� ī�带 �� ������
	while (dq.size() != 1) {
		dq.pop_front();
		card = dq.front();
		dq.pop_front();
		dq.push_back(card);
	}
	cout << dq.front();

	return 0;
}