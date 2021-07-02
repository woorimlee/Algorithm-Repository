#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Naive�ϰ� �����غ���, 0�� ���� �� ��������
password�� �׸����ϰ� �̾� ���̸� ��
ex) share�� ������ ���� �־�����
555, 3, 55511
3 -> 55511 -> 555�� �̾���̸� ��
�ٵ�, �ܼ� ������ ���Ľ� 3 -> 555 -> 55511�� �پ�����ϱ� 
���ϴ� �� ����� p, q�� �� p + q�� q + p�� ����

����, invalid �˻縦 ���� 0�� �� �տ� �����°� skip �����鼭
1) all skip �Ǵ� ��� -> invalid
2) �� �տ� 0���� �������� �ʴ°� ������ ��� �װ� �� �տ� �ΰ� 
   ������ ���ĵ� ���ڸ� �տ������� �̾� ���̸鼭 ������ ������� ���ڿ��� ����
*/

bool cmp(const string& p, const string& q) {
	return p + q < q + p; // p + q�� ������ p�� ��������
}

string make_password(const vector<string>& shares, int i, int N) {
	string temp = shares[i]; // �� �տ� �߰��صΰ�

	for (int j = 0; j < N; j++) {
		if (j != i)
			temp += shares[j]; // ���ļ� �߰�
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