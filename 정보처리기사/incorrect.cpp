#include "incorrect.h"
#include<windows.h>
#include <cstdio>
#pragma warning(disable:4996)

void chapter1::section3() {
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
	printf("%5.2f, %5.2f, %5.2f, %5.2f\n", 1.1, 1234567.123, 1234567.1, 1.12345);
	//_1.10, 1234567.12, 1234567.10, _1.12
	char inStr[] = "Welcome, C World!";
	printf("%.4s, %3.2s\n", inStr, inStr);
	//Welc, _We
}

void chapter1::section4() {
	//1-4 연산자
	printf("%d, %d, %d\n", 11 % -2, -11 % 2, -11 % -2);
	int a = 2, b = 4;
	printf("%d, %d\n", (++a + ++a), (++b + b++ + ++b + b++));
	a = 1, b = 0;
	printf("%d %d\n", !a, !b);
	a = 2, b = 3;
	int c = 4, d = 5;
	printf("%d\n", d *= 10 - b++);
	d = 5, b = 3;
	printf("%d\n", a %= c | b & d - b);
	a = 1, b = 2, c = 3, d = 4;
	printf("%d\n", a += ++a % b++ ? c * d : b / c);
	a = 5, b = 9;
	c = b % 5 < 5 ? 1 : 0;
	c = c | c << 3;
	c = a < 5 || c >= 10 ? c - a : c + a;
	printf("%d\n", c);
}

void chapter1::section6() {
	//1-6 반복문
	int a, b;
	a = 10, b = 0;
	while (a > 1) {
		a--;
		if (a % 3 == 1) {
			b += a;
		}
	}
	printf("%d\n", b);
}

void chapter1::section8() {
	//1-8 포인터
	int arr[4] = { 1, -3, 5, -7 };
	int* p = arr;
	printf("%d, ", ++ * p);
	printf("%d, ", *p++);
	printf("%d, ", *p);
	printf("%d\n", *++p);
	int a = 5, b, * c;
	c = &a;
	b = (*c)++;
	printf("%d %d\n", a, b);
	a = 31, c = &a;
	int* d = &b;
	*d = -- * c % 3 ? a + a : a * a;
	printf("%d\n", *d);

}

void chapter4::section40() {
	printf("통합 구현은 사용자의 요구사항을 해결하고, 새로운 서비스 창출을 위해 모듈 간의 연계와 통합을 의미한다.\n");
	printf("일반적인 통합 구현의 구성 요소 5가지를 쓰시오.");
	Sleep(10000);
	printf("정답 : 송신 시스템, 수신 시스템, 중계 시스템, 네트워크, 연계 데이터.\n");
}