#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void josephus(int N, int K) {

	list<int> people;
	for (int i = 1; i <= N; i++)
		people.push_back(i);
	list<int>::iterator suicide = people.begin();
	while (N > 2) {
		suicide = people.erase(suicide);
		N--;
		if (suicide == people.end())
			suicide = people.begin();
		for (int i = 0; i < K - 1; i++) {
			suicide++;
			if (suicide == people.end())
				suicide = people.begin();
		}
	}
	for (int p : people)
		cout << p << " ";
	cout << "\n";
}

int main() {
	int C, N, K;
	cin >> C;
	while (C--) {
		cin >> N >> K;
		josephus(N, K);
	}
	return 0;
}