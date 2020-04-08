#include <iostream>
#include <random>
#include <array>
#include <algorithm>

using namespace std;

//난수 생성함수
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

void SelectionSort(array<int, 10> & arr);
void BubbleSort(array<int, 10> & arr);
void ImprovedBubbleSort(array<int, 10> & arr);
void InsertionSort(array<int, 10> & arr);
//합병 정렬용 아래 세 개의 함수
void MergeSort(array<int, 10> & arr);
void RunMS(array <int, 10> & arr, int left, int right);
void Merge(array <int, 10> & arr, int left, int mid, int right);

int main() {
	array <int, 10> arr = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[i] = GetRandomInt(-20, 20);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> 정렬 전 배열\n======================================\n";
	
	//이하 알고리즘 평균 O(N^2)
	//SelectionSort(arr);
	//BubbleSort(arr);
	//ImprovedBubbleSort(arr);
	//InsertionSort(arr);
	MergeSort(arr);

	//이하 알고리즘 평균 O(NlogN)


	cout << "==> 정렬 후 배열\n";
	return 0;
}

//선택 정렬. 최대 혹은 최솟값을 찾아서 맨 뒤나 맨 앞으로 옮긴다.
void SelectionSort(array<int, 10> & arr) {
	//O(N^2)
	int index = 0;
	array<int, 10> sorted_arr = arr;
	//1. 배열에서 가장 큰 값을 찾는다.
	//2. 맨 뒤의 값이랑 swap한다. (swap된 맨 뒷 부분 다음 검색에서 제외)
	//3. 맨 앞의 자료는 최솟값으로 정렬되니, i가 1이 될때까지만 위 과정을 반복한다.
	for (int i = sorted_arr.size() - 1; i >= 1; i--) {
		index = i;
		for (int j = 0; j <= i; j++) {
			if (sorted_arr[index] < sorted_arr[j]) {
				index = j;
			}
		}
		if(i != index)
			swap(sorted_arr[i], sorted_arr[index]);
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//버블 정렬. 이웃한 두 원소를 비교해 정렬이 필요하면 swap.
void BubbleSort(array<int, 10> & arr) {
	//O(N^2)
	array<int, 10> sorted_arr = arr;
	for (int i = 0; i < sorted_arr.size() - 1; i++) {
		//두 개씩 비교해나가니까 맨 마지막 원소의 위치 -1 까지만 for 구문을 돌림.
		//+ 정렬 한 번 끝나면 맨 끝에는 검사할 필요가 없음
		for (int j = 0; j < sorted_arr.size() - 1 - i; j++) {
			if (sorted_arr[j] > sorted_arr[j + 1]) {
				swap(sorted_arr[j], sorted_arr[j + 1]);
			}
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//Improved Bubble Sort. Modified Bubble Sort.
void ImprovedBubbleSort(array<int, 10> & arr) {
	/*버블 정렬을 한 창 시행중인데, 더이상 정렬이 필요없는 상황이 있을 수 있음.
	ex) arr = {0, 5, 9, 11, 8};
	버블정렬 1회 : arr = {0, 5, 9, 8, 11};
	버블정렬 2회 : arr = {0, 5, 8, 9, 11};
	2회만에 정렬이 끝났음에도 최소 두 번 버블정렬을 더 시행함.
	이런 경우를 위해 bool 변수를 하나 만듦.
	*/
	bool flag = true;
	array<int, 10> sorted_arr = arr;
	for (int i = 0; i < sorted_arr.size() - 1; i++) {
		flag = true;
		//두 개씩 비교해나가니까 맨 마지막 원소의 위치 -1 까지만 for 구문을 돌림.
		//+ 정렬 한 번 끝나면 맨 끝에는 검사할 필요가 없음
		for (int j = 0; j < sorted_arr.size() - 1 - i; j++) {
			if (sorted_arr[j] > sorted_arr[j + 1]) {
				swap(sorted_arr[j], sorted_arr[j + 1]);
				flag = false;
			}
		}
		if (flag) {
			cout << "bubble sort 도중에 끝남\n";
			//더이상 정렬이 필요없는 상태.
			break;
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}

//삽입 정렬. 배열의 원소들을 앞에서부터 비교하며 자신의 적절한 위치를 찾아 그곳에 자신을 삽입함.
void InsertionSort(array<int, 10> & arr) {
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
	array<int, 10> sorted_arr = arr;

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

	for(auto it : sorted_arr){
		cout << it << " ";
	}
	return;
}

//합병 정렬. 폰 노이만이 고안한 정렬 알고리즘으로,
//divide and conquer 방식이 적용된 분할 정복 알고리즘.
//배열을 반으로 나눠서 각 부분 배열을 재귀적으로 정렬하고 하나로 합침.
void MergeSort(array<int, 10> & arr) {
	/*
	O(nlogn) <-- 비교 nlogn + 이동 2nlogn == 3nlogn
	특징 : 
	임시 배열이 많이 필요함 -> 연결 리스트로 구현한다면 임시 배열없이 주어진 배열만 사용해도 됨.
	정렬할 data가 무엇이든 간에 정렬되는 시간은 동일한 안정적인 정렬 방법임
	
	정렬 방법 : 
	둘로 나뉘어진 배열을 merge하는 과정에서 실제로 정렬이 이뤄짐.
		1. 두 배열의 값을 앞에서부터 비교하며 더 작은 값을 새 배열의 앞에 저장
		2. 둘 중 하나가 비교하는 과정이 끝나면 나머지 한 배열의 값을 새 배열의 뒤편에 저장
		3. 새로 만들어진 배열을 원래 배열에 저장
	*/

	RunMS(arr, 0, arr.size()-1);

	for (auto it : arr) {
		cout << it << " ";
	}
	return;
}
void RunMS(array <int, 10> & arr, int left, int right) {
	int mid;
	//left와 right가 똑같은 상황 == divide가 끝나서 분할된 배열의 크기가 1인 상황
	if (left < right) {
		mid = (left + right) / 2;		//divide : 반으로 나누기 위한 인덱스 정의
		RunMS(arr, left, mid);			//conquer :  
		RunMS(arr, mid + 1, right);		//conquer : 위의 코드와 이 코드를 실행하고 난 결과 
										//배열은 반으로 쪼개져있으며, 그것들을 아래에서 정렬하고 합칠 예정
		Merge(arr, left, mid, right);	//merge, combine : 실제로 두 개의 부분 배열을 정렬 & 합병
	}
	return;
}
void Merge(array <int, 10> & arr, int left, int mid, int right) {
	//임시 공간이 필요
	array <int, 10> temp;
	//최적화 하고 싶으면 (right - left) + 1의 크기만큼의 배열만 만들어도 됨.

	int i = left; //왼쪽 부분 집합의 첫 원소 위치
	int j = mid + 1; //오른쪽 부분 집합의 첫 원소 위치
	int k = left; //임시 배열에 값을 저장할 위치

	//두 부분 배열 중 한 쪽 배열의 정렬이 끝날때까지 (더 채울 값이 없을 때까지)
	while (i < (mid + 1) && j < (right + 1)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	//남은 한 쪽의 나머지 값 처리
	if (j > right) {
		//첫 번째 부분 배열에 값이 남아있는 상황
		for (int l = i; l < mid + 1; l++) {
			temp[k++] = arr[l];
		}
	}
	else {
		//두 번째 부분 배열에 값이 남아있는 상황
		for (int l = j; l < right + 1; l++) {
			temp[k++] = arr[l];
		}
	}

	//임시 공간에 있는 값을 원래 배열로 복사
	for (int l = left; l < right + 1; l++) {
		arr[l] = temp[l];
	}
	
	return;
}

//퀵 정렬.

//힙 정렬.

//셸 정렬.

//계수 정렬.

//기수 정렬.