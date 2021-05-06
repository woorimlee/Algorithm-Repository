#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_ALPHABET = 26; // 문자로 알파벳 대문자만 입력됨

int charToNumber(char ch) { return ch - 'A'; }

struct TrieNode {
	TrieNode* children[MAX_ALPHABET];
	bool finish; // 종료 노드 확인용

	TrieNode() : finish(false) {
		fill(&children[0], &children[MAX_ALPHABET], nullptr);
	}

	~TrieNode() {
		for (int i = 0; i < MAX_ALPHABET; i++) {
			if(children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') 
			finish = true;
		else {
			int next = charToNumber(*key);
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == '\0')
			return this;
		int next = charToNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}
};

int main() {
	TrieNode* root = new TrieNode;

	const char* st = "BUSY";
	root->insert(st);
	st = "BUSH";
	root->insert(st);

	cout << root->find("BUSY")->finish << "\n";
	cout << root->find("BUSH")->finish << "\n";
	cout << root->find("BUS")->finish << "\n";
	return 0;
}