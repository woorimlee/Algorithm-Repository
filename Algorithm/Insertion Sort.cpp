/****************************************************************************
삽입 정렬 :
	배열의 한 원소씩 앞에서부터 비교하며 그 원소의 적절한 위치를 찾아 그곳에 자신을 삽입하는 방식.
	O(N^2) ~ O(N)의 시간 복잡도를 가짐.

	정렬하고자 하는 원소 하나를 바로 앞의 인덱스와 swap
	1. [n]번째 원소부터 시작하며, 바로 이전의 원소와 자신의 값을 비교한다.
	2. 오름차순 기준으로 [n] 인덱스가 [n-1]보다 값이 크거나 같다면 swap을 할 필요가 없다.
	3. 반대라면 swap을 진행한다.
	4. 3을 실행하면, [n]인덱스에 있던 값이 [n-1]으로 위치하게 되는데, [n-1]에서 이전 인덱스인 [n-2]와 또 2~3번을 반복한다.(비교한다).
	5. 1~4를 반복하며 [n]의 값을 1 증가시킨다.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
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
	cout << "==> 정렬 전 배열\n======================================\n";
	InsertionSort(arr);
	cout << "==> 정렬 후 배열\n";
	return 0;
}

int GetRandomInt(int min, int max) {
	random_device rd;
	//랜덤 디바이스 객체 생성시 하드웨어의 리소스로 랜덤한 숫자를 생성
	mt19937 mt(rd());
	//메르센 트위스터 엔진에 객체 전달

	//시드 설정 끝

	//난수의 타입을 결정.
	//min~ max까지 모든 숫자 다 나올 수 있음. 닫힌 구간임.
	uniform_int_distribution <int> range(min, max);

	//값 추출
	return range(mt);
}

//삽입 정렬. 배열의 원소들을 앞에서부터 비교하며 자신의 적절한 위치를 찾아 그곳에 자신을 삽입함.
void InsertionSort(array<int, ARRSIZE>& arr) {
	/*O(N^2) ~ O(N)
	정렬하고자 하는 원소 하나를 필요한 경우 앞으로 땡겨오는 느낌.
	ex) arr = {10, 20, 5, 30};
	1차전 : 정렬하고자 하는 원소 = 20
		-> 20의 전 원소(5)와 20의 값을 비교 -> 정렬할 필요 없음
	2차전 : 정렬하고자 하는 원소 = 5
		-> 5의 전 원소(20)와 5를 비교 -> {10, 5, 20, 30} -> 5의 전 원소(10)와 5를 비교 -> {5, 10, 20, 30}
	3차전 : 정렬하고자 한흔 원소 = 30
		-> 30의 전 원소(20)와 30을 비교 -> 정렬할 필요 없음
	*/
	array<int, ARRSIZE> sorted_arr = arr;

	//방법 1
	/*int key = sorted_arr[1];
	int j = 0;
	for (int i = 1; i < sorted_arr.size(); i++) {
		key = sorted_arr[i];
		for (j = i - 1; j >= 0 && sorted_arr[j] > key; j--) {
			sorted_arr[j + 1] = sorted_arr[j];
		}
		sorted_arr[j + 1] = key;
	}*/

	//방법 2
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