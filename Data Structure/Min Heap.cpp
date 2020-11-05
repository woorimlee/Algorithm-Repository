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

int getMin(); // 최솟값 return. O(1)
int popMin(); // 최솟값 제거. O(lgn)
int decreaseKey(); //특정 노드의 key 값을 수정한다. O(1) ~ O(lgn)
void insertKey(int key); //새 값을 삽입. O(lgn)
int deleteKey(); //특정 노드 삭제. O(lgn)
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
	//일단 집어넣고,
	//부모와 자식간의 크기 비교만하면 된다.
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