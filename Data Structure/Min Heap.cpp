/*
* Binary Heap�� �Ʒ��� ������ ������ ���� Ʈ����.
* 1. ���� ���� Ʈ�� (��� ���� ������ �Ʒ���, ���ʿ��� ���������� ä���� ����)
*   -> �� ���ǿ� ����, Binary Heap�� �迭�� �����ϱ� ����. (���� �׼��� ����)
* 2. Min Heap�̰ų� Max Heap�̾�� �Ѵ�.(root ����� key ���� ��� ��� �߿��� �ּҰų� �ִ�)
* 3. ��� sub tree�� ���� ������ ������.
�θ�� �ڽ� ����� ��� ���踸 �߿��ϰ�, ���� ���鰣�� ����� ����.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
	int* heap = NULL; //heap elements array�� ����ų ����
	int capacity = 0; //maximum size
	int heap_size = 0; //���� heap�� size

public :
	MinHeap(int capa);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

	void insert_key(int key); // �� ���� ����. O(log n)
	int get_min(); // �ּڰ� return. O(1)
	void pop_min(); // �ּڰ� ����. O(log n) -> heap�� �����ϱ� ���� root�� ������ �� heapify
	void min_heapify(int i); //i ��° ����� subtree�� heapify
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

	//���
	heap.print_heap();
	heap.get_min();
	
	//pop
	heap.pop_min();
	heap.pop_min();
	
	//���
	heap.print_heap();
	heap.get_min();

	//�� ����
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min();
	heap.pop_min(); // ���� ���

	return 0;
}

MinHeap::MinHeap(int capa) {
	heap = new int[capa];
	capacity = capa;
	heap_size = 0;
}

void MinHeap::insert_key(int k) {
	if (heap_size == capacity) {
		cout << "\nheap�� �� ������.\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	heap[i] = k;

	//�ٲ� ��尡 �θ� ��庸�� key ���� �������� �˻��ؿ�
	while (i != 0 && heap[MinHeap::parent(i)] > heap[i]) {
		swap(heap[MinHeap::parent(i)], heap[i]);
		i = parent(i);
	}
}

void MinHeap::print_heap() {
	cout << "\nheap�� ��� ��� ���(�ε��� ����) :\n";
	for (int i = 0; i < heap_size; i++)
		cout << heap[i] << " ";
	cout << "\n";
}

int MinHeap::get_min() {
	cout << "\n�ּڰ� : " << heap[0] << "\n";
	return heap[0]; 
}

void MinHeap::pop_min() {
	if (heap_size <= 0) {
		cout << "\n���� ����ֽ��ϴ�.\n";
		return;
	}
	else if (heap_size == 1) {
		heap_size--;
		return;
	}

	//�ּ� ���� �� �� �̻��� ��尡 ������� �� ���� ����
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