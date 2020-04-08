#include <iostream>
#include <random>
#include <array>
#include <algorithm>

using namespace std;

//���� �����Լ�
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

void SelectionSort(array<int, 10> & arr);
void BubbleSort(array<int, 10> & arr);
void ImprovedBubbleSort(array<int, 10> & arr);
void InsertionSort(array<int, 10> & arr);

int main() {
	array <int, 10> arr = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[i] = GetRandomInt(-20, 20);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	//SelectionSort(arr);
	//BubbleSort(arr);
	//ImprovedBubbleSort(arr);
	InsertionSort(arr);

	cout << "==> ���� �� �迭\n";
	return 0;
}

//���� ����. �ִ� Ȥ�� �ּڰ��� ã�Ƽ� �� �ڳ� �� ������ �ű��.
void SelectionSort(array<int, 10> & arr) {
	//O(N^2)
	int index = 0;
	array<int, 10> sorted_arr = arr;
	//1. �迭���� ���� ū ���� ã�´�.
	//2. �� ���� ���̶� swap�Ѵ�. (swap�� �� �� �κ� ���� �˻����� ����)
	//3. �� ���� �ڷ�� �ּڰ����� ���ĵǴ�, i�� 1�� �ɶ������� �� ������ �ݺ��Ѵ�.
	for (int i = sorted_arr.size() - 1; i >= 1; i--) {
		index = i;
		for (int j = 0; j <= i; j++) {
			if (sorted_arr[index] < sorted_arr[j]) {
				index = j;
			}
		}
		if(i != index)
			swap(sorted_arr[i], sorted_arr[index]);
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//���� ����. �̿��� �� ���Ҹ� ���� ������ �ʿ��ϸ� swap.
void BubbleSort(array<int, 10> & arr) {
	//O(N^2)
	array<int, 10> sorted_arr = arr;
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
void ImprovedBubbleSort(array<int, 10> & arr) {
	/*���� ������ �� â �������ε�, ���̻� ������ �ʿ���� ��Ȳ�� ���� �� ����.
	ex) arr = {0, 5, 9, 11, 8};
	�������� 1ȸ : arr = {0, 5, 9, 8, 11};
	�������� 2ȸ : arr = {0, 5, 8, 9, 11};
	2ȸ���� ������ ���������� �ּ� �� �� ���������� �� ������.
	�̷� ��츦 ���� bool ������ �ϳ� ����.
	*/
	bool flag = true;
	array<int, 10> sorted_arr = arr;
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
			cout << "bubble sort ���߿� ����\n";
			//���̻� ������ �ʿ���� ����.
			break;
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//�迭�� ���ҵ��� �տ������� ���ϸ� �ڽ��� ������ ��ġ�� ã�� �װ��� �ڽ��� ������.
void InsertionSort(array<int, 10> & arr) {
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
	array<int, 10> sorted_arr = arr;

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

	for(auto it : sorted_arr){
		cout << it << " ";
	}
	return;
}