/****************************************************************************
힙 정렬 : 
	힙 자료구조를 이용해 최댓값과 최솟값을 빠르게 구하며, 
	최대 힙, 최소 힙을 만들면서 정렬한다.
	O(nlogn)
	추가 메모리 필요 없음.

	0. 힙은 일반적인 배열로 표현할 때, 
	i번째 노드의 왼쪽 자식은 i*2, 오른쪽 자식은 i*2+1
	힙정렬을할 땐 0부터 시작함. 왼쪽 i * 2 + 1, 오른쪽 i * 2 + 2.
	1. 최대 힙 또는 최소 힙을 만든다.
	2. root를 맨 마지막 노드와 바꾼다.
	3. 맨 마지막 원소를 제외하고 1~2를 반복한다.

참고한 링크 : https://reakwon.tistory.com/43
****************************************************************************/

#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#define ARRSIZE 10

using namespace std;

//난수 생성함수
int GetRandomInt(int min, int max);
void HeapSort(array<int, ARRSIZE>& arr);
void BulidHeap(array<int, ARRSIZE>& arr);
void MaxHeapify(array<int, ARRSIZE>& arr, int start, int size);

int main() {
	array <int, ARRSIZE> arr = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		arr[i] = GetRandomInt(-5, 5);
	}
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << "==> 정렬 전 배열\n======================================\n";
	HeapSort(arr);
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

void HeapSort(array<int, ARRSIZE>& arr) {
	//배열을 힙 모양으로 고치는 함수를 Heapify로 정의
	//Headpify는 Heapify 할 위치의 노드부터 자식 노드들을 기준으로 최대 혹은 최소 힙 기준에 맞게
	//swap을 실행.

	//Heapify만 사용하면 최대 or 최소 힙이 제대로 만들어지지 않아서
	//처음에는 무조건 배열을 최대힙 형태로 한 번 바꿔야 함.
	//그 함수의 이름을 BuildHeap이라고 정의
	BulidHeap(arr);	//한 번 힙모양으로 바꾸고나면
	for (int i = arr.size() - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //이후에는 최대 힙만 찾아서 가장 큰 값을 맨 뒤로만 바꾸면 됨.
		MaxHeapify(arr, 0, i);
	}
}

void BulidHeap(array<int, ARRSIZE>& arr) {
	//Heapify를 리프노드를 제외한 노드부터 루트 노드까지 역순으로 호출함
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		MaxHeapify(arr, i, arr.size());
	}
}

void MaxHeapify(array<int, ARRSIZE>& arr, int start, int size) {
	int left = start * 2 + 1;
	int right = start * 2 + 2;
	int largest = start;
	//부모 노드 기준으로 왼쪽과 오른쪽 자식 노드중 가장 큰 값을 찾음 (그래서 largest를 하나만 두는 것)
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	//부모 노드가 제일 큰 상태가 아니라면
	if (largest != start) {
		swap(arr[largest], arr[start]);
		//최대값을 찾은 자식에 대해서 또 MaxHeapify 수행
		MaxHeapify(arr, largest, size);
	}
}