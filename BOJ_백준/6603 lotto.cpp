#include <iostream>
#include <algorithm>
#include <vector>

//들어가기에 앞서. 정답 출력 부분은 코드적으로 좀 더 간결하게 만드셔도 됩니다. 
//저는 그냥 깔끔하게 정리하기 위해서 answer 벡터 하나를 더 선언했습니다.

//K를 입력 받고, K 크기 만큼 집합 S에 포함될 수를 입력 받을 것.
//1. K가 7일 경우, 7개의 원소 중 6개만 골라서 로또 번호를 선택할 것이니
//   크기가 7인 bool 배열에서 하나는 false, 나머지는 true로 만들고
//   이 배열의 모든 순열 조합을 구한다.
//2. 정렬된 상태로 출력을 해야한다.

using namespace std;
int S[13];
bool check_permutation[13];
vector <vector <int> > answer;
vector <int> vec;

int main(void) {
	int K;

	while (cin >> K) {
		//cin >> K는 cin으로 부터 값을 읽어서 K에 넣을 건데 
		//K의 자료형과 맞지 않는 입력이 들어오거나, EOF, 에러 등의 상황이 오면 flase야.
		//while안에 넣어줌으로써 정확한 입력이 들어오는 한 계속 while문을 돌릴거라는 선언.
		
		if (K == 0) break;
		for (int i = 0; i < K; i++) {
			cin >> S[i];
		}

		//1. 부분
		for (int i = 0; i < K-6; i++) {
			check_permutation[i] = false;
		}
		for (int i = K-6; i < K; i++) {
			check_permutation[i] = true;
		}
		do {
			for (int i = 0; i < K; i++) {
				if (check_permutation[i] == true) {
					vec.push_back(S[i]);
				}
			}
			answer.push_back(vec);
			vec.clear();
		} while (next_permutation(check_permutation, check_permutation+K));

		//2. 부분
		sort(answer.begin(), answer.end());
		for (auto it : answer) {
			for (int i = 0; i < it.size(); i++) {
				cout << it[i] << " ";
			}
			cout << endl;
		}
		answer.clear();
		cout << endl;
	}

	return 0;
}