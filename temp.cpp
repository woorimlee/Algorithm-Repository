#include <iostream>

using namespace std;

enum Cafe {SB, CB, E, TS};

int main() {
	Cafe c1;
	c1 = SB;
	int i = SB;
	if (c1 == SB)
		cout << c1 << " " << i << endl;
	c1 = (Cafe)3;
	if (c1 == TS)
		cout << c1 << endl;
	c1 = (Cafe)4;
	if(c1 == SB)
		cout << c1 << endl;
	return 0;
}