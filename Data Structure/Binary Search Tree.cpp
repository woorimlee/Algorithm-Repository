#include <iostream>

using namespace std;

struct NODE{
	int key;
	NODE* lft, * rgt;
	NODE(int k, NODE* l, NODE* r) : key{ k }, lft{ l }, rgt{ r } {}
};
typedef struct NODE node;

node* insert_BST(node* parent, int key) {
	if (parent == NULL) 
		return new node(key, NULL, NULL);

	if (parent->key > key)
		parent->lft = insert_BST(parent->lft, key);
	else if (parent->key < key)
		parent->rgt = insert_BST(parent->rgt, key);

	return parent;
}

void inorder_traversal(node* n) {
	if (n == NULL)
		return;
	inorder_traversal(n->lft);
	cout << n->key << " ";
	inorder_traversal(n->rgt);
}


node* find_min_node(node* n) {//delete_BST에 쓰일 함수
	if (n->lft == NULL) {
		return n;
	}
	return find_min_node(n->lft);
}
//delete
node* delete_BST(node* n, int key) {
	if (n == NULL)
		return NULL;

	if (n->key > key)
		n->lft = delete_BST(n->lft, key);
	else if (n->key < key)
		n->rgt = delete_BST(n->rgt, key);
	else if (n->key == key) {
		//자식 노드가 없거나 하나인 경우
		if (n->lft == NULL) {
			node* temp = n->rgt;
			free(n);
			return temp;
		}
		else if (n->rgt == NULL) {
			node* temp = n->lft;
			free(n);
			return temp;
		}

		//양 쪽에 자식이 있는 경우, 오른쪽 sub tree 중 가장 작은 값 찾음
		node* temp = find_min_node(n->rgt);
		n->key = temp->key;
		n->rgt = delete_BST(n->rgt, temp->key);
	}
	return n;
}

//floor 내림
//ceil 올림

int main() {

	node * root = NULL;
	root = insert_BST(root, 10);
	insert_BST(root, 5);
	insert_BST(root, 7);
	insert_BST(root, 16);
	insert_BST(root, 12);
	insert_BST(root, 3);
	insert_BST(root, 9);
	insert_BST(root, 13);
	insert_BST(root, 14);
	insert_BST(root, 18);

	inorder_traversal(root);
	cout << "\n";

	delete_BST(root, 9);
	inorder_traversal(root);
	cout << "\n";
	return 0;
}