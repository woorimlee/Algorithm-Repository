#include <iostream>
#include <string>

using namespace std;

//���� �� ���� �ϱ� ���� string �������� ���.
//¦�� ���� �˻��ϸ� ��.
//���� ���� �˻� ���? ���� ���� ã��
//��� ���ϸ�? ��Ʈ��ŷ

int N;
bool flag = false;

void make_seq(string seq) {
	if (flag == true)
		return;
	string str1, str2;
	//���� ���� �� ���� ��
	//�˻��� �� ������� ���� ���̰� 6�̸�
	//�� ���� ���� �߰��� ���� �������� �� �� ���� ����ϸ� ��.
	//ex) 1 2 1 3 1 2 �� �����������
	//    �� ���� 1 | 2 �˻�
	//    �� ���������� 1 3 | 1 2 �˻�
	//    �� ���������� 1 2 1 | 3 1 2 �˻�
	//str1�� �˻� ����� �� �κ�, str2�� �� �κ��̶� �ϸ� 
	//str1�� substr�� ù ��° parameter pos�� ���� ���� str2�� pos - (i+1)
	//���� ���ϰ� seq.length - 1�� seq_len���� ����
	int seq_len = seq.length() - 1;
	for (int i = 0; i < seq.length() / 2; i++) {
		str2 = seq.substr(seq_len - i, i+1);		
		str1 = seq.substr(((seq_len - i) - (i + 1)), i+1);	
		if (str1.compare(str2) == 0) 
			return; //str1�ϰ� str2�� ������ ����
	}
	//���� ������ ����� seq�� ���� ����

	if (seq.length() == N) {
		cout << seq;
		//�ϳ��� ã���� �Ǵϱ�... �����Ű��.
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++)
		make_seq(seq + (char)(i + '0'));

	return;
}

int main(void) {
	cin >> N;

	//���� ���̰� 1�� ��, 2�� ��, ... n/2�� ������ �˻�
	//�� ���� 1�� �������� ����
	make_seq("1");

	return 0;
}