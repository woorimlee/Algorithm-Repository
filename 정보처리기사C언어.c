#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	//1-3 ������ �� ���
	float i;
	//scanf("%4f", &i); //�Է¹��� �� . ���� �� �ڸ��� ����. 12.1234 -> 12.1
	printf("H\rI\n\bHi\n");
	printf("H\0\rI\n\bHi\n");
	printf("fads\fasdf");
	printf("test\n");

	printf("%f\n", 12.3456); // �Ҽ��� ���� �⺻ �����ڸ�
	printf("%.8f\n", 12.3456789999); //�Ҽ��� ���� �����ڸ����� �Է¹ް�, �������� 0ä���� ���
	printf("%o\n", 250);
	printf("%e\n", 25.43);
	printf("%3s\n", "help me"); //��� Ȯ���� �������� ����� �� �ڸ��� �� ũ�� ��� ���
	printf("%.3s\n", "help me"); //����� �ڸ� Ȯ���ϰ� �׸�ŭ�� ���
	printf("%8.6s\n", "help me");
	printf("%-8.6s\n", "help me");
	printf("%3d\n", 123456); //��� Ȯ���� �������� ����� �� �ڸ��� �� ũ�� ��� ���
	//d�� .�� ����
	printf("a=%8.2f b=%e c=%4f d=%f\n", 125.23f, 3141.592E-1, 3141.592f, 3.483E-2);


	return 0;
}