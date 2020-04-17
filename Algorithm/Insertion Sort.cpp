/****************************************************************************
���� ���� :
	�迭�� �� ���Ҿ� �տ������� ���ϸ� �� ������ ������ ��ġ�� ã�� �װ��� �ڽ��� �����ϴ� ���.
	O(N^2) ~ O(N)�� �ð� ���⵵�� ����.

	�����ϰ��� �ϴ� ���� �ϳ��� �ٷ� ���� �ε����� swap
	1. [n]��° ���Һ��� �����ϸ�, �ٷ� ������ ���ҿ� �ڽ��� ���� ���Ѵ�.
	2. �������� �������� [n] �ε����� [n-1]���� ���� ũ�ų� ���ٸ� swap�� �� �ʿ䰡 ����.
	3. �ݴ��� swap�� �����Ѵ�.
	4. 3�� �����ϸ�, [n]�ε����� �ִ� ���� [n-1]���� ��ġ�ϰ� �Ǵµ�, [n-1]���� ���� �ε����� [n-2]�� �� 2~3���� �ݺ��Ѵ�.(���Ѵ�).
	5. 1~4�� �ݺ��ϸ� [n]�� ���� 1 ������Ų��.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max);
void InsertionSort(array<int, ARRSIZE>& arr);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	InsertionSort(arr);
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

//���� ����. �迭�� ���ҵ��� �տ������� ���ϸ� �ڽ��� ������ ��ġ�� ã�� �װ��� �ڽ��� ������.
void InsertionSort(array<int, ARRSIZE>& arr) {
	/*O(N^2) ~ O(N)
	�����ϰ��� �ϴ� ���� �ϳ��� �ʿ��� ��� ������ ���ܿ��� ����.
	ex) arr = {10, 20, 5, 30};
	1���� : �����ϰ��� �ϴ� ���� = 20
		-> 20�� �� ����(5)�� 20�� ���� �� -> ������ �ʿ� ����
	2���� : �����ϰ��� �ϴ� ���� = 5
		-> 5�� �� ����(20)�� 5�� �� -> {10, 5, 20, 30} -> 5�� �� ����(10)�� 5�� �� -> {5, 10, 20, 30}
	3���� : �����ϰ��� ���� ���� = 30
		-> 30�� �� ����(20)�� 30�� �� -> ������ �ʿ� ����
	*/
	array<int, ARRSIZE> sorted_arr = arr;

	//��� 1
	/*int key = sorted_arr[1];
	int j = 0;
	for (int i = 1; i < sorted_arr.size(); i++) {
		key = sorted_arr[i];
		for (j = i - 1; j >= 0 && sorted_arr[j] > key; j--) {
			sorted_arr[j + 1] = sorted_arr[j];
		}
		sorted_arr[j + 1] = key;
	}*/

	//��� 2
	int key = sorted_arr[1];
	for (int i = 1; i < sorted_arr.size(); i++) {
		key = i;
		for (int j = i - 1; j >= 0 && sorted_arr[j] > sorted_arr[key]; j--) {
			swap(sorted_arr[j], sorted_arr[key]);
			key = j;
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}