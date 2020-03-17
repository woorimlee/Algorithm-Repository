#include <iostream>

using namespace std;

int N, K;
struct Node {
	int person;
	Node* next;
	Node(int i) : person{ i }, next{ nullptr } {};
};

void insertList(Node*& node, int i) {
	Node* temp = new Node(i);
	temp->next = node;
	node = temp;
	return;
}

void printList(Node* head) {
	while (head) {
		cout << head->person << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

void deleteNode(Node* curr) {
	Node* temp = curr->next;
	curr->person = temp->person;
	curr->next = temp->next;
	delete temp;
	return;
}

void solveJosephus(Node* node) {
	cout << "<";
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < K - 1; j++) {
			node = node->next;
		}
		if (i == N - 1) {
			cout << node->person;
		}
		else {
			cout << node->person << ", ";
		}
		deleteNode(node);
	}
	cout << ">";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	Node* head = nullptr;
	//단방향 연결 리스트 만들기
	for (int i = N; i >= 1; i--) {
		insertList(head, i);
	}
	//아래 함수를 사용해 list의 현재 상태를 출력해보세요.
	//printList(head);

	//리스트의 맨 끝은 nullptr을 가리키고 있는데, 맨 끝이 head를 가리키게 만들어서
	//원형 연결 리스트를 만든다.
	Node* temp = head;
	//nullptr이 다음 노드일 때까지 while문으로 탐색
	if (temp != nullptr)
		while (temp->next != nullptr)
			temp = temp->next;
	//nullptr을 가리키고 있던 노드의 next 값을 head를 가리키게 함.
	if (temp != nullptr)
		temp->next = head;
	
	//정답 출력
	solveJosephus(head);
	return 0;
}