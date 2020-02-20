#include <iostream>

using namespace std;

//연결 리스트 구현
//각각의 노드는 두 가지 값을 가지고 있습니다.
//첫 번째 : 자기 자신의 값
//두 번째 : 포인터로 다음 값을 저장한 구조체의 주소값을 가리킴

struct Node {
	int data = 0;
	Node* next = nullptr;
	Node(int num, Node* tnext) : data{ num }, next{ tnext } {};
};

int main(void) {
	Node* head = nullptr;

	int n, k;
	cin >> n;
	Node* temp = nullptr;
	//연결리스트는 헤드에서 -> 다음 노드를 가리키고 -> 다음 노드를 가리키고 이런 형식으로 이뤄짐
	for (int i = 0; i < n; i++) {
		//새 노드를 만들어서 헤드가 그 노드를 가리키거나
		//새 노드가 새로운 헤드가 되거나
		cin >> k;
		temp = new Node(k, head);
		head = temp;
		
	}


	return 0;
}