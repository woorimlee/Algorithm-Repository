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
	//�ܹ��� ���� ����Ʈ �����
	for (int i = N; i >= 1; i--) {
		insertList(head, i);
	}
	//�Ʒ� �Լ��� ����� list�� ���� ���¸� ����غ�����.
	//printList(head);

	//����Ʈ�� �� ���� nullptr�� ����Ű�� �ִµ�, �� ���� head�� ����Ű�� ����
	//���� ���� ����Ʈ�� �����.
	Node* temp = head;
	//nullptr�� ���� ����� ������ while������ Ž��
	if (temp != nullptr)
		while (temp->next != nullptr)
			temp = temp->next;
	//nullptr�� ����Ű�� �ִ� ����� next ���� head�� ����Ű�� ��.
	if (temp != nullptr)
		temp->next = head;
	
	//���� ���
	solveJosephus(head);
	return 0;
}