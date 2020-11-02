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

//delete
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

	inorder_traversal(root);
	cout << "\n";

	return 0;
}