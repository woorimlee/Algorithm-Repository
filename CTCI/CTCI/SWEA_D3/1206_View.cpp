#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, answer = 0;
	int Highest = 0;
	vector<int> vec;

	for (int i = 1; i <= 10; i++) {
		//테스트 끝나고 초기화
		answer = 0;
		cin >> N;
		vec.clear();
		vec.resize(N + 1);

		//벡터에 N개의 빌딩 길이 집어넣음.
		for (int j = 0; j < N; j++) {
			cin >> vec[j];
			if (j >= 4) {
				//검사할 빌딩 기준 왼쪽 두 개 빌딩과 오른쪽 두 개 빌딩에서 각각 가장 큰 빌딩 찾고
				//그것 중 다시 가장 큰 빌딩 찾아서
				Highest = max(max(vec[j - 4], vec[j - 3]), max(vec[j - 1], vec[j])); 
				//검사할 빌딩이랑 비교
				if (vec[j - 2] > Highest)
					answer += vec[j - 2] - Highest;
			}
		}

		cout << "#" << i << " " << answer << "\n";
	}

}