/****************************************************************************
�պ� ���� : �� ���̸��� ����� ���� �˰�������, divide and conquer ����� ����� ���� ���� �˰���.
	O(nlogn) <-- �� nlogn + �̵� 2nlogn == 3nlogn
	�ӽ� �迭�� ���� �ʿ��� ����ε� -> ���� ����Ʈ�� �����Ѵٸ� �ӽ� �迭���� �־��� �迭�� ����ص� ��.
	������ data�� �����̵� ���� ���ĵǴ� �ð��� ������ �������� ���� �����. (�� ���� ���� ���� �������)

	�ѷ� �������� �迭�� merge�ϴ� �������� ������ ������ �̷���.
	1. �� �迭�� ���� �տ������� ���ϸ� �� ���� ���� �� �迭�� �տ� ����
	2. �� �� �ϳ��� ���ϴ� ������ ������ ������ �� �迭�� ���� �� �迭�� ���� ����
	3. ���� ������� �迭�� ���� �迭�� ����
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max);

void MergeSort(array<int, ARRSIZE>& arr);
void RunMS(array <int, ARRSIZE>& arr, int left, int right);
void Merge(array <int, ARRSIZE>& arr, int left, int mid, int right);


int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	MergeSort(arr);
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

//�迭�� ������ ������ �� �κ� �迭�� ��������� �����ϰ� �ϳ��� ��ħ.
void MergeSort(array<int, ARRSIZE>& arr) {

	RunMS(arr, 0, arr.size() - 1);

	for (auto it : arr) {
		cout << it << " ";
	}
	return;
}

void RunMS(array <int, ARRSIZE>& arr, int left, int right) {
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

void Merge(array <int, ARRSIZE>& arr, int left, int mid, int right) {
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