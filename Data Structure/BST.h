#include <iostream>
#include <vector>
#include <algorithm>
#pragma once

using namespace std;

struct NODE {
	int key;
	NODE* lft, * rgt;
	NODE(int k, NODE* l, NODE* r) : key{ k }, lft{ l }, rgt{ r } {}
};
typedef struct NODE node;

node* insert_BST(node* parent, int key); //key ���� ���� ��� �����ϱ�
node* delete_BST(node* n, int key); //key ���� ���� ��� �����
node* find_min_node(node* n); //delete_BST���� ����� �Լ�
void find_ceil_floor(node*& root); //ceil_BST, floor_BST, ceil_floor_IA ����ϴ� �Լ�
int ceil_BST(node* n, int key); //ceil(�ø�) ã��
int floor_BST(node* n, int key); //floor(����) ã��
void ceil_floor_IA(node* n, int key, int& ceil, int& floor); //ceil, floor ã��
void inorder_traversal(node* n); // BST ��¿� ���� ��ȸ

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

node* find_min_node(node* n) {//delete_BST�� ���� �Լ�
	if (n->lft == NULL) {
		return n;
	}
	return find_min_node(n->lft);
}

node* delete_BST(node* n, int key) {
	if (n == NULL)
		return NULL;

	if (n->key > key)
		n->lft = delete_BST(n->lft, key);
	else if (n->key < key)
		n->rgt = delete_BST(n->rgt, key);
	else if (n->key == key) {
		//�ڽ� ��尡 ���ų� �ϳ��� ���
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

		//�� �ʿ� �ڽ��� �ִ� ���, ������ sub tree �� ���� ���� �� ã��
		node* temp = find_min_node(n->rgt);
		n->key = temp->key;
		n->rgt = delete_BST(n->rgt, temp->key);
	}
	return n;
}

int ceil_BST(node* n, int key) {
	if (n == NULL) //��ã��
		return -1;
	if (n->key == key) //��ġ�ϴ� �� ã��
		return n->key;
	else if (n->key < key) //�����ʿ� ����
		return ceil_BST(n->rgt, key);

	int temp = ceil_BST(n->lft, key);//���ʿ� �ְų� ������ ceil ���̰ų�
	return (temp >= key) ? temp : n->key;
}

int floor_BST(node* n, int key) {
	if (n == NULL)
		return -1;
	if (n->key == key)
		return n->key;
	else if (n->key > key)
		return floor_BST(n->lft, key);

	int temp = floor_BST(n->rgt, key);
	return (temp <= key && temp != -1) ? temp : n->key;
}

void ceil_floor_IA(node* n, int key, int& ceil, int& floor) { //IA : Iterative Approach
	while (n) {
		if (n->key == key) {
			ceil = key;
			floor = key;
			return;
		}
		if (n->key > key) {
			ceil = n->key;
			n = n->lft;
		}
		else if (n->key < key) {
			floor = n->key;
			n = n->rgt;
		}
	}
}

void find_ceil_floor(node*& root) {
	//1. recursive approach
	for (int i = 2; i <= 19; i++) {
		cout << "key : " << i << ", floor : " << floor_BST(root, i) << ", ceil : " << ceil_BST(root, i) << "\n";
	}
	//2. iterative approach
	for (int i = 2; i <= 19; i++) {
		int ceil = -1;
		int floor = -1;
		ceil_floor_IA(root, i, ceil, floor);
		cout << "\nkey : " << i << ", floor : " << floor << ", ceil : " << ceil;
	}
}
