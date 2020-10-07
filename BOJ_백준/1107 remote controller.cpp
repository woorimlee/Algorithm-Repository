#include <iostream>

using namespace std;

//���� ä�� 100��.
//���峭 ��ư�� �Է� ������ bool �迭�� �ش� �ε����� true�� ����� ���峭 ���¶�� ���Ѵ�.
//N���� �ٷ� �̵� ��������, �Ұ��� �ϴٸ� ���� ����� ���� ���ؼ� �� �� +�� - ��ư�� ������ ���� ���Ѵ�.
//��� ����� ����(��� ä��) ��~ �м��ϴ� ���Ʈ ���� ������� Ǯ ���̴�.

//ex. N : 500,000, ���峭 ��ư�� 7�� 0�� �� ��������� �ϸ�, ������ ���ϴµ� �� ���� ����� �ִ�.
//1) 77,777�� �̵��ؼ� + ��ư�� ������
//2) 700,000�� �̵��ؼ� - ��ư�� ������.
//2)���� �ξ� ���� ����̴�. 
//���� �츮�� ��� ����� ��(ä��)�� ����� �� 500,000�� �Ѵ� ä�ε� �˻��ؾ� �Ѵ�.

//���峭 ��ư�� ���� bool �迭
bool button[10];

//���Ʈ ���� ������� ��� ����� ��(ä��)�� �˻��ϸ鼭 
//���� ��ư Ŭ������ �̵� ������ ä������ �Ǵ��ϴ� �Լ�.
int check_num(int temp) {
	if (temp == 0) {
		if (button[0]) {
			return 0;
		}
		else return 1;
	}
	int num_length = 0;
	while (temp) {
		if (button[temp%10]) {
			return 0;
		}
		temp /= 10;
		num_length++;
	}
	return num_length;
	//�̵� �Ұ����� ä���̸� 0�� return.
	//�̵� ������ ä���̸� ä���� ���� ���� return.
}

int main(void) {

	int N;//�̵��Ϸ��� ä��
	int M;//���峭 ��ư ����
	int temp;
	int current = 100;
	int answer = 0;
	int calculate_sum;
	cin >> N;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> temp;
		button[temp] = true;
	}

	//���� ��ġ�� ä���� 100�� ä�ο��� +�� -�� ������ �� ������ N ä�ο� ������ �� �ִ°�
	answer = abs(N - current);

	for (int i = 0; i < 1000000; i++) {
		temp = check_num(i);
		//check_num�� 0�� return�ϸ� �׳� ���� ����� ���� �Ѿ��
		//0�� �ƴ� ���� return�ϸ� 1)�̵��Ϸ��� ä�� - �̵� ������ ä��
		//2) 1)�� ��� ���� ä���� ���� ������ ���ؼ�
		//3) 100������ +�� - ��ư�� ������ �̵��� ������ ������ �Ǵ�.

		//ex) N = 109, ���峭 ���� ����.
		//0) answer = 109 - 100 = 9. 
		//1) check_num(109)�� 3�� return. ���� temp = 3
		//2) N - i = 109 - 109 = 0
		//3) calculate_sum = 0 + 3
		//4) answer > calculate_sum�� 9 > 3���� true�� ��Ȳ.
		//5) ���� answer�� 3.
		if (temp) {
			calculate_sum = abs(N - i) + temp;
			if (answer > calculate_sum) {
				answer = calculate_sum;
			}
		}
	}

	cout << answer << endl;
	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;

int check_num(int temp) {
	if (temp == 0) {
		if (binary_search(vec.begin(), vec.end(), 0)) {
			return 0;
		}
		else return 1;
	}
	int num_length = 0;
	while (temp>0) {
		if (binary_search(vec.begin(), vec.end(), temp%10)) {
			return 0;
		}
		temp /= 10;
		num_length++;
	}
	return num_length;
}

int main(void) {

	int N;//�̵��Ϸ��� ä��
	int M;//���峭 ��ư ����
	int temp;
	int current = 100;
	int answer = 0;
	int calculate_sum;
	cin >> N;
	cin >> M;


	for (int i = 0; i < M; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	answer = abs(N - current);

	for (int i = 0; i < 1000000; i++) {
		temp = check_num(i);
		if (temp > 0) {
			calculate_sum = abs(N - i) + temp;
			if (answer > calculate_sum) {
				answer = calculate_sum;
			}
		}
	}
	cout << answer << endl;
	return 0;
}*/