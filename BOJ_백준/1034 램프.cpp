/*
한 번에 한 열을 다 바꾸니까
입력받은 이차원 배열에서
한 행에 0의 갯수가 K보다 작은 것들 중
가장 많이 똑같은 상태를 갖고 있는 행을 구하면 됨.

함정이 있었음. (생각하지 못한)
스위치를 무조건 K번 만큼 눌러야함.
같은 곳을 짝수번 클릭하면 스위치 누르는 걸 무를 수 있으니, 이걸 추가해야 함

만약 스위치 남은 경우
K - 0의 갯수의 값이 홀수면 그냥 못하는거고,
짝수면 ㄱㅊ
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int N, M, K;
//처음에 인트형 배열했다가 쓸데없이 복잡해져서
//스트링으로처리함
string table[51] = { "" };

int main() {
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	cin >> K;

	int cnt = 0;
	int same = 1;
	int max = 0;
	for (int i = 0; i < N; i++) {
		//i 행의 0의 개수를 셈
		cnt = 0; // 0의 개수를 저장
		same = 0; // 같은 형태의 행의 개수를 저장
		for (int j = 0; j < M; j++) {
			if (table[i][j] == '0')
				cnt++;
		}
		//cnt가 k보다 작거나 같고, k-cnt가 짝수면
		if (cnt <= K && (K - cnt) % 2 == 0) {
			//자기랑 똑같은 형태의 행을 찾음
			for (int k = i; k < N; k++) {
				if (table[i] == table[k])
					same++;
			}
			max = max < same ? same : max;
		}
		
	}
	cout << max;
	return 0;
}
