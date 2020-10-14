#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int C, N, P, L;

void curve(const string& seed, int gene, string& dc) {
	if (gene == 0) {
		dc += seed;
		return;
	}
	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X')
			curve("X+YF", gene - 1, dc);
		else if (seed[i] == 'Y')
			curve("FX-Y", gene - 1, dc);
		else
			dc += string(1, seed[i]);
	}
}

const int MAX = 1000000000 + 1;
int length[51];
void pre_calc() {
	length[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}

char nth_dragon_curve(const string& seed, int gene, int skip) {
	if (gene == 0) {
		return seed[skip];
	}

	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X' || seed[i] == 'Y') {
			if (skip >= length[gene])
				skip -= length[gene];
			else if (seed[i] == 'X')
				return nth_dragon_curve("X+YF", gene - 1, skip);
			else
				return nth_dragon_curve("FX-Y", gene - 1, skip);
		}
		else if (skip > 0)
			skip--;
		else
			return seed[i];
	}

	return '#';
}


int main() {
	cin >> C;
	pre_calc();
	while (C--) {
		cin >> N >> P >> L;
		//세대별 드래곤커브 만드는 완탐 
		/*string dc = "";
		curve("FX", N, dc);
		cout << dc << "\n";*/
		for (int i = P - 1; i < P - 1 + L; i++) {
			cout << nth_dragon_curve("FX", N, i);
		}cout << "\n";
	}
	return 0;
}