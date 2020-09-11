/*
1 ~ N ����. N�� ���� �����
�����ϸ� �����,
���� ���� �������� 1 -> 4 ...
indegree�� 0�̰� ���ڰ� ���� �ͺ���
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
int len;
int indegree[32001];
vector <vector<int> > vec;
priority_queue <int, vector<int>, greater<int> > que;

int main() {
	cin >> N >> M;
	vec.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
		indegree[B]++;
	}
	//���� ���� 0�� ��� ���� ť�� �߰�
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	int cur_node;
	//������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮.
	while (N--) {
		if (que.empty()) {
			printf("����Ŭ �߻�\n");
			return 0;
		}
		cur_node = que.top();
		que.pop();
		cout << cur_node << " ";
		len = vec[cur_node].size();
		for (int i = 0; i < len; i++) {
			if (--indegree[vec[cur_node][i]] == 0) {
				que.push(vec[cur_node][i]);
			}
		}
	}

	return 0;
}
