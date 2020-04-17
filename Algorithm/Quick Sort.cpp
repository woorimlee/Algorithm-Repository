/****************************************************************************
�� ���� : 
	������ data�� ���� ���� �ӵ��� �޶����� �Ҿ��� ���ķ�, 
	divide and conquer ����� ����� ���� ���� ���� ���. (��ǥ���� ���� ���� ��)
	O(nlogn) ~ O(n^2)

	�������� ��������
	�Ǻ��� �������� �Ǻ����� ���� ���� �迭�� ��������, ū ���� �迭�� ���������� ������ �Ǻ��� �߽����� ������ �����ϰ�,
	��� ����� ������ ������ �Ǻ� ���� ���ʰ� ������ sub array�� ���� �������� �ٽ� �����Ѵ�.
	
	�־��� ���� �̹� ������ �����ִ� ���!
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//���� �����Լ�
int GetRandomInt(int min, int max); 
void QuickSort(array<int, ARRSIZE>& arr, int left, int right);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> ���� �� �迭\n======================================\n";
	QuickSort(arr, 0, ARRSIZE-1);
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

//�� ����. pivot�� �̿��� ����.
//���� ����� �ſ� �پ���.
void QuickSort(array<int, ARRSIZE>& arr, int left, int right) {
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
	QuickSort(arr, left, i - 2);
	QuickSort(arr, i, right);
}