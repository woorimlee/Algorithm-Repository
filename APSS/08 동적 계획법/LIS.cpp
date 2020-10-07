//O(N^2)�� Ǯ �� �ִ� ���� ��ȹ�� Ǯ��. (8�� ���� ���)
// { 1, 5, 9, 2, 3, 1, 5, 4 }
//�� ���� ��, {1, 2, 3, 5} or {1, 2, 3, 4}�� ���ؾ���.
//�� �������� {1, 2, 3, 5}, {1, 2, 3, 4}, {1, 5, 9}, {2, 3}, {1, 5} �κ� ���� ������ �������� ��.
//��, �迭�� ��� ��ġ���� ���������� ���ϴ� �õ��� �غ��� �ϸ�, ��ѱ� �� ��Ģ�� ���� �ߺ� �˻�� �ݵ�� ����.
//lis(idx) : idx���� �����ϴ� ���� �κ� ���� ���� ���̸� return

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;

int cache[501];

//idx�� -1���� �����Ͽ� 0 ~ ���̱��� ��� �迭 ��ȸ�� ����.
int lis(const vector <int>& s, int idx) { 
	int& ret = cache[idx + 1];
	if (ret != -1)
		return ret;
	
	ret = 1;
	for (int i = idx + 1; i < s.size(); i++) {
		if (idx == -1 || s[idx] < s[i])
			ret = max(ret, lis(s, i) + 1);
	}

	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N;
		fill(&cache[0], &cache[500], -1);
		vector <int> seq(N, 0);
		for (int i = 0; i < N; i++)
			cin >> seq[i];
		cout << lis(seq, -1) - 1 << "\n";
	}

	return 0;
}