/****************************************************************************
퀵 정렬 : 
	정렬할 data에 따라 실행 속도가 달라지는 불안정 정렬로, 
	divide and conquer 방식이 적용된 가장 빠른 정렬 방식. (대표적인 정렬 법들 중)
	O(nlogn) ~ O(n^2)

	오름차순 기준으로
	피봇을 기준으로 피봇보다 작은 값은 배열의 왼쪽으로, 큰 값은 배열의 오른쪽으로 보내며 피봇을 중심으로 정렬을 수행하고,
	방금 수행된 정렬이 끝나면 피봇 기준 왼쪽과 오른쪽 sub array에 대한 퀵정렬을 다시 실행한다.
	
	최악의 경우는 이미 정렬이 끝나있는 경우!
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
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
	cout << "==> 정렬 전 배열\n======================================\n";
	QuickSort(arr, 0, ARRSIZE-1);
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

//퀵 정렬. pivot을 이용한 정렬.
//구현 방법이 매우 다양함.
void QuickSort(array<int, ARRSIZE>& arr, int left, int right) {
	//base condition
	if (left >= right) {
		return;
	}

	//피봇은 맨 끝에 값으로 설정하고,
	//피봇 기준으로 swap 실행
	int i = left; //교체해줄 인덱스 (교체해줄때만 1씩 증가)
	int j = left; //비교해줄 인덱스 (계속 1씩 증가)
	int pivot = arr[right];
	while (j <= right) {
		//피봇보다 작은 값 찾으면 교체, 큰 값 찾으면 비교할 위치반 증가
		if (pivot >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//왼쪽과 오른쪽 sub array에 대한 Quick Sort 실행
	QuickSort(arr, left, i - 2);
	QuickSort(arr, i, right);
}