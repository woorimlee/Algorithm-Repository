/*************************************************************************
n���� ���ҷ� ������ �迭���� k ��° ���� ���Ҹ� ã���� �Ѵٸ�
1) ���� -> 2) k��° ���� ���� ã��
nlogn + k
O(nlogn)�� �ð��� �ɸ���.

�� �˰����� O(n)���� �ٲٱ� ���� �� ���� ����� �ִ�.
1. ��� ���� �ð� ���� �˰���
2. �־��� ��� ���� �ð� ���� �˰���

1�� ��� O(n) ~ O(n^2)�� �ӵ��� ������ �˰����̰�,
2�� ��� 1�� �˰����� �־��� ��츦 �����ϴ� �������,
��� ����ð��� O(n)�� �ǵ��� �ϴ� �˰����̴�.

�� �ڵ忡�� 1�� ��� ���� �ð� ���� �˰����� �����ߴ�.
*************************************************************************/

#include <iostream>
#include <array>
#include <algorithm>
#include <random>

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

int LinearTimeSelection(array <int, ARRSIZE>& arr, int s, int e, int k);

int main() {
	//for (int T = 0; T < 20; T++) {
	array <int, ARRSIZE> arr;
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 10);
	}

	cout << "�־��� �迭\n";
	for (auto it : arr) {
		cout << it << " ";
	}

	int k = GetRandomInt(1, ARRSIZE);
	cout << "\n" << k << "��° ���� ������ �� : ";
	cout << LinearTimeSelection(arr, 0, arr.size() - 1, k) << "\n";
	cout << "���ĵ� �迭 : ";
	sort(arr.begin(), arr.end());
	for (auto it : arr) {
		cout << it << " ";
	}
	//	cout << "\n�� ȸ ��\n";
	//}
	return 0;
}

int LinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k) {
	/*
	�� ������ ����ϴ°�?
	pivot�� ���ϰ� �Ǻ����� ���� ���� �迭�� ���ʿ�, ū ���� ����������
	���� �̵���Ű�� �˰����� �̿��� ���̴�.
	arr[] = {5, 1, 6, 7, 2}
	2�� pivot���� ��� �� ���� �� �� �غ���
	arr[] = {1, 2, 6, 7, 5}�� ���� �ٲ�µ�, �̶� ��ü�� ������ ���̴� ���� ����
	1�� ���� ���̴�. (-> �ι�°�� ���� ��)
	���� k��° ���� ���Ҹ� ã�� �� k�� ���� 2�̸� �� ã�� ���̰�,
	2���� ������ ���� �κп�, 2���� ũ�� ������ �迭�� ���ϴ� ���� ���� ���̴�.
	*/

	//ó���� ���� ������ ����
	if (start == end) {
		return arr[start];
	}

	//partition
	//�Ǻ��� �� ��° ��ģ�� ���ϱ�
	int i = start; //��ü�� �ε���
	int j = start; //���� �ε���
	while (j <= end) {
		//�Ǻ����� ���� �� ã���� ��ü, ū �� ã���� ���� �� ��ġ�� �ٲٱ�
		if (arr[end] >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//�� �ݺ������� �������� i++�ϱ� ������ �Ǻ��� �ε��� ���� 1 ���� �� ����.

	//Ȯ�ο�
	/*
	for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";
	cout << start  <<" " << end << " "  << i<< "\n";*/


	//ã�� ��ġ == �Ǻ� ��ġ�� �� ã��
	if (k == i) {
		return arr[i - 1];
	}
	//���� ũ�� �������� ���
	else if (i > k) {
		return LinearTimeSelection(arr, start, i - 2, k);
	}
	//������ ���������� ���
	else if (i < k) {
		return LinearTimeSelection(arr, i, end, k);
	}
}
