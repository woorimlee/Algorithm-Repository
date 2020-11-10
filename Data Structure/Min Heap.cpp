/*
* Binary Heap은 아래의 조건을 따르는 이진 트리다.
* 1. 완전 이진 트리 (모든 노드는 위에서 아래로, 왼쪽에서 오른쪽으로 채워진 상태)
*   -> 이 조건에 따라, Binary Heap을 배열에 저장하기 좋음. (랜덤 액세스 가능)
* 2. Min Heap이거나 Max Heap이어야 한다.(root 노드의 key 값이 모든 노드 중에서 최소거나 최대)
* 3. 모든 sub tree도 위의 조건을 따른다.
부모와 자식 노드의 대소 관계만 중요하고, 형제 노드들간의 관계는 없다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
	int* heap = NULL; //heap elements array를 가리킬 공간
	int capacity = 0; //maximum size
	int heap_size = 0; //현재 heap의 size

public :
	MinHeap(int capa);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

	void insert_key(int key); // 새 값을 삽입. O(log n)
	int get_min(); // 최솟값 return. O(1)
	void pop_min(); // 최솟값 제거. O(log n) -> heap을 유지하기 위해 root를 제거한 후 heapify
	void min_heapify(int i); //i 번째 노드의 subtree를 heapify
	void print_heap();
};

int main() {
	MinHeap heap(10);
	heap.insert_key(10);
	heap.insert_key(5);
	heap.insert_key(6);
	heap.insert_key(8);
	heap.insert_key(1);
	heap.insert_key(2);
	heap.insert_key(16);
	heap.insert_key(7);

	//출력
	heap.print_heap();
	heap.get_min();
	
	//pop
	heap.pop_min();
	heap.pop_min();
	
	//출력
	heap.print_heap();
	heap.get_min();

	//힙 비우기
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min(); // 에러 출력

	return 0;
}

MinHeap::MinHeap(int capa) {
	heap = new int[capa];
	capacity = capa;
	heap_size = 0;
}

void MinHeap::insert_key(int k) {
	if (heap_size == capacity) {
		cout << "\nheap이 꽉 차있음.\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	heap[i] = k;

	//바꿀 노드가 부모 노드보다 key 값이 작은지만 검사해요
	while (i != 0 && heap[MinHeap::parent(i)] > heap[i]) {
		swap(heap[MinHeap::parent(i)], heap[i]);
		i = parent(i);
	}
}

void MinHeap::print_heap() {
	cout << "\nheap의 모든 노드 출력(인덱스 순서) :\n";
	for (int i = 0; i < heap_size; i++)
		cout << heap[i] << " ";
	cout << "\n";
}

int MinHeap::get_min() {
	cout << "\n최솟값 : " << heap[0] << "\n";
	return heap[0]; 
}

void MinHeap::pop_min() {
	if (heap_size <= 0) {
		cout << "\n힙이 비어있습니다.\n";
		return;
	}
	else if (heap_size == 1) {
		heap_size--;
		return;
	}

	//최소 힙에 두 개 이상의 노드가 들어있을 때 실행 가능
	heap[0] = heap[heap_size - 1];
	heap_size--;
	min_heapify(0);
}

void MinHeap::min_heapify(int i) {
	int lft = MinHeap::left(i);
	int rgt = MinHeap::right(i);
	int smallest = i;

	if (lft < heap_size && heap[smallest] > heap[lft])
		smallest = lft;
	if (rgt < heap_size && heap[smallest] > heap[rgt])
		smallest = rgt;
	if (smallest != i) {
		swap(heap[smallest], heap[i]);
		MinHeap::min_heapify(smallest);
	}
}