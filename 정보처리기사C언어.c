#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	//1-3 데이터 입 출력
	float i;
	//scanf("%4f", &i); //입력받을 때 . 포함 네 자리만 받음. 12.1234 -> 12.1
	printf("H\rI\n\bHi\n");
	printf("H\0\rI\n\bHi\n");
	printf("fads\fasdf");
	printf("test\n");

	printf("%f\n", 12.3456); // 소수점 이하 기본 여섯자리
	printf("%.8f\n", 12.3456789999); //소수점 이하 여섯자리까지 입력받고, 나머지는 0채워서 출력
	printf("%o\n", 250);
	printf("%e\n", 25.43);
	printf("%3s\n", "help me"); //출력 확보한 공간보다 출력할 값 자리가 더 크면 모두 출력
	printf("%.3s\n", "help me"); //출력할 자리 확보하고 그만큼만 출력
	printf("%8.6s\n", "help me");
	printf("%-8.6s\n", "help me");
	printf("%3d\n", 123456); //출력 확보한 공간보다 출력할 값 자리가 더 크면 모두 출력
	//d는 .이 없네
	printf("a=%8.2f b=%e c=%4f d=%f\n", 125.23f, 3141.592E-1, 3141.592f, 3.483E-2);


	return 0;
}