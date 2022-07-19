#include <iostream>

using namespace std;

#define EXP1 k*N*M*(M-1)
#define EXP2 N*(N-1)*M*M

int main() {
	//식 1 : 같은 지역 리그내의 팀들과의 경기 수
	//팀당 경기수 * N개의 리그 * M개의 팀 중 2개 중복없이 고르기
	//== A * N * ( M * (M - 1) ) / 2

	//식 2 : 다른 지역 리그내의 팀들과의 경기 수
	//팀당 경기수 * N개의 리그 중 2개 중복없이 고르기 * M개의 팀 중 하나 * M개의 팀 중 하나
	//== B * (N * (N - 1) ) / 2 * M * M

	//위의 두 식을 더한 값이 D보다 작거나 같아야 함.
	//D >= 식 1 + 식 2

	//식 1의 A를 k * B로 변환해서 풀이 진행

	int T;
	cin >> T;
	while (T--) {
		int N, M, k, D;
		cin >> N >> M >> k >> D;
		int B = int(D * 2 / (EXP1 + EXP2));
		B ? cout << ((B * EXP1 / 2) + (B * EXP2 / 2)) << "\n" : cout << -1 << "\n";
	}


	return 0;
}