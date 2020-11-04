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
	
	cout << "입력받은 BST의 중위 순회 결과 : "; inorder_traversal(root); cout << "\n";
	/*
	        4
	    2        6
    1      3  5      7
	
	이 트리를 Min Heap(각 노드의 값들이 자신의 자식 노드들보다 값이 작아야함)으로 바꾸면

            1
		2        5
    3      4  6     7
	
	1. BST를 inorder traversal로 값을 받아뒀다가(오름차순)
	2. preorder traversal 방식으로 트리를 만들면 Min Heap
	*/

	queue <int> inorder;
	convert_BtoI(root, inorder); //BST to Inorder 
	make_MH(root, inorder); //Inorder 결과를 이용해 Preorder 방식으로 Min Heap 만들기

	cout << "Min Heap의 중위 순회 결과 : "; inorder_traversal(root); cout << "\n";
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