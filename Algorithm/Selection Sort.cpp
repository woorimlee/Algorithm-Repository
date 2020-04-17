/****************************************************************************
선택 정렬 : 
	최대 혹은 최솟값을 찾아서 배열의 맨 뒤나 맨 앞으로 옮기는 방법.
	O(N^2)의 시간 복잡도를 가짐.

	1. 배열에서 가장 큰 값을 찾는다.
	2. 맨 뒤의 값과 가장 큰 값을 swap한다.
	3. swap된 맨 뒷 부분은 다음 검색에서 제외한다.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
int GetRandomInt(int min, int max);
void SelectionSort(array<int, ARRSIZE>& arr);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> 정렬 전 배열\n======================================\n";
	SelectionSort(arr);
	for (auto it : arr) {
		cout << it << " ";
	}
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

//선택 정렬. 최대 혹은 최솟값을 찾아서 맨 뒤나 맨 앞으로 옮긴다.
void SelectionSort(array<int, ARRSIZE>& arr) {
	//O(N^2)
	int index = 0;
	//1. 배열에서 가장 큰 값을 찾는다.
	//2. 맨 뒤의 값이랑 swap한다. (swap된 맨 뒷 부분 다음 검색에서 제외)
	//3. 맨 앞의 자료는 최솟값으로 정렬되니, i가 1이 될때까지만 위 과정을 반복한다.
	for (int i = arr.size() - 1; i >= 1; i--) {
		index = i;
		for (int j = 0; j <= i; j++) {
			if (arr[index] < arr[j]) {
				index = j;
			}
		}
		if (i != index)
			swap(arr[i], arr[index]);
	}
	return;
}