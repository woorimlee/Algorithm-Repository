#include <queue>
#include "BST.h"

using namespace std;

void convert_BtoI(node * n, queue <int> & inorder);
void make_MH(node * n, queue <int> & inorder);

int main() {
	//complete binary tree
	node* root = NULL;
	root = insert_BST(root, 4);
	insert_BST(root, 2);
	insert_BST(root, 6);
	insert_BST(root, 1);
	insert_BST(root, 3);
	insert_BST(root, 5);
	insert_BST(root, 7);
	
	cout << "�Է¹��� BST�� ���� ��ȸ ��� : "; inorder_traversal(root); cout << "\n";
	/*
	        4
	    2        6
    1      3  5      7
	
	�� Ʈ���� Min Heap(�� ����� ������ �ڽ��� �ڽ� ���麸�� ���� �۾ƾ���)���� �ٲٸ�

            1
		2        5
    3      4  6     7
	
	1. BST�� inorder traversal�� ���� �޾Ƶ״ٰ�(��������)
	2. preorder traversal ������� Ʈ���� ����� Min Heap
	*/

	queue <int> inorder;
	convert_BtoI(root, inorder); //BST to Inorder 
	make_MH(root, inorder); //Inorder ����� �̿��� Preorder ������� Min Heap �����

	cout << "Min Heap�� ���� ��ȸ ��� : "; inorder_traversal(root); cout << "\n";
	return 0;
}

void convert_BtoI(node* n, queue <int>& inorder) {
	if (n == NULL)
		return;

	convert_BtoI(n->lft, inorder);
	inorder.push(n->key);
	convert_BtoI(n->rgt, inorder);
}

void make_MH(node* n, queue <int>& inorder) {
	if (n == NULL)
		return;

	n->key = inorder.front();
	inorder.pop();
	make_MH(n->lft, inorder);
	make_MH(n->rgt, inorder);
}