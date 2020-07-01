#include <iostream>
#include <queue>

/*
��Ģ : 
�Ʊ� ���� �ڽ��� ũ�⺸�� �۰ų� ���� ������ �̵� ����
�Ʊ� ���� �ڽź��� �����ָ� ����
�ڱ� ũ�⸸ŭ ����⸦ �Ծ�� ũ�Ⱑ 1����
�ڱ�� ���� ����� �ָ� ����
����� �ְ� �������̸� 1) �� ��, 2) �� ����
���̻� ������ ������ ���α׷� ��

�ڷᱸ�� : 
���� ����� �Թ� ������ ����⸦ ã�� ���� �켱���� ť�� ����� ���̴�.
�켱���� ť�� �⺻������ max heap.
�� ������ �� ���� pop �Ǵ� �����̴ϱ� �켱���� ť�� �� ������ �Ʒ��� ���ǿ� �ش��ϴ� ����Ⱑ ����ִ�.
	1) ���� �Ÿ��� ����� �����
	2) �Ÿ��� ����� ����Ⱑ �����̶�� y�� ���� ��
	3) y���� ������ x�� ���� ��
�� ������ �����ϴ� �ְ� ������ ������ ���� �Ѵ�. (ex. a.x < b.x)

�˰��� 
1. �� ���� ���� ���� ����� ����� bfs�� ã���� �켱����ť�� ����
2. �켱����ť pop�ϰ� �� ����� ��ġ�� �̵��ϸ� �� ���� �� �Ʊ� �� ���� ����� ���� 1 ����
3. ���� ���� ����� ������ �ڽ��� �����Կ� ������ ������ 1 ���� �� ���� ����� ���� �ʱ�ȭ
4. �켱����ť �ʱ�ȭ�ϸ鼭 1 ~ 3 �ݺ�
5. ���̻� ������ ������ ���� ���
�ٸ�, ����⸦ �԰� ����� Ŀ���� ���� Ư�� ��Ȳ�� ������
�Դ� �� ���� ó���ϰ� �� ���� �̵��ϴ� ��쿡 ���� q�� �߰���.
*/

using namespace std;

struct Fish{
	int x, y, dist;
	Fish(int x, int y, int dist) : x{ x }, y{ y }, dist{ dist }{};
	bool operator < (const Fish other) const {
		if (dist == other.dist) {
			if (y == other.y)
				return x > other.x;
			else
				return y > other.y;
		}
		return dist > other.dist;
	}
};
typedef struct Fish Fish; //C������ ȣȯ���� ����

int N, ans;
int s_eat, s_size, s_x, s_y; //shark�� ���� ����, shark ������
int map[21][21];
bool visited[21][21] = { false };
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

void bfs(); // �켱 ����ť�� ���鼭 ����� ã�� �԰�...

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s_x = j;
				s_y = i;
				map[i][j] = 0;
			}
		}
	}

	s_size = 2;
	bfs();
	cout << ans;

	return 0;
}
void bfs() {
	priority_queue<Fish> pq;
	pq.push({ s_x, s_y, 0 });

	int x, y, dist, nx, ny;
	Fish temp(0, 0, 0);
	while (!pq.empty()) {
		temp = pq.top();
		pq.pop();
		x = temp.x;
		y = temp.y;
		dist = temp.dist;
		/*
		cout << x << " " << y << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}cout << "\n";
		*/
		//����� �Ա�
		if (0 < map[y][x] && map[y][x] < s_size) {
			//����� ���ֱ�, ���� ���� ���� ���� �۾�
			map[y][x] = 0;
			ans += dist; //���� ����
			dist = 0;
			s_eat++; 
			fill(&visited[0][0], &visited[20][21], false);
			while (!pq.empty())
				pq.pop();
			//���� ���� ������� ��������
			if (s_eat == s_size) {
				s_eat = 0;
				s_size++;
			}
		}

		//�̵���Ű��
		for (int i = 0; i < 4; i++) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[ny][nx]) {
				if (0 <= map[ny][nx] && map[ny][nx] <= s_size) {
					pq.push({ nx, ny, dist + 1 });
					visited[ny][nx] = true;
				}
			}
		}
	}
}