/****************************************************************************
���� ���� : 
	�ִ� Ȥ�� �ּڰ��� ã�Ƽ� �迭�� �� �ڳ� �� ������ �ű�� ���.
	O(N^2)�� �ð� ���⵵�� ����.

	1. �迭���� ���� ū ���� ã�´�.
	2. �� ���� ���� ���� ū ���� swap�Ѵ�.
	3. swap�� �� �� �κ��� ���� �˻����� �����Ѵ�.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max);
void SelectionSort(array<int, ARRSIZE>& arr);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	SelectionSort(arr);
	for (auto it : arr) {
		cout << it << " ";
	}
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

//���� ����. �ִ� Ȥ�� �ּڰ��� ã�Ƽ� �� �ڳ� �� ������ �ű��.
void SelectionSort(array<int, ARRSIZE>& arr) {
	//O(N^2)
	int index = 0;
	//1. �迭���� ���� ū ���� ã�´�.
	//2. �� ���� ���̶� swap�Ѵ�. (swap�� �� �� �κ� ���� �˻����� ����)
	//3. �� ���� �ڷ�� �ּڰ����� ���ĵǴ�, i�� 1�� �ɶ������� �� ������ �ݺ��Ѵ�.
	for (int i = arr.size() - 1; i >= 1; i--) {
		index = i;
		for (int j = 0; j <= i; j++) {
			if (arr[index] < arr[j]) {
				index = j;
			}
		}
		if (i != index)
			swap(arr[i], arr[index]);
	}
	return;
}