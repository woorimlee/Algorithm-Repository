#include <iostream>

using namespace std;

int N, K;
bool* check;
int** ranking;

void printRanking();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	//금메달 획득 갯수 -> 은메달 -> 동메달 순서로 K국가의 순위를 하나씩 밀어낼 건데,
	//은메달 검사할 때 (이미 금메달에따른 순위는 이미 밀려났고)
	//금메달 갯수가 자기보다 많거나 적은 애들이랑은 비교를 할 필요가 없음.
	//그에 대한 check 배열을 만듦.
	check = new bool[N + 1];
	fill_n(check, N + 1, false);

	ranking = new int* [N + 1];
	for (int i = 1; i <= N; i++) {
		ranking[i] = new int[3];
	}

	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		ranking[a][0] = b;
		ranking[a][1] = c;
		ranking[a][2] = d;
	}
	//printRanking();

	int rank = 1;
	int k_medal;
	//금 -> 은 -> 동 검사를 위해 세 번 for 구문 돌림
	for (int i = 0; i < 3; i++) {
		k_medal = ranking[K][i];
		//i == 0일때 금메달, ...
		for (int j = 1; j <= N; j++) {
			if (K == j)
				continue;
			//만약 K 국가의 메달 갯수보다 높은 값이 나오면 순위 증가
			if (check[j] == false && k_medal < ranking[j][i]) {
				rank++;
				check[j] = true;
			}
			//만약 K 국가의 메달 갯수보다 낮은 애는 다음 메달도 검사할 필요가 없음
			else if (check[j] == false && k_medal > ranking[j][i]) {
				check[j] = true;
			}
		}
	}
	cout << rank;

	return 0;
}

void printRanking() {
	for (int i = 1; i <= N; i++) {
		cout << i << ":" << ranking[i][0] << " " << ranking[i][1] << " " << ranking[i][2] << '\n';
	}
}