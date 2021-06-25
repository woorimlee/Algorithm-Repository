#include <iostream>
#include <vector>

using namespace std;

/*
브루트포스(전체 탐색)으로 풀면 O(N^3)
N이 1000이기 때문에 십억번 정도의 연산이 걸리며, 시간 초과나기 딱좋음
-> 다른 알고리즘으로 풀어야함

전체 탐색으로 풀 때 세 변이 모두 같은 색인지 찾는 방법을 사용함.
두 가지 색으로 만들 수 있는 삼각형의 종류는 총 네 개임
1) 모두 빨강, 2) 모두 파랑
3) 한 변만 빨강, 4) 한 변만 파랑
3)과 4)를 살펴보니 한 꼭짓점에 두 가지 색이 있는 경우 단색 삼각형으로 못 만듦
-> 단색 삼각형을 만들지 못하는 방법을 O(N^3) 이하로 풀 수 있을지 고민해봄.

(이하 순열과 조합 개념)
단순히 생각해서 한 꼭짓점에 들어오는 빨간색 선의 갯수와 파란색 선의 갯수를 곱해주면
단색 삼각형이 아닌 삼각형이 만들어지고, 순서를 고려한 계산이기 때문에 2로 나눠줌

-> 전체 삼각형 만들수 있는 갯수는 nCm -> N은 입력받은 값, m은 3
-> 전체 갯수 - 위에서 계산한 단색 삼각형을 못만드는 갯수 = 답
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, color;
		cin >> N;
		vector <vector<int> > cnt_edge_colors(N, { 0, 0 });
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				cin >> color;
				cnt_edge_colors[i][color]++;
				cnt_edge_colors[j][color]++;
			}
		} 
		// cnt_edge_colors[i][0] = (i+1)번째 꼭짓점에서 파란색 선 갯수
		// cnt_edge_colors[i][0] = (i+1)번째 꼭짓점에서 빨간색 선 갯수

		int cnt_non_monocolors = 0;
		for (vector <int>& cnt_edge_color : cnt_edge_colors) 
			cnt_non_monocolors += cnt_edge_color[0] * cnt_edge_color[1];
		
		int nCm = (N * (N - 1) * (N - 2)) / (3 * 2 * 1);

		cout << (nCm - cnt_non_monocolors / 2) << "\n";
	}
	return 0;
}