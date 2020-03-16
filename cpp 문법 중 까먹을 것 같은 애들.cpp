//�������� ���� C++(����4��) 
//87�� ����

#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <initializer_list>

using namespace std;

/*
���
1. Referential transparency : ������ ����. �Լ��� ��ȯ ���� �� �Է� �������� ����. 
	�޸������̼� ����� ����Ϸ��� ������ �����Լ��� �����Ǿ�� ��.
	ex) int cnt = 0;
		int count() {
			return counter++;
		}
	�̷� ���� ������ �����Լ��� �ƴ�. ������ ������ cnt ���� �޶���.

2. Structured binding : ������ ���ε�. part1 �̸� �������� �ڼ��� ����
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

	//structured binding : ������ ���ε�
	void use_sb() {
		//���� ���� ������ ������ �� �迭, ����ü, ��� ������ �ʱ�ȭ ����.
		array<int, 3> arr = { 11, 22, 33 };
		auto [x, y, z] = arr;
		cout << x << " " << y << " " << z << "\n";
		struct Point { double mx, my, mz; };
		Point point;
		point.mx = 1.0; point.my = 2.0; point.mz = 3.0;
		auto [x2, y2, z2] = point;
		printf("%.1lf %.1lf %.1lf\n", x2, y2, z2);
		return;
	}
	
	//�ݺ��ڸ� �����ϴ�(begin()�� end()�� �����ϴ�) ��� �����̳ʿ� ���� ������
	//���� ��� for��
	void use_range_based_for_loop() {
		array<int, 4> arr = { 1, 2, 3, 4 };
		for (int i : arr) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	//initializer_list�� �̿��ϸ� ���� �μ��� �޴� �Լ��� ���� �ۼ��� �� �ִ�.
	//<initializer_list> ����� �����Ѵ�.
	void use_ini_list(initializer_list<int> lst) {
		int total = 0;
		for (int i : lst) {
			total += i;
		}
		cout << total << "\n";
		return;
	}
}

int main() {
	//part1::enum_Test();
	//������ for���� ������ ���
	/*
	for (part1::Cafe i = part1::Cafe::SB; i < part1::Cafe::CafeCount; i = (part1::Cafe)(i+1)) {
		part1::switch_default_Test(i);
	}
	*/
	//part1::now_func_name();
	//part1::check_arr_size();
	//part1::use_array();
	//part1::use_sb();
	//part1::use_range_based_for_loop();
	//part1::use_ini_list({1, 2, 3, 4, 5});
	return 0;
}

