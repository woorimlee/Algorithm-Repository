#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 5;

int cache_1[1 << N];
int bool_array_memoization(bool (& arr)[N]) {
	int comb = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i]) {
			comb = comb | (1 << i);
		}
	}

	int& ret = cache_1[comb];
	if (ret != -1) {
		cout << "�޸������̼� �� ����. ret �� : ";
		return ret;
	}

	cout << "������ ǥ�� �� : ";
	for (int i = N-1; i >= 0; i--) {
		if (comb & (1 << i))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	cout << "\n";
	ret = 1;
	return ret;
}

int factorial[N];
void make_factorial() {
	factorial[1] = 1;
	for (int i = 2; i < N; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
}
int get_seq_index(int(&arr)[N]) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int less = 0;
		for (int j = i + 1; j < N; j++) 
			if (arr[i] > arr[j])
				less++;
		ret = ret + (factorial[N - i - 1] * less);
	}

	return ret;
}

int main() {
	fill(&cache_1[0], &cache_1[1 << N], -1);

	//1. �Է��� �Ҹ� ���� �迭�� ���
	bool arr[N] = { true, true, false }; //00011
	bool_array_memoization(arr);
	cout << bool_array_memoization(arr) << "\n";

	//2. �Է��� ������ ���
	int arr1[N] = { 1, 2, 3, 4, 5 }; //0
	int arr2[N] = { 1, 2, 5, 3, 4 }; //2 * 2!
	int arr3[N] = { 2, 1, 3, 4, 5 }; //1 * 4!
	make_factorial();
	cout << "arr1 ������ ���� ��ȣ : " << get_seq_index(arr1) << "\n";
	cout << "arr2 ������ ���� ��ȣ : " << get_seq_index(arr2) << "\n";
	cout << "arr3 ������ ���� ��ȣ : " << get_seq_index(arr3) << "\n";

	return 0;
}