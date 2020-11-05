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
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> Map;

	for (int i = 0; i < clothes.size(); i++) {

		//auto iter = Map.find(clothes[i][1]);

		if (Map.find(clothes[i][1]) == Map.end()) {
			Map[clothes[i][1]] = 1;
		}
		else {
			Map[clothes[i][1]]++;
		}
	}

	for (auto it : Map) {
		cout << it.first << " " << it.second << "\n";
	}

	for (auto i = Map.begin(); i != Map.end(); i++) {
		int value = i->second;
		answer *= (value + 1);
	}

	return answer - 1;
}

int main() {
	vector<vector<string>> clothes = { {"ye", "head"}, {"bl", "eye"}, {"gr", "head"} };
	cout << solution(clothes);
	return 0;
}

/*
vector <int> min_heap;
int heap_capacity = 10;

int getMin(); // �ּڰ� return. O(1)
int popMin(); // �ּڰ� ����. O(lgn)
int decreaseKey(); //Ư�� ����� key ���� �����Ѵ�. O(1) ~ O(lgn)
void insertKey(int key); //�� ���� ����. O(lgn)
int deleteKey(); //Ư�� ��� ����. O(lgn)
void print_min_heap();

int main() {
	insertKey(5);
	insertKey(4);
	insertKey(9);
	insertKey(16);
	insertKey(2);
	insertKey(5);
	insertKey(1);
	
	print_min_heap();

	return 0;
}

void insertKey(int key) {
	if (min_heap.size() == heap_capacity) {
		return;
	}
	//�ϴ� ����ְ�,
	//�θ�� �ڽİ��� ũ�� �񱳸��ϸ� �ȴ�.
	min_heap.push_back(key);
	int child_idx = min_heap.size() - 1;
	int parent_idx = (child_idx - 1) / 2;
	
	while (parent_idx >= 0 && min_heap[child_idx] < min_heap[parent_idx]) {
		swap(min_heap[child_idx], min_heap[parent_idx]);
		child_idx = parent_idx;
		parent_idx = (child_idx - 1) / 2;
	}
}

void print_min_heap() {
	for (auto it : min_heap)
		cout << it << " ";
	cout << "\n";
}*/