#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, M, ans;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

struct SHARK {
	bool dead;
	int r, c, s, d, z; //위치, 속력, 이동 방향, 크기
	// d = 1 ~ 4 = 위, 아래, 오른쪽, 왼쪽

	SHARK() {}
	SHARK(int r, int c, int s, int d, int z) : r{ r }, c{ c }, s{ s }, d{ d }, z{ z } {
		if (d <= 2)
			this->s %= ((R - 1) * 2);
		else
			this->s %= ((C - 1) * 2);
		dead = false;
		this->d--; // 0 ~ 3으로 만듦
	}

	void move()
	{
		for (int i = 0; i < s; i++)
		{
			// 경계 방향 전환
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

	// 1. 낚시왕 1열 움직임
	for (int i = 1; i <= C; i++) {
		// 2. 가장 땅에서 가까운 상어 잡기
		for (int j = 1; j <= R; j++) {
			const int& idx = shark_pos[j][i];
			if (idx != -1 && shark_info[idx].dead == false)
			{
				ans += shark_info[idx].z;
				shark_info[idx].dead = true;
				break; // 3번 실행
			}
		}

		// 상어 재이동 전 낚시를 하는 격자판 초기화
		fill(&shark_pos[0][0], &shark_pos[100][101], -1);

		// 3. 상어 이동
		for (int k = 0; k < M; k++) {
			
			SHARK& sh = shark_info[k];

			// 이동 가능한 상어면 이동
			if (sh.dead) 
				continue;
			sh.move();

			//이동한 정보 입력 | 상어 잡아먹기
			int& idx = shark_pos[sh.r][sh.c];
			if (idx == -1) // 이동 정보 입력
				idx = k; 
			else { // 상어 잡아먹기
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