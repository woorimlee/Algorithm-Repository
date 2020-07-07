#include "incorrect.h"
#include<windows.h>
#include <cstdio>
#include <conio.h>
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
	printf("일반적인 통합 구현의 구성 요소 5가지를 쓰시오.\n");
	//Sleep(10000);
	while (!kbhit());
	printf("  정답 : 송신 시스템, 수신 시스템, 중계 시스템, 네트워크, 연계 데이터.\n");
}

void chapter4::section42() {
	printf("연계 메커니즘은 데이터를 생성하여 전송하는 송신 체계와 수신하여 운영 DB에 반영하는 수신 체계로 구성된다.\n");
	printf("송신 시스템, 수신 시스템, 중계 시스템의 각 역할을 간략히 서술하시오.\n");
	while (!kbhit());
	printf("  송신 시스템 : 운영 DB로부터 인터페이스 테이블이나 파일 형식으로 연계할 데이터를 생성하여 송신한다.\n");
	printf("  수신 시스템 : 전송된 데이터를 수신 시스템에 맞는 형식으로 변환한 후 운영 DB에 반영한다.\n");
	printf("  중계 시스템 : 송 수신 시스템을 연계하며 데이터 오류 처리 등의 현황을 모니터링한다.\n");
}

void chapter4::section43() {
	printf("연계 메커니즘의 오류 처리 절차에 대해 서술하시오.\n");
	while (!kbhit());
	printf("  1. 연계 서버에서 제공하는 모니터로 장애 및 오류 현황 모니터링을 통해 원인 및 발생 현황 파악\n");
	printf("  2. 송, 수신 시스템 및 연계 시스템에서 기록한 오류 로그 테이블 또는 파일을 확인\n");
	printf("  3. 오류에 대해 적절한 조치를 취한 후 데이터 생성부터 송신 및 수신을 통한 DB 반영까지 재실행\n");
	printf("\n\t(추가 정보) 식별한 오류 내용은 오류 코드를 부여하고 오류 메세지를 정의한다.\n");
	printf("\t오류 코드와 메세지가 많으면 테이블 관리 방식을, 적으면 파일 관리 방식을 이용한다\n");
}