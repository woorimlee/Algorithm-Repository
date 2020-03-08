#include <iostream>
#include <string>

using namespace std;

namespace enumtest {
	//기본 int형, 값을 따로 지정해주지 않으면 0부터 채워짐
	enum Cafe { SB, CB, E, TS };

	void enum_Test() {
		Cafe c1;
		c1 = SB;
		int i = SB;
		if (c1 == SB)
			cout << c1 << " " << i << endl;
		c1 = (Cafe)3;
		if (c1 == TS)
			cout << c1 << endl;
		c1 = (Cafe)4;
		if (c1 == SB)
			cout << c1 << endl;
	}
}
/*
int main() {
	enumtest::enum_Test();
	return 0;
}*/