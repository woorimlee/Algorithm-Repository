#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int C;
int N, K;
const int MAX = 2000000000 + 1;

int cache[501];
int lis(const vector<int>& seq, int idx) {
	int& ret = cache[idx + 1];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next = idx + 1; next < seq.size(); next++) {
		if (idx == -1 || seq[idx] < seq[next])
			ret = max(ret, lis(seq, next) + 1);
	}
	return ret;
}

int cntcache[501];
int cnt_lis(const vector<int>& seq, int idx) {
	if (lis(seq, idx) == 1)
		return 1;
	int& ret = cntcache[idx];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int next = idx + 1; next < seq.size(); next++) {
		if ((idx == -1 || seq[idx] < seq[next]) && lis(seq, idx) == lis(seq, next) + 1) {
			ret = min<long long>(MAX, (long long)ret + cnt_lis(seq, next));
		}
	}
	return ret;
}

void reconstruct(const vector<int>& seq, int idx, int skip, vector<int>& ans_lis) {
	if (idx != -1)
		ans_lis.push_back(seq[idx]); //���� �߰�. ������ ��찡 �ƴϸ� �ƿ� ��� �Լ� ���� ��ü�� ����
	
	//lis()�� ���� ������ �͵��� ã��
	vector <pair <int, int> > followers;
	for (int next = idx + 1; next < seq.size(); next++) {
		if ((idx == -1 || seq[idx] < seq[next]) && lis(seq, idx) == lis(seq, next) + 1) {
			followers.push_back({ seq[next], next });
		}
	}
	sort(followers.begin(), followers.end());

	//idx�� cnt���� skip ���� ��
	for (int i = 0; i < followers.size(); i++) {
		int cnt = cnt_lis(seq, followers[i].second);
		if (cnt <= skip) //k��° �� = skip���� �� �� ó�� ������ ��
			skip -= cnt;
		else {
			reconstruct(seq, followers[i].second, skip, ans_lis);
			break;
		}
	}
}

void print_result(const vector<int>& seq);
void print_answer(const vector<int>& lis);

int main() {
	cin >> C;
	while (C--) {
		cin >> N >> K;
		fill(&cache[0], &cache[501], -1);
		fill(&cntcache[0], &cntcache[501], -1);
		vector <int> seq(N);
		for (int i = 0; i < N; i++)
			cin >> seq[i];
		cnt_lis(seq, -1);
		//print_result(seq); //Debuging �뵵
		vector <int> lis;
		reconstruct(seq, -1, K - 1, lis);
		print_answer(lis);
	}
	return 0;
}

void print_result(const vector<int>& seq) {
	for (int i = 0; i < N; i++) {
		cout << seq[i] << " ";
	}cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << lis(seq, i) << " ";
	}cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << cnt_lis(seq, i) << " ";
	}cout << "\n";
}

void print_answer(const vector<int>& lis) {
	cout << lis.size() << "\n";
	for (int it : lis) {
		cout << it << " ";
	}cout << "\n";
}