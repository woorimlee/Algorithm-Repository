#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

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

void SelectionSort(array<int, ARRSIZE> & arr);
void BubbleSort(array<int, ARRSIZE> & arr);
void ImprovedBubbleSort(array<int, ARRSIZE> & arr);
void InsertionSort(array<int, ARRSIZE> & arr);
//�պ� ���Ŀ� �Ʒ� �� ���� �Լ�
void MergeSort(array<int, ARRSIZE> & arr);
void RunMS(array <int, ARRSIZE> & arr, int left, int right);
void Merge(array <int, ARRSIZE> & arr, int left, int mid, int right);
void QuickSort(array<int, ARRSIZE> & arr, int left, int right);

int main() {
	for (int i = 0; i < 100; i++) {
		array <int, ARRSIZE> arr = { 0 };
		for (int i = 0; i < ARRSIZE; i++) {
			arr[i] = GetRandomInt(-5, 5);
		}
		for (auto it : arr) {
			cout << it << " ";
		}
		cout << "==> ���� �� �迭\n======================================\n";

		//���� �˰��� ��� O(N^2)
		//SelectionSort(arr);
		//BubbleSort(arr);
		//ImprovedBubbleSort(arr);
		//InsertionSort(arr);
		//���� �˰��� ��� O(NlogN)
		//MergeSort(arr);
		QuickSort(arr, 0, ARRSIZE - 1);
		for (auto it : arr) {
			cout << it << " ";
		}cout << "\n";


		cout << "==> ���� �� �迭\n";
	}
	return 0;
}

//���� ����. �ִ� Ȥ�� �ּڰ��� ã�Ƽ� �� �ڳ� �� ������ �ű��.
void SelectionSort(array<int, ARRSIZE> & arr) {
	//O(N^2)
	int index = 0;
	array<int, ARRSIZE> sorted_arr = arr;
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
void BubbleSort(array<int, ARRSIZE> & arr) {
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
void ImprovedBubbleSort(array<int, ARRSIZE> & arr) {
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

//���� ����. �迭�� ���ҵ��� �տ������� ���ϸ� �ڽ��� ������ ��ġ�� ã�� �װ��� �ڽ��� ������.
void InsertionSort(array<int, ARRSIZE> & arr) {
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

	for(auto it : sorted_arr){
		cout << it << " ";
	}
	return;
}

//�պ� ����. �� ���̸��� ����� ���� �˰�������,
//divide and conquer ����� ����� ���� ���� �˰���.
//�迭�� ������ ������ �� �κ� �迭�� ��������� �����ϰ� �ϳ��� ��ħ.
void MergeSort(array<int, ARRSIZE> & arr) {
	/*
	O(nlogn) <-- �� nlogn + �̵� 2nlogn == 3nlogn
	Ư¡ : 
	�ӽ� �迭�� ���� �ʿ��� -> ���� ����Ʈ�� �����Ѵٸ� �ӽ� �迭���� �־��� �迭�� ����ص� ��.
	������ data�� �����̵� ���� ���ĵǴ� �ð��� ������ �������� ���� �����
	
	���� ��� : 
	�ѷ� �������� �迭�� merge�ϴ� �������� ������ ������ �̷���.
		1. �� �迭�� ���� �տ������� ���ϸ� �� ���� ���� �� �迭�� �տ� ����
		2. �� �� �ϳ��� ���ϴ� ������ ������ ������ �� �迭�� ���� �� �迭�� ���� ����
		3. ���� ������� �迭�� ���� �迭�� ����
	*/

	RunMS(arr, 0, arr.size()-1);

	for (auto it : arr) {
		cout << it << " ";
	}
	return;
}
void RunMS(array <int, ARRSIZE> & arr, int left, int right) {
	int mid;
	//left�� right�� �Ȱ��� ��Ȳ == divide�� ������ ���ҵ� �迭�� ũ�Ⱑ 1�� ��Ȳ
	if (left < right) {
		mid = (left + right) / 2;		//divide : ������ ������ ���� �ε��� ����
		RunMS(arr, left, mid);			//conquer :  
		RunMS(arr, mid + 1, right);		//conquer : ���� �ڵ�� �� �ڵ带 �����ϰ� �� ��� 
										//�迭�� ������ �ɰ���������, �װ͵��� �Ʒ����� �����ϰ� ��ĥ ����
		Merge(arr, left, mid, right);	//merge, combine : ������ �� ���� �κ� �迭�� ���� & �պ�
	}
	return;
}
void Merge(array <int, ARRSIZE> & arr, int left, int mid, int right) {
	//�ӽ� ������ �ʿ�
	array <int, 10> temp;
	//����ȭ �ϰ� ������ (right - left) + 1�� ũ�⸸ŭ�� �迭�� ���� ��.

	int i = left; //���� �κ� ������ ù ���� ��ġ
	int j = mid + 1; //������ �κ� ������ ù ���� ��ġ
	int k = left; //�ӽ� �迭�� ���� ������ ��ġ

	//�� �κ� �迭 �� �� �� �迭�� ������ ���������� (�� ä�� ���� ���� ������)
	while (i < (mid + 1) && j < (right + 1)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	//���� �� ���� ������ �� ó��
	if (j > right) {
		//ù ��° �κ� �迭�� ���� �����ִ� ��Ȳ
		for (int l = i; l < mid + 1; l++) {
			temp[k++] = arr[l];
		}
	}
	else {
		//�� ��° �κ� �迭�� ���� �����ִ� ��Ȳ
		for (int l = j; l < right + 1; l++) {
			temp[k++] = arr[l];
		}
	}

	//�ӽ� ������ �ִ� ���� ���� �迭�� ����
	for (int l = left; l < right + 1; l++) {
		arr[l] = temp[l];
	}
	
	return;
}

//�� ����. pivot�� �̿��� ����.
void QuickSort(array<int, ARRSIZE> & arr, int left, int right) {
	/*������ data�� ���� ���� �ӵ��� �޶����� �Ҿ��� ������.
	divide and conquer �������, �ſ� ������ �պ� ���Ŀ� ���� ��յ��� ���� �����.
	�Ǻ��� �������� �Ǻ����� ���� ���� �迭�� ��������, ū ���� �迭�� ���������� ������ �Ǻ��� �߽����� ������ �����ϰ�, 
	������ ������ ���ʰ� ������ sub �迭�� ���� �������� �ٽ� �����Ѵ�.
	*/

	//base condition
	if (left >= right) {
		return;
	}
	
	//�Ǻ��� �� ���� ������ �����ϰ�,
	//�Ǻ� �������� swap ����
	int i = left; //��ü���� �ε��� (��ü���ٶ��� 1�� ����)
	int j = left; //������ �ε��� (��� 1�� ����)
	int pivot = arr[right];
	while (j <= right) {
		//�Ǻ����� ���� �� ã���� ��ü, ū �� ã���� ���� ��ġ�� ����
		if (pivot >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//���ʰ� ������ sub array�� ���� Quick Sort ����
	QuickSort(arr, left, i-2);
	QuickSort(arr, i, right);
}


//�� ����.

//�� ����.

//��� ����.

//��� ����.