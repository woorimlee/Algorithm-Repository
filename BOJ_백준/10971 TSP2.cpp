#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//항상 순회할 수 있는 경우만 주어짐.
//모든 순열 조합을 바탕으로 순회하기.
//ex). arr[0] = 0, [1] = 1, ..., [3] = 3 일 때 :
//     0123 은 0 -> 1 -> 2 -> 3 -> 0으로 순회한다고 가정.
//     만약 0 -> 1 값이 0이면, 다음 순열로 바로 넘어감.
//     모든 순열 조합을 탐색하며 최소 값 찾기.

int main(void) {
	int N;
	cin >> N;
	int W[10][10];

	//충분히 큰 값
	int answer = 2147483647;
	int arr[10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
		arr[i] = i;
	}

	do {
		//0 -> 1일 때 값이 0이라면 다음 순열 조합으로 넘기기 위한 flag.
		bool flag = true;
		//매 순회마다 계산할 값을 저장할 temp.
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			if (W[arr[i]][arr[i + 1]] == 0) flag = false;
			else temp += W[arr[i]][arr[i + 1]];
		}

		if (!flag || W[arr[N - 1]][arr[0]] == 0) continue;
		temp += W[arr[N - 1]][arr[0]];
		//최소 값으로 answer를 갱신.
		answer = min(answer, temp);

		//이 문제는 0 -> 1 -> 2 -> 3의 경우, 마지막에 3 -> 0으로 돌아오기 때문에 맨 앞의 값을
		//(모든 순열 조합에서 맨 앞의 값을) 고정해두고 모든 순열을 찾아도 됨.
	} while (next_permutation(arr + 1, arr + N));

	cout << answer << endl;
	return 0;
}
