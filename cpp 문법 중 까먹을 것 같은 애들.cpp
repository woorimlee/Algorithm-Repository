//전문가를 위한 C++(개정4판) 
//75쪽

#include <iostream>
#include <string>

using namespace std;

namespace part1 {
	//기본 int형, 값을 따로 지정해주지 않으면 0부터 채워짐
	enum Cafe { SB, CB, E, TS, CafeCount}; //열거형 개수를 세기 위해 

	void enum_Test() {
		Cafe c1;
		c1 = SB;
		int i = SB;
		if (c1 == SB)
			cout << c1 << " " << i << endl;
		c1 = (Cafe)3;
		if (c1 == TS)
			cout << c1 << endl;
		c1 = (Cafe)5;
		if (c1 == SB)
			cout << c1 << endl;
	}

	//스위치도 자주 쓰인다고 하네요?
	void switch_default_Test(Cafe cafe) {
		switch (cafe) {
			case Cafe::SB:
				cout << "스타벅스\n";
				break;
			//fallthrough 폴스루, 흘려보내기 방식
			case CB:
			case TS:
				cout << "중고가\n";
				break;
			default :
				//일치하는게 하나도 없으면 default 실행.
				//보통 에러 잡기위해 씀
				cout << "중저가\n";
				break;
			}

	}
}

int main() {
	part1::enum_Test();
	//열거형 for구문 돌리는 방법
	for (part1::Cafe i = part1::Cafe::SB; i < part1::Cafe::CafeCount; i = (part1::Cafe)(i+1)) {
		part1::switch_default_Test(i);
	}
	return 0;
}
