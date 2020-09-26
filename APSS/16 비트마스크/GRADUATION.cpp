#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAXN 12
#define MAXM 10
#define MAXSEMESTER 20
using namespace std;

int C;
int N, K, M, L;
int prerequisite[MAXN]; // 전공 과목별 선수 과목 집합
int sem_class[MAXM]; // 학기별 개설되는 과목 집합
int cache[MAXM][1 << MAXN];

//se = 특정 학기, taken = 지금까지 들은 과목의 집합
int graduate(int se, int taken) { //이번 semester에 taken + K에 수강해서 졸업할 수 있는 최소 학기의 수를 return
	//기저 조건
	//1. 다 들었다
	if (__builtin_popcount(taken) >= K)
		return 0;
	//2. 학기가 부족하다
	if (se >= M)
		return MAXSEMESTER;

	int& ret = cache[se][taken];
	if (ret != -1)
		return ret;

	ret = MAXSEMESTER;
	//canTake 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목 집합
	int can_take = (sem_class[se] & (~taken));

	//canTake의 과목 집합 중 선수과목을 듣지 않은 것들은 제거한다.
	for (int i = 0; i < N; i++) { //i = 과목 번호
		//canTake & (1 << i) : 이번 학기에 들을 수 있는 과목 중 아직 듣지 않았던 과목을 찾음
		//taken & prerequisite[i]) != prerequisite[i] : 들었던 과목과 i번째 과목의 선수과목을 비교해서 선수과목의 비트가 모두 도출되면 모두 들은것임
		if ((can_take & (1 << i)) && ((taken & prerequisite[i]) != prerequisite[i])) {
			can_take &= ~(1 << i); //i번째 과목의 비트는 0으로 바꾸고 나머지는 유지함
		}
	}
	//모든 부분 집합 순회하기 -> 공집합은 제외함. 이 문제에선 49번째줄 필수
	for (int subset = can_take; subset; subset = ((subset - 1) & can_take)) { //subset은 부분 집합이야. 
		if (__builtin_popcount(subset) > L) // 부분 집합의 갯수(과목 수)가 최대 들을 수 있는 갯수 넘으면 패스
			continue;
		else {
			ret = min(graduate(se + 1, taken | subset) + 1, ret);
		}
	}
	ret = min(graduate(se + 1, taken), ret); //이번 학기 아무것도 안 들음

	return ret;
}


int main() {
	cin >> C;
	while (C--) {
		fill(&prerequisite[0], &prerequisite[MAXN], 0);
		fill(&sem_class[0], &sem_class[MAXM], 0);
		fill(&cache[0][0], &cache[MAXM-1][(1 << MAXN)], -1);
		//memset(prerequisite, 0, sizeof(prerequisite));
		//memset(sem_class, 0, sizeof(sem_class));
		//memset(cache, -1, sizeof(cache));

		cin >> N >> K >> M >> L;
		
		int R, Ri;
		for (int i = 0; i < N; i++) {
			cin >> R;
			for (int j = 0; j < R; j++) {
				cin >> Ri;
				prerequisite[i] |= (1 << Ri);
			}
			/*cout << "prerequisite 과목 " << i << "의 선수 과목 : ";
			for (int j = 0; j < MAXN; j++) {
				if (prerequisite[i] & (1 << j))
					cout << j << " ";
			}cout << "\n";*/
		}

		int CC, CCi;
		for (int i = 0; i < M; i++) {
			cin >> CC;
			for (int j = 0; j < CC; j++) {
				cin >> CCi;
				sem_class[i] |= (1 << CCi);
			}
			/*cout << i << "학기의 개설 과목 : ";
			for (int j = 0; j < MAXM; j++) {
				if (sem_class[i] & (1 << j))
					cout << j << " ";
			}cout <<"\n";*/
		}

		int ans = graduate(0, 0);
		if (ans != MAXSEMESTER)
			cout << ans << "\n";
		else
			cout << "IMPOSSIBLE\n";

	}
	return 0;
}