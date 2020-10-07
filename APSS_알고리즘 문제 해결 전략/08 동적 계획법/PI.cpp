/*
optimal substructre ���� ����.
���ڷ� �� ���ڿ��� Ư�� ��ġ�������� 
3ĭ, 4ĭ, 5ĭ �� �ϳ��� ������ ������� ��Ž �� 
min ���� ã�Ƴ��� ��.

int memorize(int idx) {
	int& ret = cache[idx];
	
	3ĭ �� �����ϸ�
	ret = min(ret, optimal_method(idx, idx + 3) + memorize(idx + 3));
	ret = min .. 4
	ret = min .. 5

	return ret;
}

optimal_method(int begin, end){

}
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int C;
string subpi;
int cache[10001];

int optimal_method(int begin, int end) {
	bool level_1 = true;
	bool level_2_5 = true;
	bool level_4 = true;
	int ap = subpi[begin] - subpi[begin + 1];//arithmetic progression ��������
	for (int i = begin; i < end - 1; i++) {
		if (subpi[i] != subpi[i + 1]) {
			level_1 = false;
		}
		if (subpi[i] - subpi[i + 1] != ap)
			level_2_5 = false;
	}

	if (level_1) {
		return 1;
	}
	if (level_2_5 && abs(ap) == 1) {
		return 2;
	}
	if (level_2_5 && ap != 1) {
		return 5;
	}

	for (int i = begin; i < end - 2; i++) {
		if (subpi[i] != subpi[i + 2]) {
			level_4 = false;
		}
	}

	if (level_4) {
		return 4;
	}

	return 10;
}

int memorize(int idx) {
	int& ret = cache[idx];
	if (ret != -1)
		return ret;
	if (idx == subpi.size())
		return 0;

	ret = 1234567890;
	for (int i = 3; i <= 5; i++) 
		if (idx + i <= subpi.size()) 
			ret = min(ret, (memorize(idx + i) + optimal_method(idx, idx + i)));
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> subpi;
		fill(&cache[0], &cache[subpi.size()+1], -1);
		cout << memorize(0) << "\n";
		//cout << optimal_method(0, 3) << "\n";
	}
	return 0;
}