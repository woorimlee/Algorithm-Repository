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

�� �ڵ忡�� 2�� �־��� ��쿡�� ���� �ð� ���� �˰����� �����ߴ�.
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

int FindMedian(int arr[], int n);
int WorstCaseLinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k);

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
		cout << "\n" << k << "��° ���� ������ �� :";
		cout << WorstCaseLinearTimeSelection(arr, 0, arr.size() - 1, k) << "\n";
		cout << "���ĵ� �迭 : ";
		sort(arr.begin(), arr.end());
		for (auto it : arr) {
			cout << it << " ";
		}
	//	cout << "\n�� ȸ ��\n";
	//}
	return 0;
}

//�־��� ��Ȳ���� ���� �ð� ���� �˰��� ���� �Լ�
int FindMedian(int arr[], int n)
{
	sort(arr, arr + n);
	return arr[n / 2];
}

//sort�� �ʹ� �����ѰͰ���. std::sort �Լ��� worst case ���� O(nlogn)�� �����Ѵ�.
//�̹� ���ĵ� �κ����� Ȯ���ϴ� �Լ� �ϳ� ���� ���ĵǾ������� sort()�Լ� �����ϴ°� �����ָ� ����ӵ��� ���� ���Ǳ� �ϰڳ�.
int WorstCaseLinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k) {
	/*
	�˰���
	1. ��ü �迭�� 5���� ���� �� n/5���� �׷��� �����.
	2. �� �׷��� �����ϰ� �߰� ���� ã�Ƴ���. �̶�, �� �׷��� �߰� ���� m1, m2, ... mn/5�� ����Ѵ�.
	3. m1, m2, ... mn/5�� �� �� �߰� ���� �� �Լ��� ����Լ��� ���� ���Ѵ�. (k = �迭 ũ�� / 2�� �ѱ�)
	4. 3���� ���� �߰� ���� M�̶�� �� ��, M�� �迭�� �� �ڷ� ������ �� ��Ʈ ����� �̿��� 
		M���� ���� ���� �迭�� ��������, ū ���� ���������� �����Ѵ�.
	5. k == M�� ��ġ��� M�� ����, K > M�� ��ġ��� ������ �迭��, K < M�� ��ġ��� ���� �迭�� Ž���Ѵ�.
	*/

	//ó���� ���� ������ ����
	if (start == end) {
		return arr[start];
	}
	//5�� �����̸� ã�ƺ��� ����
	else if (end - start <= 4) {
		sort(arr.begin() + start, arr.begin() + end + 1);
		return arr[k - 1];
	}

	//1 & 2. n/5���� �׷����� ������ �߰� ���� �����Ѵ�.
	int i=0, size = end-start+1;
	int* median;
	median = new int[(size+ 4) / 5]; //size�� 6~ 10�̸� �� �� ������ �ϰ�, ...  
	//cout << "median : ";
	for (i = 0; i < size / 5; i++) {
		//(size+4)/5�� ��ŭ ������� �迭 �� �� ������ �ε��� �����
		//��� 5���� ���غ� �� ����.
		//���� Ž������ �迭�� ù ��ġ + i*5��°���� 5�� �� �߰� �� ã��
		median[i] = FindMedian(&arr[start] + start + i * 5, 5);
		//cout << median[i] << " ";
	}
	if (size % 5 != 0) {
		median[i] = FindMedian(&arr[start] + start + i * 5, size % 5);
		//cout << median[i] << "\n";
	}

	//3. m1, m2, ..., mn/5 �� �߰� ���� ��������� ���Ѵ�.
	sort(median, median + (size + 4) / 5);
	int med_of_med = median[((size + 4) / 5) / 2];
	//cout << "medofmed : " << med_of_med << "\n" ;

	//4. M�� pivot���� �� ������ ������ ����.
	//1) M�� index�� ���Ѵ�.
	i = start;
	for (; i < end; i++) {
		if (arr[i] == med_of_med) {
			break;
		}
	}
	//2) M�� �� �ڷ� ������
	//Ȯ�ο�
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/
	swap(arr[i], arr[end]);
	//Ȯ�ο�
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/
	//3) partition ����
	i = start;
	int j = start;
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
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/

	//5. M�� �ε����� k�� ���ϰ� subarray�� ���� ��� Ž���� �����Ѵ�.
	//ã�� ��ġ == �Ǻ� ��ġ�� �� ã��
	if (k == i) {
		return arr[i - 1];
	}
	//���� ũ�� �������� ���
	else if (i > k) {
		return WorstCaseLinearTimeSelection(arr, start, i - 2, k);
	}
	//������ ���������� ���
	else if (i < k) {
		return WorstCaseLinearTimeSelection(arr, i, end, k);
	}
}
