#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int m,q, n;
string str_q[501];
int word_idx[101]; //분류기가 인식한 문장의 단어의 번호(위치)를 저장할 배열
double B[501];
double T[501][501];
double M[501][501];
double cache[102][502];
int choice[102][502];

//Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그 값을 반환.
//Q[segment - 1] == previousMatch
double recognize(int segment, int previousMatch) {
	if (segment == n)
		return 0; //0.0으로 하면 오답. 왜..?
	
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0)
		return ret;

	ret = -1e200;
	int& choose = choice[segment][previousMatch];
	for (int thisMatch = 1; thisMatch <= m; thisMatch++) {
		double candidate = T[previousMatch][thisMatch] + M[thisMatch][word_idx[segment]] + recognize(segment + 1, thisMatch);
		if (ret < candidate) {
			ret = candidate;
			choose = thisMatch;
		}
	}
	return ret;
}

void reconstruct(int seg, int pre) {
	if (seg == n)
		return;
	
	int choose = choice[seg][pre];
	cout << str_q[choose] << " ";
	reconstruct(seg + 1, choose);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//초기화
	cin >> m >> q;
	//원문 입력
	for (int i = 1; i <= m; i++)
		cin >> str_q[i];
	
	//B 입력
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] = log(B[i]);
	}

	//T 입력
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 0)
				T[i][j] = B[j];

			else {
				cin >> T[i][j];

				T[i][j] = log(T[i][j]);
			}
		}
	}

	//M 입력
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}

	//q 번의 분류기로 인식한 문장이 주어짐
	while (q--) {
		cin >> n;
		fill(&cache[0][0], &cache[101][502], 1.0);
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			for (int j = 1; j <= m; j++) {
				if (temp == str_q[j]) {
					word_idx[i] = j; //i번째 문자가 원문 기준 몇 번째 글자인가
					break;
				}
			}
		}
		recognize(0, 0);
		reconstruct(0, 0);
		cout << "\n";
	}

	return 0;
}
