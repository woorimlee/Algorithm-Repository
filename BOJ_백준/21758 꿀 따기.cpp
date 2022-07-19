#include <iostream>
#include <algorithm>

using namespace std;

int spot[100001], sum_of_honey[100001];
int N, ans;

int main() {
	/*
	�� ���� �� ���� ���°� ���� ������ �� �ִ� ���� �̻����� ��Ȳ.
	������ �Է��� �Ʒ����� ���� ���,
	N = 3
	1 10000 1
	������ 0��° ��ġ�� 2��° ��ġ�� ������ 10000�̳� �Ǵ� ���� ���԰� ��

	���� ��츦 �� �� ���� ������.
	��� 1 : ������ ������ ���� �ִ� ���
		1�� ��(a)�� 0��° ��ġ�� ����
		2�� ��(b)�� 1 ~ N-1 ������ ��򰡿� ��ġ��Ű�鼭 ���� ã��
		- sum_of_honey[i] : 0��° ��ġ���� i��° ��ġ���� ���� ��
		- spot[N] : N���� �� ������ ����� �迭
		a�� ���� �� �ִ� ���� �� : sum_of_honey[N-1] - spot[a] - spot[b]
		b�� ���� �� �ִ� ���� �� : sum_of_honey[N-1] - sum_of_honey[b]

	��� 2 : ������ ���� ���� �ִ� ���
		1�� ��(a)�� N-1�� �ְ�
		2�� ��(b)�� 1 ~ N-1 ������ ��򰡿� ��ġ��Ŵ
		a�� ���� �� �ִ� ���� �� : sum_of_honey[N-2] - spot[b]
		b�� ���� �� �ִ� ���� �� : sum_of_honey[b-1]

	��� 3 : ������ �߰��� �ִ� ���
		1�� ��(a)�� ���� ����
		2�� ��(b)�� ������ ���� �ִ°� ���� �̵�
		������ ��ġ��(c) 1 ~ N-1 ������ ��򰡿� ��ġ��Ŵ
		a�� ���� �� �ִ� ���� �� : sum_of_honey[c] - spot[a]
		b�� ���� �� �ִ� ���� �� : sum_of_honey[N-2] - sum_of_honey[c-1]

	�� ��쿡 ���ؼ� for �������� 1 ~ N-1 ���� �ٲٰ�,
	�ִ� ���� ������
	*/

	//sum_of_honey ����� ���Ǽ��� ���� 0�� ° �ε����� ��� 
	//���� ���� 0���� ����, �Ʒ� �ڵ�� 1���� ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> spot[i];
		sum_of_honey[i] = sum_of_honey[i - 1] + spot[i];
	}

	// ��� 1
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[N] - spot[1] - spot[i]) + (sum_of_honey[N] - sum_of_honey[i]));

	// ��� 2
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[N - 1] - spot[i]) + (sum_of_honey[i - 1]));

	// ��� 3
	for (int i = 2; i < N; i++)
		ans = max(ans, (sum_of_honey[i] - spot[1]) + (sum_of_honey[N - 1] - sum_of_honey[i - 1]));

	cout << ans;
	return 0;
}