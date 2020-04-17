/****************************************************************************
Bubble Sort :
	앞에서부터 두 개씩 비교해나가며 오름차순, 내림차순 기준에 맞춰 swap한다.
	O(N^2)의 시간 복잡도를 가짐.

	1. 배열의 맨 앞에서부터 두 개씩 원소 값을 비교한다.
	2. 필요한 경우 swap한다.
	3. swap된 맨 뒷 부분은 다음 검색에서 제외한다.
	4. 1~3을 반복한다.

Improved Bubble Sort : 
	버블 정렬의 1~3을 반복하면서 bool 변수 하나를 이용해 더 이상 정렬이 필요없는지 검사한다.
	만약, 앞에서 두 개씩 원소 값을 비교하는데, 배열의 끝까지 도달했을 때 swap한 적이 한 번도 없다면
	그 배열은 정렬이 끝난 상태이니 더 이상 버블 정렬을 할 필요가 없다.
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
int GetRandomInt(int min, int max);
void BubbleSort(array<int, ARRSIZE>& arr);
void ImprovedBubbleSort(array<int, ARRSIZE>& arr);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> 정렬 전 배열\n======================================\n버블 정렬 : ";
	BubbleSort(arr);
	cout << "==> 정렬 후 배열\n발전된 버블 정렬 : ";
	ImprovedBubbleSort(arr);
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

//버블 정렬. 이웃한 두 원소를 비교해 정렬이 필요하면 swap.
void BubbleSort(array<int, ARRSIZE>& arr) {
	//O(N^2)
	array<int, ARRSIZE> sorted_arr = arr;
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
void ImprovedBubbleSort(array<int, ARRSIZE>& arr) {
	/*버블 정렬을 한 창 시행중인데, 더이상 정렬이 필요없는 상황이 있을 수 있음.
	ex) arr = {0, 5, 9, 11, 8};
	버블정렬 1회 : arr = {0, 5, 9, 8, 11};
	버블정렬 2회 : arr = {0, 5, 8, 9, 11};
	2회만에 정렬이 끝났음에도 최소 두 번 버블정렬을 더 시행함.
	이런 경우를 위해 bool 변수를 하나 만듦.
	*/
	bool flag = true;
	array<int, ARRSIZE> sorted_arr = arr;
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
			cout << "(bubble sort 도중에 끝남) ";
			//더이상 정렬이 필요없는 상태.
			break;
		}
	}

	for (auto it : sorted_arr) {
		cout << it << " ";
	}
	return;
}