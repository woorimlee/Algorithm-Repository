/****************************************************************************
합병 정렬 : 폰 노이만이 고안한 정렬 알고리즘으로, divide and conquer 방식이 적용된 분할 정복 알고리즘.
	O(nlogn) <-- 비교 nlogn + 이동 2nlogn == 3nlogn
	임시 배열이 많이 필요한 방법인데 -> 연결 리스트로 구현한다면 임시 배열없이 주어진 배열만 사용해도 됨.
	정렬할 data가 무엇이든 간에 정렬되는 시간은 동일한 안정적인 정렬 방법임. (퀵 정렬 같은 것은 비안정적)

	둘로 나뉘어진 배열을 merge하는 과정에서 실제로 정렬이 이뤄짐.
	1. 두 배열의 값을 앞에서부터 비교하며 더 작은 값을 새 배열의 앞에 저장
	2. 둘 중 하나가 비교하는 과정이 끝나면 나머지 한 배열의 값을 새 배열의 뒤편에 저장
	3. 새로 만들어진 배열을 원래 배열에 저장
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
int GetRandomInt(int min, int max);

void MergeSort(array<int, ARRSIZE>& arr);
void RunMS(array <int, ARRSIZE>& arr, int left, int right);
void Merge(array <int, ARRSIZE>& arr, int left, int mid, int right);


int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> 정렬 전 배열\n======================================\n";
	MergeSort(arr);
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

//배열을 반으로 나눠서 각 부분 배열을 재귀적으로 정렬하고 하나로 합침.
void MergeSort(array<int, ARRSIZE>& arr) {

	RunMS(arr, 0, arr.size() - 1);

	for (auto it : arr) {
		cout << it << " ";
	}
	return;
}

void RunMS(array <int, ARRSIZE>& arr, int left, int right) {
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

void Merge(array <int, ARRSIZE>& arr, int left, int mid, int right) {
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