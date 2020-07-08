#include "incorrect.h"
#include<windows.h>
#include <cstdio>
#include <conio.h>
#pragma warning(disable:4996)
int temp;

void chapter1::section3() {
	printf("3. 데이터 입 출력\n");
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
	printf("4. 연산자\n");
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
	printf("6. 반복문\n");
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
	printf("8. 포인터\n");
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
	printf("40. 연계 요구사항 분석\n");
	printf("통합 구현은 사용자의 요구사항을 해결하고, 새로운 서비스 창출을 위해 모듈 간의 연계와 통합을 의미한다.\n");
	printf("일반적인 통합 구현의 구성 요소 5가지를 쓰시오.\n");
	//Sleep(10000);
	while (!kbhit());
	temp = getch();
	printf("  정답 : 송신 시스템, 수신 시스템, 중계 시스템, 네트워크, 연계 데이터.\n");
}

void chapter4::section42() {
	printf("42. 연계 메커니즘 정의\n");
	printf("연계 메커니즘은 데이터를 생성하여 전송하는 송신 체계와 수신하여 운영 DB에 반영하는 수신 체계로 구성된다.\n");
	printf("송신 시스템, 수신 시스템, 중계 시스템의 각 역할을 간략히 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  송신 시스템 : 운영 DB로부터 인터페이스 테이블이나 파일 형식으로 연계할 데이터를 생성하여 송신한다.\n");
	printf("  수신 시스템 : 전송된 데이터를 수신 시스템에 맞는 형식으로 변환한 후 운영 DB에 반영한다.\n");
	printf("  중계 시스템 : 송 수신 시스템을 연계하며 데이터 오류 처리 등의 현황을 모니터링한다.\n");
	printf("\n연계 메커니즘의 구성 요소와 절차를 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  송신 시스템 연계 데이터 생성 -> 코드 매핑 및 데이터 변환 -> 인터페이스 테이블 또는 파일 생성 ->\n");
	printf("  연계 서버 또는 송신 어댑터를 이용한 전송 -> 연계 서버 또는 수신 어댑터를 이용한 수신 ->\n");
	printf("  인터페이스 테이블 또는 파일 수신 -> 코드 매핑 및 데이터 변환 -> 운영 DB에 데이터 반영.\n");
}

void chapter4::section43() {
	printf("43. 연계 장애 및 오류처리 구현\n");
	printf("연계 메커니즘의 오류 처리 절차에 대해 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  1. 연계 서버에서 제공하는 모니터로 장애 및 오류 현황 모니터링을 통해 원인 및 발생 현황 파악\n");
	printf("  2. 송, 수신 시스템 및 연계 시스템에서 기록한 오류 로그 테이블 또는 파일을 확인\n");
	printf("  3. 오류에 대해 적절한 조치를 취한 후 데이터 생성부터 송신 및 수신을 통한 DB 반영까지 재실행\n");
	printf("\n\t(추가 정보) 식별한 오류 내용은 오류 코드를 부여하고 오류 메세지를 정의한다.\n");
	printf("\t오류 코드와 메세지가 많으면 테이블 관리 방식을, 적으면 파일 관리 방식을 이용한다\n");
}

void chapter4::section45_46() {
	printf("45. 연계 모듈의 구현 환경, 46. XML\n");
	printf("EAI와 ESB의 개념을 간략히 서술하시오.\n");
	while (!kbhit());
	printf("  EAI : Enterprise Application Integration. 기업내 각종 어플리케이션, 플랫폼 간의 정보 연계 등을 가능하게 해주는 솔루션으로, 시스템 확장성을 높여준다.\n");
	printf("  구축 유형에는 point-to-point, hub & spoke, message bus, hybrid 방식이 있다.\n");
	printf("  ESB : Enterprise Service Bus. 기업내 각종 어플리케이션 연계 등 표준 기반의 인터페이스를 제공하는 솔루션. 서비스 중심의 통합을 지향한다.\n");
	printf("  어플리케이션간 결합도를 약하게 유지한다.\n");
	printf("\n웹 서비스의 개념을 간략히 서술하고, 세 가지 구성에 대해서 설명하시오.\n");
	temp = getch();
	while (!kbhit());
	temp = getch();
	printf("  Web Service : 네트워크의 정보를 표준화된 서비스 형태로 만들어 SOA(Service Oriented Architecture. 서비스 기반 아키텍처) 개념을 실현한다.\n");
	printf("  웹 서비스는 네트워크 상에서 XML 기반의 메세지를 교환하기 위한 SOAP와 검색 및 접근을 위한 UDDI, 웹 서비스에 대한 상세 정보를 XML 형식으로 구현한 WSDL로 구성된다.\n");
	printf("  SOAP(Simple Object Access Protocol) : HTTP, SMTP 등을 활용해 XML 기반 메세지를 교환하는 프로토콜.\n");
	printf("  WSDL(Web Services Description Language) : 웹 서비스명, 서비스 제공 위치, 프로토콜 등 서비스에 대한 상세 정보를 XML 형식으로 구현. UDDI의 기초로 인터넷에 웹 서비스를 제공하기 위해 사용되며, 클라이언트가 서버에서 어떤 조작이 가능한지 명시되어 있다.\n");
	printf("  UDDI(Universal Description, Discovery and Integration) : 인터넷에서 전 세계의 비즈니스 업체 목록에 자신의 정보를 등록하고자 WSDL을 등록하여 서비스와 서비스 제공자를 검색하고 접근하는 데 사용.\n");
	printf("\nXML의 특징을 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  XML(eXtensible Markup Language)은 웹 브라우저간 HTML 호환 문제, SGML의 복잡함을 해결하기 위해 개발된 다목적 마크업 언어다.\n");
	printf("  특징으로는\n  1. 사용자가 직접 문서의 태그를 정의하고 다른 사용자 태그 사용 가능.\n");
	printf("  2. 텍스트 형식 포맷으로 다양한 시스템에서 활용 가능.\n");
	printf("  3. 유니코드를 기반으로 다국어를 지원.\n");
	printf("  4. 트리 구조로 구성되어 있어 상위 태그가 여러 개의 하위 태그를 가질 수 있음.\n");
	printf("  5. 모든 태그는 종료 태그를 가지며, 시작 태그와 종료 태그의 Element(요소) 이름은 동일하다.\n");
}

void chapter5::section48() {
	printf("48. 개발 환경 구축\n");
	printf("웹 서버의 기능 여섯 가지를 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  HTTP(S) 지원 : HyperText Transfer Protocol (Secure). 하이퍼 텍스트 문서를 정송하기 위해 사용하는 프로토콜 지원\n");
	printf("  통신 기록 : Communication log. 클라이언트 처리 요청들을 로그 파일로 기록\n");
	printf("  정적 파일 관리 : Managing Static Files. HTML, CSS, 이미지 파일 등을 관리\n");
	printf("  대역폭 제한 : Bandwith Throttling. 네트워크 트래픽 포화 방지를 위해 응답속도 제한\n");
	printf("  가상 호스팅 : Virtual Hosting. 하나의 서버로 여러 개의 도메인 이름 연결\n");
	printf("  인증 : Authentication. 인증받은 사용자인지 확인\n\n");
}

void chapter5::section51() {
	printf("51. DMBS 접속\n");
	printf("(   )은 웹 서버와 웹 어플리케이션 서버로 구성되며, 서비스 규모가 작은 경우\n");
	printf("Web Server와 WAS를 통합하여 하나의 서버만으로 운용할 수 있다. \n");
	printf("사용자가 DBMS로부터 데이터를 얻기 위해서는 (   )을 통해야 한다.\n");
	printf("(   )에 들어갈 용어는?\n");
	while (!kbhit());
	temp = getch();
	printf("  웹 응용 시스템\n\n");
}

void chapter5::section52() {
	printf("52. 서버 개발\n");
	printf("서버 개발 프레임워크에 대해 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  웹 어플리케이션의 로직을 구현하여 WAS에 탑재할 서버 개발 시에 필요한 기능들(네트워크 설정, 요청 및 응답, 아키텍처 모델링)을\n");
	printf("  쉽게 처리할 수 있도록 클래스나 인터페이스를 제공하는 소프트웨어다.\n");
	printf("  보통 MVC(모델-뷰-컨트롤러) 패턴을 기반으로 개발되었다.\n\n");
	printf("프레임워크의 특징 네 가지와 각각에 대해서 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  1. 모듈화(Modularity) : 캡슐화를 통해 결합도는 약하게, 응집도는 높은 상태로 모듈화를 강화하고,\n");
	printf("  시스템의 수정 및 유지 관리등이 용이하게 한다.\n");
	printf("  2. 재사용성(Resuability) : 재사용이 가능한 모듈들을 제공\n");
	printf("  3. 확장성(Extensibility) : 인터페이스의 다형성(Polimorphism)을 통해 다양한 기능을 가진 앱 개발\n");
	printf("  4. 제어의 역행(Inversion of Control) : 개발자가 관리해야 할 객체들의 제어 권한을 프레임워크에 넘김\n");
	printf("  전체적으로 생산성을 향상시키기 위해 사용됨.\n\n");
}