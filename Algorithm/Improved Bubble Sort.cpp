/****************************************************************************
Bubble Sort :
	�տ������� �� ���� ���س����� ��������, �������� ���ؿ� ���� swap�Ѵ�.
	O(N^2)�� �ð� ���⵵�� ����.

	1. �迭�� �� �տ������� �� ���� ���� ���� ���Ѵ�.
	2. �ʿ��� ��� swap�Ѵ�.
	3. swap�� �� �� �κ��� ���� �˻����� �����Ѵ�.
	4. 1~3�� �ݺ��Ѵ�.

Improved Bubble Sort : 
	���� ������ 1~3�� �ݺ��ϸ鼭 bool ���� �ϳ��� �̿��� �� �̻� ������ �ʿ������ �˻��Ѵ�.
	����, �տ��� �� ���� ���� ���� ���ϴµ�, �迭�� ������ �������� �� swap�� ���� �� ���� ���ٸ�
	�� �迭�� ������ ���� �����̴� �� �̻� ���� ������ �� �ʿ䰡 ����.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max);
void BubbleSort(array<int, ARRSIZE>& arr);
void ImprovedBubbleSort(array<int, ARRSIZE>& arr);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n���� ���� : ";
	BubbleSort(arr);
	cout << "==> ���� �� �迭\n������ ���� ���� : ";
	ImprovedBubbleSort(arr);
	cout << "==> ���� �� �迭\n";

	return 0;
}

int GetRandomInt(int min, int max) {
	random_device rd;
	//���� ����̽� ��ü ������ �ϵ������ ���ҽ��� ������ ���ڸ� ����
	mt19937 mt(rd());
	//�޸��� Ʈ������ ������ ��ü ����

	//�õ� ���� ��

	//������ Ÿ���� ����.
	//min~ max���� ��� ���� �� ���� �� ����. ���� ������.
	uniform_int_distribution <int> range(min, max);

	//�� ����
	return range(mt);
}

//���� ����. �̿��� �� ���Ҹ� ���� ������ �ʿ��ϸ� swap.
void BubbleSort(array<int, ARRSIZE>& arr) {
	//O(N^2)
	array<int, ARRSIZE> sorted_arr = arr;
	for (int i = 0; i < sorted_arr.size() - 1; i++) {
		//�� ���� ���س����ϱ� �� ������ ������ ��ġ -1 ������ for ������ ����.
		//+ ���� �� �� ������ �� ������ �˻��� �ʿ䰡 ����
		for (int j = 0; j < sorted_arr.size() - 1 - i; j++) {
			if (sorted_arr[j] > sorted_arr[j + 1]) {
				swap(sorted_arr[j], sorted_arr[j + 1]);
			}
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//Improved Bubble Sort. Modified Bubble Sort.
void ImprovedBubbleSort(array<int, ARRSIZE>& arr) {
	/*���� ������ �� â �������ε�, ���̻� ������ �ʿ���� ��Ȳ�� ���� �� ����.
	ex) arr = {0, 5, 9, 11, 8};
	�������� 1ȸ : arr = {0, 5, 9, 8, 11};
	�������� 2ȸ : arr = {0, 5, 8, 9, 11};
	2ȸ���� ������ ���������� �ּ� �� �� ���������� �� ������.
	�̷� ��츦 ���� bool ������ �ϳ� ����.
	*/
	bool flag = true;
	array<int, ARRSIZE> sorted_arr = arr;
	for (int i = 0; i < sorted_arr.size() - 1; i++) {
		flag = true;
		//�� ���� ���س����ϱ� �� ������ ������ ��ġ -1 ������ for ������ ����.
		//+ ���� �� �� ������ �� ������ �˻��� �ʿ䰡 ����
		for (int j = 0; j < sorted_arr.size() - 1 - i; j++) {
			if (sorted_arr[j] > sorted_arr[j + 1]) {
				swap(sorted_arr[j], sorted_arr[j + 1]);
				flag = false;
			}
		}
		if (flag) {
			cout << "(bubble sort ���߿� ����) ";
			//���̻� ������ �ʿ���� ����.
			break;
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}