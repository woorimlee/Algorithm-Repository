#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, kbs1_idx, kbs2_idx;
string str;

void button();

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		//string ���´� == "���ڿ�"�� �˻� ����
		if (str == "KBS1") {
			kbs1_idx = i;
		}
		else if (str == "KBS2") {
			kbs2_idx = i;
		}
	}
	//KBS1�� ������ ���� �� ���� �ø��ǵ�,
	//KBS1�ؿ� KBS2�� ������ ������ ������,
	//KBS2�� KBS1���� ���� �ִٸ� KBS2�� �� ĭ ������ �з����� ������
	//KBS2�� �ε��� ���� 1 ������Ų��
	if (kbs1_idx > kbs2_idx)
		kbs2_idx++;
	button();
	return 0;
}

void button() {
	int i = 0;
	//KBS1 ���ö����� ���� ����Ű�� ä�� ������
	for (i = 0; i < kbs1_idx; i++) cout << '1';
	//KBS1ä�� �� ó������ �ø���
	for (i = 0; i < kbs1_idx; i++) cout << '4';
	if (kbs2_idx == 0)
		return;
	//KBS2 ���ö����� ���� ����Ű�� ä�� ������
	for (i = 0; i < kbs2_idx; i++) cout << '1';
	//KBS2 ä�� �ι�°�� �ø���
	for (i = 1; i < kbs2_idx; i++) cout << '4';
	return;
}

