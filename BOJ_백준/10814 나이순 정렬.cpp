#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//sort �Լ����� ����� �� ���� �Լ�
//�⺻������ ��������
//�������� : greater <int>()
//����� ���� ������ ������ֱ� ���� �Ʒ��� ���� �Լ��� ����.
bool comp(pair<int, string> a, pair<int, string> b) {
	//a.first���� b.first�� ũ�� ���ΰ�
	if (a.first < b.first) return true;
	//�ݴ�� ��ġ �ٲٱ�
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int n;
	vector <pair <int, string> > vec;
	cin >> n;
	//���� �ε����� ����� �Է¹޾��ַ��� resize
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	//sort()�� ���� ���ϴ� �� ���� ���� �� �� elements�� ��ġ�� �����Ѵٰ� ����� �� ���� �ݸ�,
	//stable_sort()�� ���� ���� ��Ȳ�� �� elements�� ��ġ(����)�� ��������.
	//stable_sort : The order of equal elements is guaranteed to be preserved.
	stable_sort(vec.begin(), vec.end(), comp);

	for (auto it : vec) {
		cout << it.first << " " << it.second << '\n';
	}
	return 0;
}