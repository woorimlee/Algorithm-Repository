#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int S = 0;

//int�� 0�϶�, 4 byte�� ������ ���� ����.
//00000000 00000000 00000000 00000000
//(2������ ǥ���� ��Ȳ)
//�ڿ������� 20��Ʈ�� 1~20������ ���� ���ҿ� �������Ѽ�
//00000000 00000000 00000000 00000001�̸� ���տ� 1�� �ְ�,
//00000000 00000000 00000000 00001001�̸� ���տ� 1�� 4�� �ִٴ� ������
//����� ����.
//�׸� ���� add, remove, check ���� �Լ����� 
//��Ʈ ������ ����ϴ� ��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int m, n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		//string�� == "���ڿ�"�� �� �˻��� �� ����
		if (str == "add")
		{
			cin >> n; 
			S = (1 << n - 1) | S;
		}
		else if (str == "remove")
		{
			cin >> n;
			S = ~(1 << n - 1) & S;
		}
		else if (str == "check")
		{
			cin >> n;
			//������ �켱���� ����
			if (((1 << n - 1) & S) == 0) cout << "0" << "\n";
			else cout << "1" << "\n";
		}
		else if (str == "toggle")
		{
			cin >> n;
			S = S ^ (1 << n - 1);
			//S ^= (1 << x-1);
		}
		else if (str == "all") {
			//~0 == -1 == ��� ��Ʈ�� 1
			S = ~0;
		}
		else if (str == "empty") 
			S = 0;
	}
	return 0;
}