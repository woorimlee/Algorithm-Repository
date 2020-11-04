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

node* insert_BST(node* parent, int key); //key 값을 가진 노드 삽입하기
node* delete_BST(node* n, int key); //key 값을 가진 노드 지우기
node* find_min_node(node* n); //delete_BST에서 사용할 함수
void find_ceil_floor(node*& root); //ceil_BST, floor_BST, ceil_floor_IA 사용하는 함수
int ceil_BST(node* n, int key); //ceil(올림) 찾기
int floor_BST(node* n, int key); //floor(내림) 찾기
void ceil_floor_IA(node* n, int key, int& ceil, int& floor); //ceil, floor 찾기
void inorder_traversal(node* n); // BST 출력용 중위 순회

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

int ceil_BST(node* n, int key) {
	if (n == NULL) //못찾음
		return -1;
	if (n->key == key) //일치하는 것 찾음
		return n->key;
	else if (n->key < key) //오른쪽에 있음
		return ceil_BST(n->rgt, key);

	int temp = ceil_BST(n->lft, key);//왼쪽에 있거나 본인이 ceil 값이거나
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
