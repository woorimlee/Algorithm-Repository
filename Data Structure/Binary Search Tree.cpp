#include "BST.h"

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

	cout << "초기 BST : ";
	inorder_traversal(root);
	cout << "\n";
	
	/*BST
			 10
	   5                16
	3    7      12         18
		   9       13
		              14
	*/

	delete_BST(root, 14);
	cout << "14 지움 : ";
	inorder_traversal(root);
	cout << "\n";
	/*BST
	         10
	   5             16
	3    7      12      18
	       9       13
	*/

	find_ceil_floor(root);
	return 0;
}