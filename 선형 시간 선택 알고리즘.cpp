#include <iostream>
#include <array>
#include <algorithm>
#include <random>
using namespace std;

/*
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
*/

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

int LinearTimeSelection(array <int, 10> & arr, int s, int e, int k);
int WorstCaseLinearTimeSelection();

int main() {
	array <int, 10> arr;
	for (int i = 0; i < 10; i++) {
		arr[i] = GetRandomInt(-20, 20);
	}

	cout << "�־��� �迭\n";
	for (auto it : arr) {
		cout << it << " ";
	}

	int k = GetRandomInt(1, 10);
	cout << "\n" << k << "��° ���� ������ �� : ";
	/*array <int, 10> test = { 5, 2, 3, 4, 6, 7, 8, 1, 11, 10 };
	int test_k = 9;
	cout << LinearTimeSelection(test, 0, 9, test_k);*/
	cout << LinearTimeSelection(arr, 0, 9, k) << "\n";
	cout << "���ĵ� �迭 : ";
	sort(arr.begin(), arr.end());
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "\n";

	return 0;
}

int LinearTimeSelection(array <int, 10> & arr, int s, int e, int k) { //s = start, e = end
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
	if (s == e)
		return s;

	//�Ǻ��� �� ��° ��ģ�� ���ϱ�
	int i = s; //��ü�� �ε���
	int j = s; //���� �ε���
	while (j <= e) {
		//�Ǻ����� ���� �� ã���� ��ü, ū �� ã���� ���� �� ��ġ�� �ٲٱ�
		if (arr[e] >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//�� �ݺ������� �������� i++�ϱ� ������ �Ǻ��� �ε��� ���� 1 ���� �� ����.
	//k�� �迭�� ũ�Ⱑ 10�϶� 1~ 10���� ���̴� ���̰�,
	//i�� 1 ������ ���´� i�� k�� �ٷ� ��
	//cout << k << i;


	//ã�� ��ġ == �Ǻ� ��ġ�� �� ã��
	if (k == i) {
		return arr[i - 1];
	}

	//���� ������ �������� ���
	else if (i < k) {
		return LinearTimeSelection(arr, s, i - 1, k);
	}
	//ũ�� ���������� ���

	else if (i > k) {
		return LinearTimeSelection(arr, i + 1, e, k);
	}
}

int WorstCaseLinearTimeSelection() {
	return 0;
}