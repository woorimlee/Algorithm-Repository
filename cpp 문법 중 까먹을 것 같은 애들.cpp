//�������� ���� C++(����4��) 
//75��

#include <iostream>
#include <string>

using namespace std;

namespace part1 {
	//�⺻ int��, ���� ���� ���������� ������ 0���� ä����
	enum Cafe { SB, CB, E, TS, CafeCount}; //������ ������ ���� ���� 

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

	//����ġ�� ���� ���δٰ� �ϳ׿�?
	void switch_default_Test(Cafe cafe) {
		switch (cafe) {
			case Cafe::SB:
				cout << "��Ÿ����\n";
				break;
			//fallthrough ������, ��������� ���
			case CB:
			case TS:
				cout << "�߰�\n";
				break;
			default :
				//��ġ�ϴ°� �ϳ��� ������ default ����.
				//���� ���� ������� ��
				cout << "������\n";
				break;
			}

	}
}

int main() {
	part1::enum_Test();
	//������ for���� ������ ���
	for (part1::Cafe i = part1::Cafe::SB; i < part1::Cafe::CafeCount; i = (part1::Cafe)(i+1)) {
		part1::switch_default_Test(i);
	}
	return 0;
}
