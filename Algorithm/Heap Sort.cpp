/****************************************************************************
�� ���� : 
	�� �ڷᱸ���� �̿��� �ִ񰪰� �ּڰ��� ������ ���ϸ�, 
	�ִ� ��, �ּ� ���� ����鼭 �����Ѵ�.
	O(nlogn)
	�߰� �޸� �ʿ� ����.

	0. ���� �Ϲ����� �迭�� ǥ���� ��, 
	i��° ����� ���� �ڽ��� i*2, ������ �ڽ��� i*2+1
	���������� �� 0���� ������. ���� i * 2 + 1, ������ i * 2 + 2.
	1. �ִ� �� �Ǵ� �ּ� ���� �����.
	2. root�� �� ������ ���� �ٲ۴�.
	3. �� ������ ���Ҹ� �����ϰ� 1~2�� �ݺ��Ѵ�.

������ ��ũ : https://reakwon.tistory.com/43
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max);
void HeapSort(array<int, ARRSIZE>& arr);
void BulidHeap(array<int, ARRSIZE>& arr);
void MaxHeapify(array<int, ARRSIZE>& arr, int start, int size);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	HeapSort(arr);
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

void HeapSort(array<int, ARRSIZE>& arr) {
	//�迭�� �� ������� ��ġ�� �Լ��� Heapify�� ����
	//Headpify�� Heapify �� ��ġ�� ������ �ڽ� ������ �������� �ִ� Ȥ�� �ּ� �� ���ؿ� �°�
	//swap�� ����.

	//Heapify�� ����ϸ� �ִ� or �ּ� ���� ����� ��������� �ʾƼ�
	//ó������ ������ �迭�� �ִ��� ���·� �� �� �ٲ�� ��.
	//�� �Լ��� �̸��� BuildHeap�̶�� ����
	BulidHeap(arr);	//�� �� ��������� �ٲٰ���
	for (int i = arr.size() - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //���Ŀ��� �ִ� ���� ã�Ƽ� ���� ū ���� �� �ڷθ� �ٲٸ� ��.
		MaxHeapify(arr, 0, i);
	}
}

void BulidHeap(array<int, ARRSIZE>& arr) {
	//Heapify�� ������带 ������ ������ ��Ʈ ������ �������� ȣ����
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		MaxHeapify(arr, i, arr.size());
	}
}

void MaxHeapify(array<int, ARRSIZE>& arr, int start, int size) {
	int left = start * 2 + 1;
	int right = start * 2 + 2;
	int largest = start;
	//�θ� ��� �������� ���ʰ� ������ �ڽ� ����� ���� ū ���� ã�� (�׷��� largest�� �ϳ��� �δ� ��)
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	//�θ� ��尡 ���� ū ���°� �ƴ϶��
	if (largest != start) {
		swap(arr[largest], arr[start]);
		//�ִ밪�� ã�� �ڽĿ� ���ؼ� �� MaxHeapify ����
		MaxHeapify(arr, largest, size);
	}
}