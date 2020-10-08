/*1. 가능한 모든 주문 방법구하기
  2. 중복 없이 최대 몇 번 주문할 수 있는지 구하기

  1번 문제를 풀기 위한 과정.
  여섯개의 상자에 인형의 갯수가 아래처럼 담겨있음.
  1 2 3 4 5 6
  H ~ T까지 주문해서 K로 나눠 떨어져야함.
  (psum[T] - psum[H-1]) % K == 0
  psum[T] % K == psum[H-1] % K
  psum 자체를 K로 나눈 나머지로 구함.
  -> psum[T] == psum[H-1]의 갯수를 구함.
  즉, psum[n]의 값이 같은 애들을 이용해 두 가지를 뽑아낼 수 있는 순서 상관없는 조합의 개수를 구한다.
  psum[n]의 값이 i일 때, f(i)는 psum[n]에서 i의 갯수.
  -> for ( n = 0 ~ K-1) {
	sum += (f(n) * f(n-1) / 2)
  }
  
  2번 문제를 풀때, % K가 적용된 psum을 이용할 수 있을까?
  H ~ T까지 더한 값을 다시 한 번 % K하면 될 것 같음.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int T, N, K;

long long my_op(int x, int y) { return ((x + y) % K); } //psum 구할 때 % K 연산도 적용하기 위한 사용자 정의 함수 추가
long long range_sum(const vector <long long>& ps, int a, int b) { return ps[b + 1] - ps[a]; } // a ~ b까지 부분 구간의 합

//1번 문제용 함수.
//부분합이 주어졌을 때, 숫자 0 ~ K-1를 이용한 두 가지를 뽑아낼 수 있는 가짓 수를 return
int num_of_ways_to_buy(const vector <long long>& ps) {
	int MOD = 20091101;
	vector <long long> num_of_k(K, 0);
	
	//psum에 있는 숫자 i의 개수를 num_of_k[i]번째에 저장.
	for (int i = 0; i < ps.size(); i++) {
		num_of_k[ps[i]]++;
	}
	//for (auto it : num_of_k)
	//	cout << it << " ";
	//cout << "\n";
	long long ans = 0;
	for (int i = 0; i < K; i++) {
		if (num_of_k[i] >= 2) 
			ans += (num_of_k[i] * (num_of_k[i] - 1)) / 2;
	}
	return ans % MOD;
}

//0 ~ n번 상자 범위 중 서로 겹치지 않고 구매할 수 있는 부분 구간의 최대 수를 return
int max_buy(const vector<long long>& ps) {
	vector<long long> ret(ps.size(), 0);
	vector<long long> prev(K, -1);
	for (int i = 0; i < ps.size(); i++) {
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;

		int loc = prev[ps[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		prev[ps[i]] = i;
	}
	return ret.back();
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector <int> boxes(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> boxes[i];
		}
		vector <long long> psum(N + 1, 0);
		psum[0] = 0; //두 개씩 psum값을 뽑아낼 때, 0을 하나 추가해둬야 % K 값이 0인 것의 조합 개수를 셀 수 있음
		partial_sum(boxes.begin(), boxes.end(), psum.begin() + 1, my_op);
		psum[1] %= K; //partial_sum은 첫 위치의 값에 대해서 my_op를 적용하지 않고 바로 return
		//for (auto it : psum) 
		//	cout << it << " ";
		//cout << "\n";
		cout << num_of_ways_to_buy(psum) << " ";
		cout << max_buy(psum) << "\n";
	}
}