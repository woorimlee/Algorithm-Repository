#include <iostream>

using namespace std;

//���� ����Ʈ ����
//������ ���� �� ���� ���� ������ �ֽ��ϴ�.
//ù ��° : �ڱ� �ڽ��� ��
//�� ��° : �����ͷ� ���� ���� ������ ����ü�� �ּҰ��� ����Ŵ

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
	//���Ḯ��Ʈ�� ��忡�� -> ���� ��带 ����Ű�� -> ���� ��带 ����Ű�� �̷� �������� �̷���
	for (int i = 0; i < n; i++) {
		//�� ��带 ���� ��尡 �� ��带 ����Ű�ų�
		//�� ��尡 ���ο� ��尡 �ǰų�
		cin >> k;
		temp = new Node(k, head);
		head = temp;
		
	}


	return 0;
}