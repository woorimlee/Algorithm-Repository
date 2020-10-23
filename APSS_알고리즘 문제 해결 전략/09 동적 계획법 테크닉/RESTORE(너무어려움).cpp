#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_K = 17;
int C, K;
vector <string> words;
int overlap[MAX_K][MAX_K];
int cache[MAX_K][1 << MAX_K];

void init();
void preprocessing();
void overlapping();
void print();

int restore(int w, int used) {
	if (used == (1 << words.size()) - 1)
		return 0;

	int& ret = cache[w][used];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < words.size(); i++) {
		if ((used & (1 << i)) == 0) {
			int cand = overlap[w][i];
			ret = max(ret, cand + restore(i, used + (1 << i)));
		}
	}
	return ret;
}

string reconstruct(int last, int used) {
	if (used == (1 << words.size()) - 1)
		return "";
	for (int i = 0; i < words.size(); i++) {
		if (used & (1 << i))
			continue;
		int if_used = restore(i, used + (1 << i)) + overlap[last][i];
		if (if_used == restore(last, used))
			return (words[i].substr(overlap[last][i]) + reconstruct(i, used + (1 << i)));
	}
	return "*******oops*******";
}

int main() {
	cin >> C;
	while (C--) {
		init();
		print();
		cout << reconstruct(words.size(), 0) << "\n";
	}
	return 0;
}

void init() {
	cin >> K;
	words.clear();
	words.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> words[i];
	}
	fill(&overlap[0][0], &overlap[MAX_K - 1][MAX_K], 0);
	fill(&cache[0][0], &cache[MAX_K - 1][(1 << MAX_K)], -1);
	preprocessing();
	overlapping();
}
void preprocessing() {
	for (int i = 0; i < words.size(); i++)
		for (int j = 0; j < words.size(); j++) {
			if (i != j) {
				int fi = words[i].find(words[j]);
				int se = words[j].find(words[i]);
				if (fi != string::npos) { //npos == -1
					words.erase(words.begin() + j);
					i = 0; j = 0;
				}
				else if (se != string::npos) {
					words.erase(words.begin() + i);
					i = 0; j = 0;
				}
			}
		}
}
void overlapping() {
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			if (i != j) {
				int& ol = overlap[i][j];
				for (int k = min(words[i].size(), words[j].size()); k > 0; k--)
					if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
						ol = k;
						break;
					}
						
			}
		}
	}
}
void print() {
	for (auto it : words)
		cout << it << " ";
	cout << "\n";
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			cout << overlap[i][j] << " ";
		}cout << "\n";
	}
}