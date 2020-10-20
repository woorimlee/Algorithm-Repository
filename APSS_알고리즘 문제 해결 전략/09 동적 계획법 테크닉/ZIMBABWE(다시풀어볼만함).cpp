/*
��Ž ���� ����
���� ���� e, ���� ���� ans�� m�� ������ ������ �־�������,
e�� �̿��� ���� �� �ִ� ��� �� �� (���� ���� ex_price��� ��)
1. e > ex_price
2. ex_price % m == 0
3. e�� �ִ� ���ڸ� �� ���� ��� ����� ex_price ����
�� ���� ������ �����ؾ���.
-> 
	1) e�� string���� �� �ڸ����� ����
	2) �� �ڸ����� �������� Ȯ���ϴ� taken[]�迭 ����
	3) ex_price�� i��° ���ڸ� ���� ��, 
		(1) taken[i] == false
		(2) i == 0 || e[i] != e[i-1] || taken[i-1] 
			i == 0 : �� ó���� ����
			e[i] != e[i-1] : �ٸ� ���ڸ� �ٷ� ex_price�� ���� �ٿ��� ��
			taken[i-1] : e[i] == e[i-1]�� ��� taken[i-1]�� true ��, �̹� ���ƾ��ٸ� �Ʒ��� ���ǿ� ���� ��밡���� ����.
			*���� : �ߺ� ���ڰ� �ִ� ��� �� �� ���� ���� ���� ���� �����ؼ� Ž��.
	�� ��쿡�� Ȯ�� ����.

string e : ���� ����
string sorted_e : ���ĵ� ���� ����
bool taken[] : sorted_e�� �ڸ����� ���ƴ��� Ȯ��
//cur_price : ������� ���� ����
infer_ex_price(string cur_price){
	if(cur_price.size() == e.size(){
		if(cur_price < e && stoi(cur_price) % m == 0)
			cur_price�� ����
	}
	for(int i = 0; i < e.size(); i++)
		if (!taken[i])
			if(i == 0 || sorted_e[i] != sorted_e[i-1] || taken[i-1]) {
				taken[i] = true;
				infer_ex_price(cur_price + sorted_e[i]);
				taken[i] = false;
			}
}
-> �־��� ��� O(n!)

�̰� ���� dp�ιٲ�?
�ϴ� taken[n] -> 1 <= n <= 15 -> cache[1<<14] 15���� �ڸ��� ���� �� ����
cur_price ���ó :
	1. base case
		1) ��� ���ڰ� �� ���� �� ���ƴ���
		2) e���� ������
		3) m�� �������
	2. dfs���� cur_price + sorted_e[i]
1.1)�� taken ��Ʈ �˻�� ġȯ
1.2)�� dfs�� �� bool ���� �̿�.	-> cur_price�� ����� i��° ���� e�� i��°���� ������ �� �ڿ� �������� ����
									-> cur_price�� ����� i��° ���� e�� i��°�� ���� ���̸� �� �ڿ� e�� i+a��° ������ ���� ���� �;���
	���� �� ��츦 bool�� ����
1.3)�� ������ ������ �й��Ģ�� Ȱ��
2.�� ���� �� ��츦 �� ó���ϸ� ���� cur_price ���� �������� �߿����� ������ �Ű澲�� �ʾƵ� ��.
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

int cache[1 << 14][2][20]; //������� taken, less, remainder
int infer_ex_price(int index, int taken, int less, int remainder) { //�� �Ű������� �̿��� ���� ���ڸ� Ȯ���ؼ� ȯ������ ������ ���� �� �ִ� ����� ���� return
	if (taken == (1 << e.size()) - 1) { //��� ����������
		return (less && (remainder == 0)) ? 1 : 0;
	}

	int& ret = cache[taken][less][remainder];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = 0; next < e.size(); next++) {
		if ((taken & (1 << next)) == 0) { //������ �� ���� �ڸ���
			if (!less && e[index] < sorted_e[next]) //less���� 0�� ��(���� ���ݱ��� ���� ���� e���� �۴ٴ� Ȯ���� ����) e[index]���� ���� �߰��� ���� �۾ƾ��� 
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