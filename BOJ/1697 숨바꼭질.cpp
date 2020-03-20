#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001] = { false };
//�������� ��ġ ��, �ɸ� �ð��� �������
queue <pair<int, int> > sb;

int main(void) {
	
	cin >> N >> K;

	sb.push({ N, 0 });
	visited[N] = true;
	pair <int, int> cp; //current position
	while (!sb.empty()) {
		cp = sb.front();
		sb.pop(); 
		
		//�������� ��ġ�� ������ ��ġ�� ���ٸ�
		if (cp.first == K) {
			cout << cp.second;
			return 0;
		}

		//bfs�� Ž���� ���� 
		//1) ������ġ -1
		//2) ������ġ +1
		//3) ������ġ *2
		int calc[3] = { cp.first - 1, cp.first + 1, cp.first * 2 };
		for (int i = 0; i < 3; i++) {
			if (0 <= calc[i] && calc[i] < 100001) {
				if (!visited[calc[i]]) {
					sb.push({ calc[i], cp.second + 1 });
					visited[calc[i]] = true;
				}
			}
		}
	}
	return 0;
}

/* �Ʒ��� �ڵ带 for������ �迭�� �Ἥ ���� ���� �ٲ�
#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001] = { false };
//�������� ��ġ ��, �ɸ� �ð��� �������
queue <pair<int, int> > sb;

int main(void) {

	cin >> N >> K;

	sb.push({ N, 0 });
	visited[N] = true;
	pair <int, int> cp; //current position
	while (!sb.empty()) {
		cp = sb.front();
		sb.pop();

		//�������� ��ġ�� ������ ��ġ�� ���ٸ�
		if (cp.first == K) {
			cout << cp.second;
			return 0;
		}

		//bfs�� Ž���� ����
		//1) ������ġ -1
		//2) ������ġ +1
		//3) ������ġ *2

		//1)
		//���� ��ġ - 1�� 0���ٴ� Ŀ����
		if (cp.first - 1 >= 0) {
			if ((!visited[cp.first - 1])) {
				sb.push({ cp.first - 1, cp.second + 1 });
				visited[cp.first - 1] = true;
			}
		}

		//2)
		if (cp.first + 1 < 100001) {
			if (!visited[cp.first + 1]) {
				sb.push({ cp.first + 1, cp.second + 1 });
				visited[cp.first + 1] = true;
			}
		}

		//3)
		//��ġ�� 100000 �̻��� �� �ƿ� ó������ �ʾƵ� �Ǵ� �����ε� ��
		if (cp.first * 2 < 100001) {
			if (!visited[cp.first * 2]) {
				sb.push({ cp.first * 2, cp.second + 1 });
				visited[cp.first * 2] = true;
			}
		}
	}
	return 0;
}
*/