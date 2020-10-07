#include <iostream>

using namespace std;

//브루트 포스 방식으로 풀 예정.
//집합에서 만들 수 있는 모든 부분집합의 경우를 다 계산 할 것임.
//부분집합의 개수 : 2^N(집합의 원소 x가 포함 되냐, 안 되냐의 개념(2) * 집합 내 원소의 개수(N))

int N, S;
int arr[20];

int main(void) {
	ios::sync_with_stdio(false);

	int sum;
	int answer = 0;

	//N은 집합의 원소 갯수
	//S는 더해서 만들 값
	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//공집합 제외라 i는 1부터 ~ 2^N -1까지(부분 집합의 개수).
	//(1 << N) : N이 5면 100000(2)이고, 여기에 - 1 하면 -> 11111(2) = 31(10). 
	//i는 1 ~ 31까지. 2진수 상으론 1(2)부터 11111(2)까지 모든 경우의 수를 만들어 내는 상황.
	//i의 값에 1, 10, 100, 1000, 10000을 비트 연산할 예정.
	for (int i = 1; i < (1 << N); i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) { // j=0 : 1,   j=1 : 10,   j=2 : 100, ...
				//i가 10010이라고 하면, j는 1, 4일 때 if문이 true.
				//따라서 arr[1]과 [4]에 있는 숫자를 더해보고
				//원하는 부분집합의 합 값이 나오면 answer를 늘린다.
				sum += arr[j];
			}
		}

		if (sum == S) answer++;
	}

	cout << answer << endl;

	return 0;
}