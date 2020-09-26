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
int prerequisite[MAXN]; // ���� ���� ���� ���� ����
int sem_class[MAXM]; // �б⺰ �����Ǵ� ���� ����
int cache[MAXM][1 << MAXN];

//se = Ư�� �б�, taken = ���ݱ��� ���� ������ ����
int graduate(int se, int taken) { //�̹� semester�� taken + K�� �����ؼ� ������ �� �ִ� �ּ� �б��� ���� return
	//���� ����
	//1. �� �����
	if (__builtin_popcount(taken) >= K)
		return 0;
	//2. �бⰡ �����ϴ�
	if (se >= M)
		return MAXSEMESTER;

	int& ret = cache[se][taken];
	if (ret != -1)
		return ret;

	ret = MAXSEMESTER;
	//canTake �̹� �б⿡ ���� �� �ִ� ���� �� ���� ���� ���� ���� ����
	int can_take = (sem_class[se] & (~taken));

	//canTake�� ���� ���� �� ���������� ���� ���� �͵��� �����Ѵ�.
	for (int i = 0; i < N; i++) { //i = ���� ��ȣ
		//canTake & (1 << i) : �̹� �б⿡ ���� �� �ִ� ���� �� ���� ���� �ʾҴ� ������ ã��
		//taken & prerequisite[i]) != prerequisite[i] : ����� ����� i��° ������ ���������� ���ؼ� ���������� ��Ʈ�� ��� ����Ǹ� ��� ��������
		if ((can_take & (1 << i)) && ((taken & prerequisite[i]) != prerequisite[i])) {
			can_take &= ~(1 << i); //i��° ������ ��Ʈ�� 0���� �ٲٰ� �������� ������
		}
	}
	//��� �κ� ���� ��ȸ�ϱ� -> �������� ������. �� �������� 49��°�� �ʼ�
	for (int subset = can_take; subset; subset = ((subset - 1) & can_take)) { //subset�� �κ� �����̾�. 
		if (__builtin_popcount(subset) > L) // �κ� ������ ����(���� ��)�� �ִ� ���� �� �ִ� ���� ������ �н�
			continue;
		else {
			ret = min(graduate(se + 1, taken | subset) + 1, ret);
		}
	}
	ret = min(graduate(se + 1, taken), ret); //�̹� �б� �ƹ��͵� �� ����

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
			/*cout << "prerequisite ���� " << i << "�� ���� ���� : ";
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
			/*cout << i << "�б��� ���� ���� : ";
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