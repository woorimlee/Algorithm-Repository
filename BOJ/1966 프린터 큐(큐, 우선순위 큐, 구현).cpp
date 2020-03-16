#include <iostream>
#include <queue>

using namespace std;

int T, N, M, cnt;
int imp; //imp == important. �߿䵵 �Է� ���� ����

/*
ť�� ���� �� ������ ���� �߿䵵�� ���� ���¶�� ����Ʈ 
�ƴ϶�� ������ �з���.
ex) 6 0
1(0��°) 1(...) 9 1 1 1
ó�� ť �˻翡�� 0��°�� ������ ��� ���� �� �ڷ�
�� ��° ť �˻翡�� 1��° ������ ��� ���� �� �ڷ�
9 1 1 1 1(6��°) 1(0��°) 1(1��°)
*/

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cnt = 1;
		cin >> N >> M;
		queue<pair<int, int> > q;
		//�켱���� ť�� ť�� ���� ������ ������������(�ٲ� �� ����)
		priority_queue<int> pq;
		pair<int, int> temp;
		for (int j = 0; j < N; ++j) {
			cin >> imp;
			q.push({ j, imp });
			pq.push(imp);
		}

		//�߿䵵�� ��ġ�ϰ� ���ϴ� ��� ������ ������ ã�� ������
		while (q.front().second != pq.top() || q.front().first != M) {
			temp = q.front();
			q.pop();
			//cout << temp.first << " " << temp.second << "\n";
			if (temp.second == pq.top()) {
				//cout << "if\n";
				pq.pop();
				//������ ������ �þ�� ���� ����� �ϴ� ��쿡�� �þ
				//�켱���� ������ �ϳ��� �������Ҷ� �þ�ٴ� ��
				cnt++;
				continue;
			}
			q.push(temp);
		} 
		cout << cnt << "\n";
	}
	return 0;
}
