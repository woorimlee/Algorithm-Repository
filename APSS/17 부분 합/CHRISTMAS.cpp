/*1. ������ ��� �ֹ� ������ϱ�
  2. �ߺ� ���� �ִ� �� �� �ֹ��� �� �ִ��� ���ϱ�

  1�� ������ Ǯ�� ���� ����.
  �������� ���ڿ� ������ ������ �Ʒ�ó�� �������.
  1 2 3 4 5 6
  H ~ T���� �ֹ��ؼ� K�� ���� ����������.
  (psum[T] - psum[H-1]) % K == 0
  psum[T] % K == psum[H-1] % K
  psum ��ü�� K�� ���� �������� ����.
  -> psum[T] == psum[H-1]�� ������ ����.
  ��, psum[n]�� ���� ���� �ֵ��� �̿��� �� ������ �̾Ƴ� �� �ִ� ���� ������� ������ ������ ���Ѵ�.
  psum[n]�� ���� i�� ��, f(i)�� psum[n]���� i�� ����.
  -> for ( n = 0 ~ K-1) {
	sum += (f(n) * f(n-1) / 2)
  }
  
  2�� ������ Ǯ��, % K�� ����� psum�� �̿��� �� ������?
  H ~ T���� ���� ���� �ٽ� �� �� % K�ϸ� �� �� ����.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int T, N, K;

long long my_op(int x, int y) { return ((x + y) % K); } //psum ���� �� % K ���굵 �����ϱ� ���� ����� ���� �Լ� �߰�
long long range_sum(const vector <long long>& ps, int a, int b) { return ps[b + 1] - ps[a]; } // a ~ b���� �κ� ������ ��

//1�� ������ �Լ�.
//�κ����� �־����� ��, ���� 0 ~ K-1�� �̿��� �� ������ �̾Ƴ� �� �ִ� ���� ���� return
int num_of_ways_to_buy(const vector <long long>& ps) {
	int MOD = 20091101;
	vector <long long> num_of_k(K, 0);
	
	//psum�� �ִ� ���� i�� ������ num_of_k[i]��°�� ����.
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

//0 ~ n�� ���� ���� �� ���� ��ġ�� �ʰ� ������ �� �ִ� �κ� ������ �ִ� ���� return
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
		psum[0] = 0; //�� ���� psum���� �̾Ƴ� ��, 0�� �ϳ� �߰��ص־� % K ���� 0�� ���� ���� ������ �� �� ����
		partial_sum(boxes.begin(), boxes.end(), psum.begin() + 1, my_op);
		psum[1] %= K; //partial_sum�� ù ��ġ�� ���� ���ؼ� my_op�� �������� �ʰ� �ٷ� return
		//for (auto it : psum) 
		//	cout << it << " ";
		//cout << "\n";
		cout << num_of_ways_to_buy(psum) << " ";
		cout << max_buy(psum) << "\n";
	}
}