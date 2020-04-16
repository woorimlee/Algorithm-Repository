/*************************************************************************
n개의 원소로 구성된 배열에서 k 번째 작은 원소를 찾고자 한다면
1) 정렬 -> 2) k번째 작은 원소 찾기
nlogn + k
O(nlogn)의 시간이 걸린다.

이 알고리즘을 O(n)으로 바꾸기 위한 두 가지 방법이 있다.
1. 평균 선형 시간 선택 알고리즘
2. 최악의 경우 선형 시간 선택 알고리즘

1의 경우 O(n) ~ O(n^2)의 속도가 나오는 알고리즘이고,
2의 경우 1번 알고리즘의 최악의 경우를 보완하는 방법으로,
평균 수행시간이 O(n)이 되도록 하는 알고리즘이다.

이 코드에선 1인 평균 선형 시간 선택 알고리즘을 구현했다.
*************************************************************************/

#include <iostream>
#include <array>
#include <algorithm>
#include <random>

#define ARRSIZE 10

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

int LinearTimeSelection(array <int, ARRSIZE>& arr, int s, int e, int k);

int main() {
	//for (int T = 0; T < 20; T++) {
	array <int, ARRSIZE> arr;
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 10);
	}

	cout << "주어진 배열\n";
	for (auto it : arr) {
		cout << it << " ";
	}

	int k = GetRandomInt(1, ARRSIZE);
	cout << "\n" << k << "번째 작은 원소의 값 : ";
	cout << LinearTimeSelection(arr, 0, arr.size() - 1, k) << "\n";
	cout << "정렬된 배열 : ";
	sort(arr.begin(), arr.end());
	for (auto it : arr) {
		cout << it << " ";
	}
	//	cout << "\n한 회 끝\n";
	//}
	return 0;
}

int LinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k) {
	/*
	퀵 정렬을 기억하는가?
	pivot을 정하고 피봇보다 작은 값은 배열의 왼쪽에, 큰 값은 오른쪽으로
	값을 이동시키는 알고리즘을 이용할 것이다.
	arr[] = {5, 1, 6, 7, 2}
	2를 pivot으로 잡고 퀵 정렬 한 번 해보면
	arr[] = {1, 2, 6, 7, 5}와 같이 바뀌는데, 이때 교체할 값으로 쓰이던 변수 값은
	1로 나올 것이다. (-> 두번째로 작은 값)
	만약 k번째 작은 원소를 찾는 데 k의 값이 2이면 답 찾은 것이고,
	2보다 작으면 왼쪽 부분에, 2보다 크면 오른쪽 배열에 원하는 답이 있을 것이다.
	*/

	//처음과 끝이 같으면 리턴
	if (start == end) {
		return arr[start];
	}

	//partition
	//피봇이 몇 번째 위친지 구하기
	int i = start; //교체할 인덱스
	int j = start; //비교할 인덱스
	while (j <= end) {
		//피봇보다 작은 놈 찾으면 교체, 큰 놈 찾으면 비교할 놈 위치만 바꾸기
		if (arr[end] >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//위 반복문에서 마지막에 i++하기 때문에 피봇의 인덱스 값이 1 증가 된 상태.

	//확인용
	/*
	for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";
	cout << start  <<" " << end << " "  << i<< "\n";*/


	//찾는 위치 == 피봇 위치면 답 찾음
	if (k == i) {
		return arr[i - 1];
	}
	//만약 크면 왼쪽으로 재귀
	else if (i > k) {
		return LinearTimeSelection(arr, start, i - 2, k);
	}
	//작으면 오른쪽으로 재귀
	else if (i < k) {
		return LinearTimeSelection(arr, i, end, k);
	}
}
