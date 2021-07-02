#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Naive하게 생각해보면, 0이 없을 때 기준으로
password를 그리디하게 이어 붙이면 됨
ex) share가 다음과 같이 주어지면
555, 3, 55511
3 -> 55511 -> 555로 이어붙이면 됨
근데, 단순 사전순 정렬시 3 -> 555 -> 55511로 붙어버리니까 
비교하는 두 대상이 p, q일 때 p + q와 q + p를 비교함

이후, invalid 검사를 위해 0이 맨 앞에 나오는건 skip 때리면서
1) all skip 되는 경우 -> invalid
2) 맨 앞에 0으로 시작하지 않는게 나오는 경우 그걸 맨 앞에 두고 
   나머지 정렬된 숫자를 앞에서부터 이어 붙이면서 이전에 만들었던 문자열과 비교함
*/

bool cmp(const string& p, const string& q) {
	return p + q < q + p; // p + q가 작으면 p가 왼쪽으로
}

string make_password(const vector<string>& shares, int i, int N) {
	string temp = shares[i]; // 맨 앞에 추가해두고

	for (int j = 0; j < N; j++) {
		if (j != i)
			temp += shares[j]; // 정렬순 추가
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector <string> shares(N, "");
	for (string& share : shares)
		cin >> share;

	sort(shares.begin(), shares.end(), cmp);
	
	string ans = "";
	for (int i = 0; i < N; i++) {
		if (shares[i][0] != '0') {
			string now = make_password(shares, i, N);
			if (ans == "" || now < ans)
				ans = now;
		}
	}
	
	if (ans == "") 
		cout << "INVALID";
	else 
		cout << ans;
	return 0;
}