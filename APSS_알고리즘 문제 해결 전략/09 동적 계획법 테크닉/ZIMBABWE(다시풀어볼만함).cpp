/*
완탐 먼저 설계
현재 가격 e, 과거 가격 ans는 m의 배수라는 정보가 주어졌을때,
e를 이용해 만들 수 있는 모든 수 중 (만든 수를 ex_price라고 함)
1. e > ex_price
2. ex_price % m == 0
3. e에 있는 숫자를 한 번씩 모두 사용해 ex_price 만듦
세 가지 성질을 만족해야함.
-> 
	1) e를 string으로 각 자릿수를 정렬
	2) 각 자릿수가 쓰였는지 확인하는 taken[]배열 생성
	3) ex_price의 i번째 숫자를 만들 때, 
		(1) taken[i] == false
		(2) i == 0 || e[i] != e[i-1] || taken[i-1] 
			i == 0 : 맨 처음건 노상관
			e[i] != e[i-1] : 다른 숫자면 바로 ex_price에 갖다 붙여도 됨
			taken[i-1] : e[i] == e[i-1]인 경우 taken[i-1]이 true 즉, 이미 사용됐었다면 아래의 조건에 따라 사용가능한 숫자.
			*조건 : 중복 숫자가 있는 경우 그 중 가장 먼저 오는 것을 선택해서 탐색.
	인 경우에만 확장 가능.

string e : 현재 가격
string sorted_e : 정렬된 현재 가격
bool taken[] : sorted_e의 자릿수가 사용됐는지 확인
//cur_price : 현재까지 만든 가격
infer_ex_price(string cur_price){
	if(cur_price.size() == e.size(){
		if(cur_price < e && stoi(cur_price) % m == 0)
			cur_price는 정답
	}
	for(int i = 0; i < e.size(); i++)
		if (!taken[i])
			if(i == 0 || sorted_e[i] != sorted_e[i-1] || taken[i-1]) {
				taken[i] = true;
				infer_ex_price(cur_price + sorted_e[i]);
				taken[i] = false;
			}
}
-> 최악의 경우 O(n!)

이걸 어케 dp로바꿈?
일단 taken[n] -> 1 <= n <= 15 -> cache[1<<14] 15개의 자릿수 담을 수 있음
cur_price 사용처 :
	1. base case
		1) 모든 숫자가 한 번씩 다 사용됐는지
		2) e보다 작은지
		3) m의 배수인지
	2. dfs에서 cur_price + sorted_e[i]
1.1)은 taken 비트 검사로 치환
1.2)는 dfs들어갈 때 bool 값을 이용.	-> cur_price에 사용할 i번째 수가 e의 i번째보다 작으면 그 뒤에 뭐가오든 노상관
									-> cur_price에 사용할 i번째 수가 e의 i번째와 같은 값이면 그 뒤에 e의 i+a번째 값보다 작은 값이 와야함
	위의 두 경우를 bool로 구분
1.3)은 나머지 연산의 분배법칙을 활용
2.는 위의 세 경우를 다 처리하면 실제 cur_price 값이 얼마인지는 중요하지 않으니 신경쓰지 않아도 됨.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MOD = 1000000007;
int C;
string e;
string sorted_e;
int m;

int cache[1 << 14][2][20]; //순서대로 taken, less, remainder
int infer_ex_price(int index, int taken, int less, int remainder) { //세 매개변수를 이용해 만든 숫자를 확장해서 환불해줄 가격을 만들 수 있는 경우의 수를 return
	if (taken == (1 << e.size()) - 1) { //모두 선택했으면
		return (less && (remainder == 0)) ? 1 : 0;
	}

	int& ret = cache[taken][less][remainder];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = 0; next < e.size(); next++) {
		if ((taken & (1 << next)) == 0) { //선택한 적 없는 자릿수
			if (!less && e[index] < sorted_e[next]) //less값이 0일 때(아직 지금까지 만든 수가 e보다 작다는 확신이 없음) e[index]보다 새로 추가할 수는 작아야지 
				continue;
			if (next == 0 || sorted_e[next] != sorted_e[next - 1] || taken & (1 << (next - 1))) {
				ret += infer_ex_price(index + 1, (taken | (1 << next)), (less || e[index] > sorted_e[next]), ((remainder * 10 + (sorted_e[next] - '0')) % m));
				ret %= MOD;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> C;
	while (C--) {
		cin >> e >> m;
		string temp = e;
		sort(e.begin(), e.end());
		sorted_e = e;
		e = temp;
		fill(&cache[0][0][0], &cache[(1 << (e.size())) - 1][1][m], -1);
		cout << infer_ex_price(0, 0, 0, 0) << "\n";
	}
	return 0;
}