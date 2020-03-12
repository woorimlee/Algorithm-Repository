//�������� ���� C++(����4��) 
//80�� ����

#include <iostream>
#include <string>
#include <array>

using namespace std;

/*
���
Referential transparency : ������ ����. �Լ��� ��ȯ ���� �� �Է� �������� ����. 
	�޸������̼� ����� ����Ϸ��� ������ �����Լ��� �����Ǿ�� ��.
	ex) int cnt = 0;
		int count() {
			return counter++;
		}
	�̷� ���� ������ �����Լ��� �ƴ�. ������ ������ cnt ���� �޶���.
*/

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

	//�Լ����� ���������� __func__��� ���� ������ �ְ�, �Լ� �̸��� ���� ����
	void now_func_name() {
		cout << "���� �Լ� �̸� : " << __func__ << "\n";
		return;
	}

	//c++17���� <array> ����� std �������� �����ϴ� size�Լ� ��� ����
	void check_arr_size() {
		int arr[3];
		cout << "size�� �̿��� �迭 ũ�� Ȯ�� : " << size(arr) << "\n";
	}
	//array�� c��Ÿ�� �迭 ���� ��õ��
	//1. ���� �Լ�
	//2. ������ ���õ� �ε��� �Ǽ�
	void use_array() {
		array<int, 5> arr = { 5, 2, 1 };
		cout << "arr size : " << arr.size();
		cout << "\nfront : " << arr.front() << " back : " << arr.back() << "\n";
		array<int, 5> arr2 = { 0 };
		arr2.fill(-1);
		cout << "arr2 : ";
		for (auto it : arr2) {
			cout << it << " ";
		}
		cout << "\nswaped arr & arr2 : ";
		arr.swap(arr2);
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " " << arr2[i] << " ";
		}
		cout << "\n";
		return;
	}
	
}

int main() {
	part1::enum_Test();
	//������ for���� ������ ���
	for (part1::Cafe i = part1::Cafe::SB; i < part1::Cafe::CafeCount; i = (part1::Cafe)(i+1)) {
		part1::switch_default_Test(i);
	}
	part1::now_func_name();
	part1::check_arr_size();
	part1::use_array();
	return 0;
}

