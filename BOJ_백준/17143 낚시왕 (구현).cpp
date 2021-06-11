#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, M, ans;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

struct SHARK {
	bool dead;
	int r, c, s, d, z; //��ġ, �ӷ�, �̵� ����, ũ��
	// d = 1 ~ 4 = ��, �Ʒ�, ������, ����

	SHARK() {}
	SHARK(int r, int c, int s, int d, int z) : r{ r }, c{ c }, s{ s }, d{ d }, z{ z } {
		if (d <= 2)
			this->s %= ((R - 1) * 2);
		else
			this->s %= ((C - 1) * 2);
		dead = false;
		this->d--; // 0 ~ 3���� ����
	}

	void move()
	{
		for (int i = 0; i < s; i++)
		{
			// ��� ���� ��ȯ
			if (d == 0 && r == 1) 
				d = 1;
			else if (d == 1 && r == R) 
				d = 0;
			else if (d == 2 && c == C) 
				d = 3;
			else if (d == 3 && c == 1) 
				d = 2;

			r += dy[d];
			c += dx[d];
		}
	}
};

vector<SHARK> shark_info;
int shark_pos[101][101];

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> R >> C >> M;
	shark_info.resize(M);
	fill(&shark_pos[0][0], &shark_pos[100][101], -1);

	int tr, tc, ts, td, tz;
	for (int i = 0; i < M; i++) {
		cin >> tr >> tc >> ts >> td >> tz;
		SHARK tShark(tr, tc, ts, td, tz);
		shark_info[i] = tShark;
		shark_pos[tr][tc] = i;
	}

	if (M == 0) {
		cout << 0;
		return 0;
	}

	// 1. ���ÿ� 1�� ������
	for (int i = 1; i <= C; i++) {
		// 2. ���� ������ ����� ��� ���
		for (int j = 1; j <= R; j++) {
			const int& idx = shark_pos[j][i];
			if (idx != -1 && shark_info[idx].dead == false)
			{
				ans += shark_info[idx].z;
				shark_info[idx].dead = true;
				break; // 3�� ����
			}
		}

		// ��� ���̵� �� ���ø� �ϴ� ������ �ʱ�ȭ
		fill(&shark_pos[0][0], &shark_pos[100][101], -1);

		// 3. ��� �̵�
		for (int k = 0; k < M; k++) {
			
			SHARK& sh = shark_info[k];

			// �̵� ������ ���� �̵�
			if (sh.dead) 
				continue;
			sh.move();

			//�̵��� ���� �Է� | ��� ��ƸԱ�
			int& idx = shark_pos[sh.r][sh.c];
			if (idx == -1) // �̵� ���� �Է�
				idx = k; 
			else { // ��� ��ƸԱ�
				if (shark_info[idx].z < sh.z)
				{
					shark_info[idx].dead = true;
					idx = k;
				}
				else shark_info[k].dead = true;
			}
		}
	}

	cout << ans;
	return 0;
}