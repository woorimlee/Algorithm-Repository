/****************************************************************************
�� ���� :
	

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
}


//�� ����.

//��� ����.

//��� ����.