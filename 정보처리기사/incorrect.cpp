#include "incorrect.h"

using namespace std;
#pragma warning(disable:4996)
int temp;

void kh() {
	while (!kbhit());
	temp = getch();
}

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

void chapter1::cp(const std::string &s) {
	cout << s;
	double p = 1;
	for (int i = 0; i < 5; i++, p *= i);
	printf("%.3f\n\n", p);
	cout << "1. 다음은 선언형 언어에 대한 설명이다. 괄호 ( 1 ), ( 2 )에 들어갈 것은?\n";
	cout << "선언형 프로그래밍 언어는 ( 1 )와, ( 2 )가 있다. ( 1 ) 의 대표적 언어는 LISP. 병렬 처리에 유리, 재귀를 통한 수학적 함수 문제 해결.\n";
	cout << "( 2 )의 대표적 언어는 PROLOG. 기초 논리학에 기반을 두고 논리 문장을 이용해 프로그램을 표현.\n";
	kh();
	cout << "  1. ( 1 ) : 함수형 언어,  ( 2 ) : 논리형 언어\n\n";
}

void chapter2::cp(const std::string& s) {
	cout << s;
	cout << "1. 다음의 설명과 가장 부합하는 용어는?\n";
	cout << ": 소프트웨어가 어떤 문제를 해결하기 위해 제공하는 서비스에 대한 설명과, 운영에 필요한 제약조건을 말한다.\n";
	cout << "소프트웨어 개발이나 유지 보수 과정에서 필요한 기준과 근거를 제공한다.\n";
	cout << "개발하려는 SW 전반적인 내용을 확인할 수 있게 하므로, 개발에 참여하려는 이해관계자들의 의사소통을 원활하게 해준다.\n";
	cout << "2. 요구사항 분석 기법 중 구문(Syntax), 의미(Semantics)를 갖는 언어를 이용해 요구사항을 수학적 기호로 표현한 후 분석하는 기법은?\n";
	cout << "3. 요구사항 분석 기법 중 현실 세계의 상황을 단순화하여 개체들간의 관계 및 종속성을 표현하는 기법이다.\n보통 UML 기법을 사용한다.\n";
	cout << "4. ( 1 )는 사용자가 실제로 사용될 환경에서 요구사항들이 모두 충족되는지 사용자가 직접 테스트하는 과정이다.\n";
	cout << "테스트에 문제가 없으면 사용자는 소프트웨어를 인수하게 된다.\n";
	cout << "종류로는 ( 2 ), ( 3 ), ( 4 ), ( 5 ), ( 6 ), ( 7 )이 있다.\n";
	cout << "( 2 ) : 사용자가 시스템 사용의 적절성 여부를 확인한다.\n";
	cout << "( 3 ) : 시스템 관리자가 시스템 인수 시 수행하는 테스트 기법으로, 백업, 정기점검, 복원 등을 한다.\n";
	cout << "( 4 ) : 계약상의 인수, 검수 조건을 준수하는지 확인한다.\n";
	cout << "( 5 ) : 소프트웨어가 정부 지침, 법규, 규정 등을 맞췄는지 확인한다.\n";
	cout << "( 6 ) : 사용자가 개발자 앞에서 통제된 환경에서 오류와 사용상 문제점을 함께 확인하는 테스트\n";
	cout << "( 7 ) : 선정된 최종 사용자가 여러 명의 사용자 앞에서 행하는 테스트.\n";
	kh();
	cout << "  1. 요구사항\n\n";
	cout << "  2. 정형 분석\n\n";
	cout << "  3. 개념 모델링\n\n";
	cout << "  4. ( 1 ) : 인수 테스트,  ( 2 ) : 사용자 인수 테스트,  ( 3 ) : 운영상 인수 테스트,  ( 4 ) : 계약 인수 테스트\n";
	cout << "     ( 5 ) : 규정 인수 테스트,  ( 6 ) :알파 테스트,  ( 7 ) : 베타 테스트\n\n";

	cout << "5. UML의 개념에 대해 간단히 서술하시오.\n";
	cout << "6. 다이어그램은 사물과 관계를 도형으로 표현한 것이다. 정적 모델링에서는 주로 ( 1 )을, 동적 모델링에서는 주로 ( 2 )을 사용한다.\n";
	cout << "( 1 )의 종류로는 클래스, 객체, 컴포넌트, 배치, 복합체 구조, 패키지 다이어그램이 있다. 이 중 ( 3 ), ( 4 )는 구현 단계에서 사용된다.\n";
	cout << "( 2 )의 종류로는 유스케이스, 활동, 시퀀스, 커뮤니케이션, 상태, 상호작용 개요, 타이밍 다이어그램이 있다.\n";
	cout << "( 5 )은 기능 모델링으로, 사용자 관점에서 기능 및 요구를 분석하고 사용자와 사용 사례로 구성된다.\n";
	cout << "( 6 )은 기능 모델링으로, 시스템이 어떤 기능을 수행하는지 유스케이스의 처리 흐름을 순서에 따라 표현한다.\n";
	cout << "( 7 )은 동적 모델링으로, 시스템 내부 요소가 시간의 흐름에 따라 변화하는 과정 및 메시지, 오퍼레이션을 통한 상호작용을 표현한다.\n";
	cout << "( 8 )은 동적 모델링으로, 초기에는 협업 다이어그램으로 불렸다. 동작에 참여하는 요소(객체)간 주고받는 메시지를 표현하는 동시에 링크로 관계까지 표현한다.\n";
	cout << "( 9 )은 동적 모델링으로, 상태, 이벤트, 상태 전환 등으로 구성되며 어떤 이벤트에 의한 객체들의 상태 변화를 표현한다.\n";
	cout << "7. Use Case Diagram의 구성 요소로는 ( 1 ), ( 2 ), ( 3 ), ( 4 )가 있다.\n";
	cout << "( 1 )은 기능과 외부 액터를 구분하기 위한 것이다. ( 2 )는 시스템과 상호작용을 하는 모든 요소를 말한다. 이름은 구체적이면 안된다.\n";
	cout << "( 2 )에는 ( 5 ), ( 6 )이 있다. ( 5 )는 시스템을 사용하는 사람을, ( 6 )은 ( 5 )의 목적 달성을 위해 시스템에 서비스를 제공하는 외부 시스템을 말한다. <<Actor>>라고 표현한다.\n";
	cout << "( 3 )은 사용자가 보는 관점에서 시스템이 액터에게 제공하는 서비스 또는 기능을 말하고, 타원으로 표현한다.\n";
	cout << "( 4 )는 액터와 유스케이스, 유스케이스와 유스케이스 사이에 나타날 수 있으며, 포함, 확장, 일반화 세 종류가 있다.\n";
	cout << "( 7 )관계는 두 개 이상의 유스케이스에 공통적으로 적용되는 기능을 별도로 분리하고, - - - > 연결한후 <<include>>라고 표현한다.\n";
	cout << "( 8 )관계는 유스케이스가 특정 조건에 부합되면 기능이 확장될 때, - - - > 연결한 후 <<extends>>라고 표현한다.\n";
	cout << "( 9 )관계는 유사한 액터나 유스케이스를 하나의 그룹으로 묶을 때, 하위는 상위를 상속받을 때, ㅡ|> 로 연결한다.\n";
	cout << "8. Activity Diagram은 하나의 유스케이스 안 혹은 유스케이스 사이에 발생하는 흐름을 명시하는 것이다.\n";
	cout << "( 1 ) ,( 2 ) : ( 1 )은 더 이상 분해할 수 없는 단일 작업으로, ( 2 )는 몇 개의 ( 1 )으로 분리될 수 있는 작업니다. 둥근 사각형으로 표현한다.\n";
	cout << "( 3 )은 검은색 원으로 표현하며 액션이나 액티비티가 시작됨을 말한다. 하나만 존재한다.\n";
	cout << "( 4 )는 액티비티 안의 모든 흐름이 종료됨을 의미하며, 여러 개 있을 수 있고, 검은색 원을 포함한 원으로 표현한다.\n";
	cout << "( 5 )는 마름모로 표현하며 제어의 흐름이 분리됨을 표현한다. 들어오는 거 하나 나가는거 여러 개\n";
	cout << "( 6 )는 마름모로 표현하며 여러 경로의 흐름이 하나로 합쳐짐을 표현한다. ( 5 )와 반대.\n";
	cout << "( 7 )은 액티비티의 흐름이 분리되어 수행됨을 표현하고, 굵은 가로선으로 표현한다. 들어오는 액티비티는 하나, 나가는 흐름은 여러 개.\n";
	cout << "( 8 )은 액티비티의 흐름이 합쳐짐을 의미. 굵은 가로선에 ( 7 )과 반대.\n";
	cout << "( 9 )는 액티비티 수행을 담당하는 주체를 구분하며, 실선을 그어 구분한다.\n";
	kh();
	cout << "  5. 사용자와 개발자간의 의사소통을 원활히 하기 위해 공통된 표현법으로 개발할 대상물을 사물, 관계, 다이어그램으로 정의하는 것.\n";
	cout << "  Rumbaugh, Booch, Jacobson 등이 개발한 객체지향 모델링 언어다.\n\n";
	cout << "  6. ( 1 ) 구조 다이어그램,  ( 2 ) : 행위 다이어그램,  ( 3 ) : 컴포넌트,  ( 4 ) : 배치\n";
	cout << "  ( 5 ) : 유스케이스 다이어그램,  ( 6 ) : 활동 다이어그램,  ( 7 ) : 시퀀스 다이어그램,  ( 8 ) : 커뮤니케이션 다이어그램,  ( 9 ) :상태 다이어그램\n\n";
	cout << "  7. ( 1 ) : 시스템/시스템 범위,  ( 2 ) : 액터,  ( 3 ) : 유스케이스,  ( 4 ) : 관계,  ( 5 ) : 주액터,  ( 6 ) : 부액터\n";
	cout << "  ( 7 ) : 포함 관계,  ( 8 ) : 확장 관계,  ( 9 ) : 일반화 관계\n\n";
	cout << "  8. ( 1 ) : 액션,  ( 2 ) : 액티비티,  ( 3 ) : 시작 노드,  ( 4 ) : 종료 노드,  ( 5 ) : 조건(판단) 노드\n\n";
	cout << "  ( 6 ) : 병합 노드,  ( 7 ) : 포크 노드,  ( 8 ) : 조인 노드,  ( 9 ) : 스윔 레인\n\n";

	cout << "9. Class Diagram은 객체들을 구조적인 관점에서 추상화하여 표현하는 정적 모델링의 대표적인 예다.\n";
	cout << "시스템 구성 요소를 파악하는 구조적 다이어그램이자, 코딩에 필요한 속성, 함수 등의 정보를 담고 있다.\n";
	cout << "클래스, 제약 조건, 관계로 구성되어있다.\n";
	cout << "클래스의 속성 형식은 [접근제어자] 속성명 : 자료형 [다중성(배열)] [=초기값]이다. 접근 제어자는 다음과 같다.\n";
	cout << "public : ( 1 )로 표현. 어떤 클래스에서라도 접근,  private : ( 2 )로 표현. 해당 클래스 내부에서만 접근\n";
	cout << "protected : ( 3 )로 표현. 동일 패키지 내의 클래스 또는 클래스를 상속받은 외부 패키지에서만 접근\n";
	cout << "package : ( 4 )로 표현. 동일 패키지 내부에 있는 클래스에서만 접근\n";
	cout << "클래스의 오퍼레이션 형식은 [접근제어자] 오퍼레이션명(매개변수명 : 자료형) : 반환자료형이다.\n";
	cout << "( 5 )는 속성이나 오퍼레이션에 지정해야 할 조건이다. {} 중괄호를 쓰거나 주석을 추가하고 점선으로 연결한다.\n";
	cout << "관계는 연관, 집합, 포함, 일반화, 의존 관계가 있다.\n";
	cout << "10. Sequence Diagram은 시간의 흐름에 따라 변화하는 객체들간 메세지 상호 작용을 표현한 것.\n";
	cout << "주로 유스케이스 전체를 표현 범위로 하거나, 클래스 내 오퍼레이션을 범위로 함.\n";
	cout << "( 1 ) : 시스템으로부터 서비스를 요청하는 외부 요소, 사람이나 외부 시스템을 의미.\n";
	cout << "( 2 ) : 메시지를 주고받는 주체로, 객체명 : 클래스명 형식으로 사용한다. (ex. 신발 : 신규 주문)\n";
	cout << "( 3 ) : 객체가 메모리에 존재하는 기간으로, 객체 아래쪽에 점선을 그어 표현하고, 소멸이 되면 X를 표현.\n";
	cout << "( 4 ) : 객체가 메시지를 주고받으며 구동되고 있는 곳. 라이프라인에 겹쳐 직사각형 형태로 표현.\n";
	cout << "( 5 ) : 객체가 상호 작용을 위해 주고받는 메시지로, 동기, 비동기, 생성, 응답이 있다.\n";
	cout << "( 6 ) : 메시지를 보낸 후 결과가 반환될 때까지 기다림, -▶\n";
	cout << "( 7 ) : 메시지를 보낸 후 다른 작업을 수행, ->\n";
	cout << "( 8 ) : 메시지를 받는 새로운 객체를 생성, - - - >\n";
	cout << "( 9 ) : 동기 메시지에 대한 수행 결과, - - -▶\n";
	cout << "11. Communication Diagram은 초기에 Collaboration Diagram으로 불림. 시퀀스 다이어그램  + ( ) 객체들 관계까지 표현\n";
	cout << "( ) : 메시지를 이 위에 표현하며, 객체들간의 관계를 표현. 실선을 그음.\n";
	cout << "12. State Diagram은 객체의 상호 작용 과정 속 상태 변화를 그림으로 표현한다.\n";
	cout << "하나의 객체를 프레임으로 범위를 표현하고, 시작 상태는 ( 1 ), 종료 상태는 ( 2 )\n";
	cout << "객체의 상태는 ( 3 )으로 그리고, 화살표로 상태 전환을 표현하며 그 위에 이벤트를 작성한다.\n";
	cout << "( 1 ), ( 2 ), ( 3 )에 a, b, c 중 맞는 것을 적어라.\n";
	cout << "a : 둥근 사각형,  b : 속이 채워진 원,  c : 속이 채워진 원을 둘러싼 원\n";
	kh();
	cout << "  9. ( 1 ) : +,  ( 2 ) : -,  ( 3 ) : #,  ( 4 ) : ~,  ( 5 ) : 제약 조건\n\n";
	cout << "  10. ( 1 ) : 액터,  ( 2 ) : 객체,  ( 3 ) : 라이프라인,  ( 4 ) : 활성 상자,  ( 5 ) : 메시지\n";
	cout << "  ( 6 ) : 동기,  ( 7 ) : 비동기,  ( 8 ) : 생성,  ( 9 ) : 응답\n\n";
	cout << "  11. 링크\n\n";
	cout << "  12. ( 1 ) : b,  ( 2 ) : c,  ( 3 ) : a\n\n";
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

void chapter5::section53() {
	printf("53. 서버 개발 과정\n");
	printf("(   )는 서버 프로그램 개발을 위해 생성하는 객체 중 하나로, DB에 접근하고 데이터를 실제로 조작한다.\n");
	printf("DB를 조작하기 위해서 사용되는 SQL문은 (   )의 내부에 직접 입력되거나, 외부의 XML 문서에 삽입하여 호출하는 방식을 사용한다.\n");
	printf("(   )에 들어갈 것은?\n");
	while (!kbhit);
	temp = getch();
	printf("  DAO(Data Access Object)\n\n");
}

void chapter5::section54() {
	printf("54. 배치 프로그램\n");
	printf("리눅스의 crontab 명령어를 이용하여 다음의 작업을 처리하는 명령문을 작성하시오.\n");
	printf("작업 : A사는 3, 6, 9, 12월 마다 수행되어야 하는 데이터 백업 작업을 예약하려한다.\n");
	printf("해당 작업은 각 월의 25일에 서버 이용이 가장 적은 시간대인 오후 10시 정각에 처음 실행되어 15분마다 총 4회 수행할 예정이다.\n");
	printf("백업과 관련된 명령어는 /backup/batch.sh 파일에 준비해두었다.\n");
	while (!kbhit());
	temp = getch();
	printf("  */15 22 25 */3 * /backup/batch.sh\n\n");
}

void chapter6::section55() {
	printf("55. 사용자 인터페이스\n");
	printf("UI 설계의 기본 원칙 네 가지에 대해 서술하시오\n");
	while (!kbhit());
	temp = getch();
	printf("  직관성 : 기능을 누구나 쉽게 이해하고 파악할 수 있다.\n");
	printf("  유효성 : 사용자가 행하고자 하는 목적을 정확하게 달성해야한다.\n");
	printf("  학습성 : 사용자가 쉽게 이해하고 배워야 한다.\n");
	printf("  유연성 : 사용자의 행위를 최대한 수용하고 에러를 최소화한다.\n\n");
}

void chapter6::section56() {
	printf("56. UI 표준 및 지침\n");
	printf("웹 사이트 개발 시 고려해야 할 웹의 3요소를 서술하시오.\n");
	while (!kbhit());
	temp = getch();
	printf("  Web Standard 웹 표준 : 웹 사이트의 기술적 중립성을 의미하며, 자바 스크립트, HTML 등에 적용돼야 할 규칙\n");
	printf("  Web Accessibility 웹 접근성 : 누구나 어느 상황에서 웹 사이트의 모든 정보에 대해 이용할 수 있어야함\n");
	printf("  Cross browsing 웹 호환성 : 어떤 HW, SW를 사용하더라도 같은 웹사이트에 대해 동등한 서비스를 제공\n\n");
}

void chapter6::section60() {
	cout << "60. UI 상세 설계\n";
	cout << "다음이 무엇에 대한 설명인지 쓰시오.\n";
	cout << "화면의 정보를 한 눈에 파악하기 위한 시각적인 컨텐츠 모형을 말한다.\n";
	cout << "일반적으로 테이블 형태로 되어 있고, 위에서부터 아래로 내려가며 정보를 찾을 수 있는 계층형으로 되어있다.\n";
	while (!kbhit());
	temp = getch();
	cout << "  site map\n\n";
}

void chapter6::cp() {
	//comprehensive problem
	cout << "챕터 6 종합 문제.\n";
	cout << "UI 스타일 가이드 작성과 순서에 대해 서술하시오.\n";
	cout << "a. 구동 환경 정의,  b. 레이아웃 정의,  c. 기능 정의,  d. 구성 요소 정의,  e. 네비게이션 정의\n";
	while (!kbhit());
	temp = getch();
	cout << "  UI 스타일 가이드는 개발자나 디자이너들이 UI를 작성할 때 기준이 되는 규칙을 말함.\n";
	cout << "  a. 구동 환경 정의 -> b. 레이아웃 정의 -> e. 네비게이션 정의 -> c. 기능 정의(논리적 모델로 상세화) -> d. 구성 요소 정의(그리드, 버튼)\n\n";
	
	cout << "UI 요구사항 확인과 확인 순서에 대해 서술하시오.\n";
	cout << "a. 요구사항 작성,  b. 목표 정의,  c. 요구사항 확인,  d. 활동 사항 정의,  e. 정황 시나리오 작성";
	while (!kbhit());
	temp = getch();
	cout << "  UI 요구사항 확인은 새로 개발할 시스템에 필요한 UI 관련 사항을 정의.\n";
	cout << "  b. 목표 정의(인터뷰) -> d. 활동사항 정의(비전 일치) -> c, e, a. UI 요구사항 작성(요구사항 확인 -> 정황 시나리오 작성 -> 요구사항 작성)\n\n";
	
	cout << "UI 흐름 설계와 순서에 대해서 서술하시오.\n";
	cout << "a. 화면에 입력할 요소 확인,  b. 기능 및 양식 확인,  c. UI 유스케이스 설계,  d. 화면에 표현할 기능 작성\n";
	while (!kbhit());
	temp = getch();
	cout << "  UI 흐름 설계는 사용자의 업무적 진행 과정에 대해 UI가 어떤 방식으로 변화하는 지 작성하는 것\n";
	cout << "  d. 화면에 표현할 기능 작성(기능, 비기능) -> a. 화면에 입력할 요소 확인 -> c. UI 유스케이스 설계 -> b. 기능 및 양식(텍스트, 콤보, 라디오, 체크 박스) 확인\n\n";

	cout << "UI 상세 설계와 순서에 대해 서술하시오.\n";
	cout << "a. UI 요구사항과 프로토 타입에 기반한 UI 구조 설계,  b. 필요한 모든 화면을 설계,  c. 요구사항 최종 확인,  d. 표지 및 개정 이력 작성,  e. 사이트맵 구조 설계\n";
	while (!kbhit());
	temp = getch();
	cout << "  실제 설계 및 구현을 위해 만들 화면들에 대해 상세히 기술하는 것.\n";
	cout << "  c. 요구사항 최종 확인 -> d. 표지 및 개정 이력 작성 -> a. UI 요구사항과 프로토타입에 기반한 UI 구조 설계 -> e. 사이트 맵 구조를 설계 -> b. 필요한 모든 화면을 설계\n\n";
}

void chapter7::section63(const std::string &s) {
	cout << s;
	cout << "소프트웨어 인터페이스에서 실행되는 기능 테스트로, 소프트웨어의 기능이 의도대로 작동하고 있는지 테스트하는 기법은?\n";
	kh();
	cout << "  블랙박스 테스트\n\n";
	
	cout << "대표적인 화박 테스트로, 테스트 결과 실행 경로의 기초를 정의하는 테스트는?\n";
	kh();
	cout << "  기초 경로 테스트\n\n";
	
	cout << "제어 구조 검사의 세 가지 검사와 각각을 서술하시오\n";
	kh();
	cout << "  조건 검사 : 모든 논리적 조건 테스트\n  루프 검사 : 반복문에 초점을 맞춘 검사\n  데이터 흐름 검사 : 변수의 정의와 사용에 따라 검사 경로를 선택하는 검사\n\n";
}

void chapter7::section65(const std::string& s) {
	cout << s;
	cout << "상향식 통합 테스트의 단계들을 순서대로 서술하시오.\n";
	kh();
	cout << "  1. 하위 모듈을 묶어 클러스터를 구성\n";
	cout << "  2. 클러스터를 구동할 드라이버 구현\n";
	cout << "  3. 클러스터 단위 검사\n";
	cout << "  4. 드라이버 제거 후 클러스터를 실제 모듈로 구현\n\n";

	cout << "하향식 통합 테스트의 단계들을 순서대로 서술하시오.\n";
	kh();
	cout << "  1. 상위 모듈의 테스트 용으로 스텁을 만듦\n";
	cout << "  2. 깊이 또는 너비 우선 방식으로 스텁들을 하나씩 실제 모듈로 교체\n";
	cout << "  3. 모듈이 교체될 때마다 회귀 테스트를 실시함\n\n";
}

void chapter7::section66(const std::string& s) {
	cout << s;
	cout << "테스트 결과에 대해 결함이 어디에서 발생했는지 결함 관리 프로세스를 진행한다. 순서를 서술하라\n";
	kh();
	cout << "  에러 발견 -> 에러 등록 -> 에러 분석 -> 결함 확정 -> 결함 할당 -> 결함 조치 -> 결함 조치 검토 및 승인\n\n";

}

void chapter7::section67(const std::string& s) {
	cout << s;
	cout << "다음에 제시된 테스트 케이스의 작성 순서를 순서대로 나열하시오.\n";
	cout << "a : 시스템에 대한 사용자 요구사항이나, 테스트 대상을 재검토하고, 테스트 특성, 조건, 기능 등을 분석한다.\n";
	cout << "b : 시스템 요구사항과 기능 명세서를 검토하고 테스트 대상 시스템의 정보를 확보한다.\n";
	cout << "c : 요구사항에 따라 테스트 케이스를 작성하고, 입력 값, 실행 조건, 예상 결과 등을 기술한다.\n";
	cout << "d : 테스트 케이스의 형식, 분류 방법, 테스트 절차, 장비, 도구 등을 결정한다.\n";
	cout << "e : 테스트 케이스의 유용성을 검토한다\n";
	cout << "f : 결함의 위험 정도에 따른 우선순의를 결정하고, 어느 부분에 초점을 맞춰 테스트할지를 결정한다.\n";
	kh();
	cout << "  테스트 계획 검토 및 자료 확보 -> 우선순위(위험 정도) 결정 -> 테스트 대상 재검토 및 요구사항(조건, 기능) 정의\n";
	cout << "  -> 테스트 구조 설계 및 방법(테스트 절차, 장비, 도구) 결정 -> 테스트 케이스 정의, 명세(작성, 예상 결과) \n  -> 테스트 케이스 검토, 유지 보수\n";
	cout << "  b -> f -> a -> d -> c -> e\n\n";
}

void chapter7::section68(const std::string& s) {
	cout << s;
	cout << "테스트 하네스는 앱 컴포넌트 및 모듈을 테스트하는 환경의 일부분으로, 테스트를 지원하기 위해 생성된 코드와 데이터를 의미한다.\n";
	cout << "테스트 하네스 도구는 테스트가 실행될 환경을 시뮬레이션하고, 모듈 정상 동작 테스트를 하는데, 아래의 설명에 맞는 구성 요소를 말하라.\n";
	cout << "1) 제어 모듈이 호출하는 타 모듈의 기능을 단순히 수행하는 도구로, 일시적으로 필요한 조건 만을 가지고 있는 테스트용 모듈은?\n";
	cout << "2) 사전에 사용자의 행위를 조건부로 입력해 두면, 그 상황에 맞는 예정된 행위를 수행하는 객체는?\n";
	cout << "3) 테스트 대상 컴포넌트나 모듈, 시스템에 사용되는 테스트 케이스의 집합은?\n";
	cout << "4) 자동화된 테스트 실행 절차에 대한 명세서는?\n";
	kh();
	cout << "  1) 테스트 스텁\n  2) 목 오브젝트\n  3) 테스트 슈트(suites)\n  4) 테스트 스크립트\n\n";
}

void chapter7::section69(const std::string& s) {
	cout << s;
	cout << "테스트를 완료한 후에는 발견된 결함에 대해 결함 관리 측정 지표와 속성 값들을 분석하고 향후 어떤 결함이 발생할지를 추정해야 한다.\n";
	cout << "결함 관리 측정 지표 세 가지를 쓰시오\n";
	kh();
	cout << "  1. 결함 분포 (결함 수)\n  2. 결함 추세(결함 수의 추이)\n  3. 결함 에이징(지속 시간 측정)\n\n";
}

void chapter7::section70(const std::string& s) {
	cout << s;
	cout << "앱의 성능 분석(측정 지표 : 처리량, 응답시간, 경과시간, 자원사용률) 도구는 ( 1 ) 도구와 ( 2 ) 도구로 분류.\n";
	cout << "( 1 ) 도구는 앱에 부하를 가하며 성능 측정 지표를 점검한다. JMeter, LoadUI, OpenSTA\n";
	cout << "( 2 ) 도구는 앱이 실행됐을 때 시스템 자원의 사용량을 확인하고 분석한다. Scouter, Zabbix\n";
	cout << "( 1 )과 ( 2 )에 들어갈 용어는?\n";
	kh();
	cout << "  ( 1 ) : 성능 테스트\n  ( 2 ) : 시스템 모니터링\n\n";
}

void chapter8::cp(const std::string& s) {
	//comprehensive problem
	cout << s;
	cout << "연습용 링크 : https://www.w3schools.com/sql/trysql.asp?filename=trysql_select_columns" << "\n";
	cout << "1. Customers 테이블의 Country의 종류를 중복되지 않게 출력하시오.\n";
	cout << "2. Customers 테이블의 Country의 고유 갯수를 출력하시오.\n";
	cout << "3. Customers 테이블의 Country의 고유 갯수를 출력하고, 속성 이름을 CountConutry로 바꾸시오.\n";
	cout << "4. Customers 테이블의 City가 Berlin인 고객의 CustomerID와 CustomerName, City를 출력하시오.\n";
	cout << "5. Customers 테이블의 City가 Madrid인 사람의 수를 출력하시오.\n";
	cout << "6. Customers 테이블에서 Brazil의 Rio de Janeiro 혹은 Resende City에 거주하는 모든 고객을 출력하시오.\n";
	cout << "7. Products 테이블에서 Price가 높은 순서, ProductID가 낮은 순서대로 모든 내용을 출력하시오.\n";
	cout << "8. Customers 테이블에 Suppliers 테이블에 있는 모든 SupplierName, ContactName, Address, City, Country 속성을 CustomerName, ContactName, Address, City, Country에 집어넣어라.\n";
	cout << "9. Orders 테이블에 10444, 14, 5, 1997-03-01, 3을 삽입하시오.\n";
	cout << "10. Employees 테이블에서 Notes가 NULL인 사람의 EmployeeID, Photo를 출력하시오.\n";
	kh();
	cout << "  1. SELECT DISTINCT Country FROM Customers;\n\n";
	cout << "  2. SELECT COUNT(DISTINCT Country) FROM Customers;\n\n";
	cout << "  3. SELECT COUNT(*) AS CountCountry FROM (SELECT DISTINCT Country From Customers); \n     SELECT COUNT(DISTINCT Country) AS CountCountry FROM Customers;\n\n";
	cout << "  4. SELECT CustomerID, CustomerName, City FROM Customers Where City = 'Berlin';\n\n";
	cout << "  5. SELECT COUNT(*) FROM Customers WHERE City = 'Madrid';\n\n";
	cout << "  6. SELECT * FROM Customers WHERE Country = 'Brazil' AND (City = 'Resende' OR City = 'Rio de Janeiro');\n\n";
	cout << "  7. SELECT * FROM Products ORDER BY Price DESC, ProductID;\n\n";
	cout << "  8. INSERT INTO Customers(CustomerName, ContactName, Address, City, Country) SELECT SupplierName, ContactName, Address, City, Country FROM Suppliers;\n\n";
	cout << "  9. INSERT INTO Orders VALUES (10444, 14, 5, '1997-03-01', 3)\n\n";
	cout << "  10. SELECT EmployeeID, Photo From Employees WHERE Notes IS NULL;\n\n";
	
	cout << "11. [학생정보] 테이블과 [학과인원] 테이블에서 학과가 같은 튜플을 JOIN 하여 이름, 학과, 학생수를 검색하시오.\n";
	cout << "12. 여가활동 테이블에 이름이 없는(취미활동을 하지 않는) 사람들을 사원 테이블에서 모두 검사하시오.\n";
	cout << "13. 상여금 테이블에서 상여내역별로 상여금에 대한 일련 번호를 구하시오. 순서는 내림차순으로, 속성명은 NO로 구한다.\n";
	cout << "14. OrderDetails 테이블에서 OrderID별 Quantity 평균 값을 구하라(속성명은 평균)\n";
	cout << "15. Customers 테이블에서 Country별 튜플 수를 검색하시오\n";
	cout << "16. Customers 테이블에서 Country별 튜플의 수가 3개 이상인 수를 검색하시오\n";
	kh();
	cout << "  11. SELECT 이름, 학과, 학생수 FROM 학생정보 JOIN 학과인원 ON(학생정보.학과 = 학과인원.학과);\n\n";
	cout << "  12. SELECT * FROM 사원 WHERE 이름 NOT IN (SELECT 이름 FROM 여가활동);\n\n";
	cout << "  13. SELECT 상여내역, 상여금, ROW_NUMBER() OVER(PARTITION BY 상여내역 ORDER BY 상여금 DESC) AS NO FROM 상여금;\n\n";
	cout << "  14. SELECT OrderID, AVG(Quantity) AS 평균 FROM OrderDetails GROUP BY OrderID;\n\n";
	cout << "  15. SELECT Country, Count(*) FROM Customers GROUP BY Country;\n\n";
	cout << "  16. SELECT Country, Count(*) FROM Customers GROUP BY Country HAVING COUNT(*) >= 3;\n\n";

	cout << "17. 아래의 요구사항을 만족하는 테이블 patient를 정의하라.\n";
	cout << ": id(문자 5), sex(문자 1) 속성을 가지며, id 속성은 기본키이고, sex 속성은 f 또는 m 값만 갖도록 한다.(제약 조건명 : sex_ck)\n";
	cout << "id는 doctor 테이블에 있는 doc_id를 참조하며, 제약 조건명은 id_fk다.\n";
	kh();
	cout << "  17. CREATE TABLE patient (id CHAR(5) PRIMARY KEY, sex CHAR(5),\n";
	cout << "             CONSTRAINT sex_ck CHECK (sex = 'f' OR sex = 'm'), \n";
	cout << "             CONSTRAINT id_fk FOREIGN KEY (id) REFERENCES doctor(doc_id));\n\n";

	cout << "18. 아래의 요구사항을 만족하는 테이블 Instructor를 정의하라.\n";
	cout << ": id(문자 5) 속성을 기본키로, name(문자 15) 속성은 Null이 못오게,\n";
	cout << "dept(문자 15) 속성은 Department 테이블의 dept 속성을 참조하는 외래키로 만든다.\n";
	cout << "Department 테이블에서 튜플이 삭제되면 관련된 모든 튜플의 dept 속성 값은 NULL로 변경하고,\n";
	cout << "Department 테이블에서 dept 속성이 변경되면 Instructor 테이블의 관련된 모든 속성 값도 같은 값으로 변경한다.\n";
	kh();
	cout << "  18. CREATE TABLE Instructor ( id CHAR(5) PRIMARY KEY,\n";
	cout << "             name CHAR(15) NOT NULL,\n";
	cout << "             dept CHAR(15) FOREIGN KEY REFERENCES Department(dept)\n";
	cout << "                  ON DELETE SET NULL\n";
	cout << "                  ON UPDATE CASCADE );\n\n";

	cout << "19. 아래의 요구사항을 만족하는 뷰 CC를 정의하라.\n";
	cout << ": Course 릴레이션의 instructor 속성과 Instructor 릴레이션의 id 속성이 같은 자료에 대해 view를 만든다.\n";
	cout << "cc 뷰는 ccid, ccname, instname 속성을 가진다.\n";
	cout << "cc 뷰는 Course의 id, name, Instructor의 name 속성을 사용한다.\n";
	kh();
	cout << "  19. CREATE VIEW CC(ccid, ccname, instname)\n";
	cout << "             AS SELECT Course.id, Course.name, Instructor.name\n";
	cout << "             FROM Course, Instructor WHERE Course.instructor = Instructor.id;\n\n";

	cout << "20. 직위 도메인을 만들며 값으로 사원, 대리, 부장, 사장만을 허용하고 기본 값으로 사원을 취하는 도메인 무결성\n";
	cout << "제약 조건을 설정하라\n";
	kh();
	cout << "  20. CREATE DOMAIN 직위 VARCHAR(10)\n";
	cout << "             DEFALUT '사원' CONSTRAINT VALID-직위 CHECK (VALUE IN ('사원', '대리', '부장', '사장') );\n\n";

	cout << "21. 아래의 SQL에서 직책 부분을 암기하자.\n";
	kh();
	cout << "  21. CREATE TABLE 사원 (성명 CHAR(10) UNIQUE,\n";
	cout << "             직책 CHAR(10) CHECK (직책 IN ('사원', '대리', '사장') ) );\n\n";

	cout << "22. 사용자 ID가 NABI인 사람에게 데이터베이스 및 테이블을 생성할 수 있는 권한을 부여하시오.\n";
	cout << "23. 김하늘에게 학생 테이블에 대한 접근 및 조작에 관한 모든 권한을 부여하는 SQL문을 작성하시오.\n";
	cout << "24. 김하늘에게 강좌 테이블에 대해 삭제하는 권한을 부여하고, 강좌 테이블에 대해 삭제하는 권한을\n";
	cout << "다른 사람에게 부여할 수 있는 권한을 부여하시오.\n";
	cout << "25. 수강 테이블에 대해 임꺽정에게 부여된 UPDATE 권한과 임꺽정이 다른 사람에게 UPDATE 권한을 부여할 수 있는 권한\n";
	cout << "그리고 임꺽정이 다른 사람에게 부여한 UPDATE 권한도 모두 취소하시오.\n";
	cout << "26. 학부생 테이블에서 담당관이 이로 시작하는 튜플의 학과번호를 999로 갱신하시오.\n";
	kh();
	cout << "  22. GRANT RESOURCE TO NABI;\n\n";
	cout << "  23. GRANT ALL ON 학생 TO 김하늘;\n\n";
	cout << "  24. GRANT DELETE ON 강좌 TO 김하늘 WITH GRANT OPTION;\n\n";
	cout << "  25. REVOKE UPDATE ON 수강 FROM 임꺽정 CASCADE;\n";
	cout << "      (어차피 UPDATE 권한 REVOKE하면 GRANT OPTION도 취소됨. 그래서 생략.)\n\n";
	cout << "  26. UPDATE 학부생 SET 학과번호 = 999 WHERE 담당관 LIKE '이%';\n\n";

	cout << "27. 학생 정보 테이블의 학번과 신청 정보 테이블의 학번이 같고, 신청과목이 Java인 학생들만을 대상으로\n";
	cout << "학생정보의 이름, 전공, 신청과목의 신청과목을 검색하려한다.\n";
	cout << "검색된 데이터는 이름, 전공, 신청 과목을 기준으로 그룹을 지정하되, 전공이 컴퓨터 공학인 그룹만 표시하라\n";
	kh();
	cout << "  28. SELECT 이름, 전공, 신청과목 FROM 학생정보, 신청과목 WHERE 학생정보.학번 = 신청정보.학번 AND 신청과목.신청과목 = 'Java'\n";
	cout << "             GROUP BY 이름, 전공, 신청과목 HAVING 전공 = '컴퓨터공학';\n\n";
	
	cout << "28. 결제 테이블(학번, 신청번호, 결제여부)을 이용하여 결제 여부별 학생수를 검색하라.\n";
	cout << "29. 상여금 테이블에서 상여내역별로 상여금에 대한 일련 번호를 구하시오. 순서는 내림차순.\n";
	kh();
	cout << "  28. SELECT 결제여부, COUNT(*) AS 학생수 FROM 결제 GROUP BY 결제여부;\n\n";
	cout << "  29. SELECT 상여내역, 상여금, ROW_NUMBER() OVER (PARTITION BY 상여내역, 상여금\n";
	cout << "             ORDER BY 상여금 DESC) FROM 상여금;\n\n";

	cout << "30. 프로시저에 대해서 간단하게 서술하시오.\n";
	cout << "31. 다음의 조건에 따라 프로시저를 만들어라.\n";
	cout << ": 프로지서 score_count를 생성하며, 동일한 이름이 있는 경우 기존의 프로시저를 대체한다.\n";
	cout << "파라미터로 전달받은 정수는 변수 sc에 저장하여 처리되며, 어떠한 값도 반환하지 않는다.\n";
	cout << "지역변수로 정수형 변수 a를 사용한다.\n";
	cout << "프로시저가 실행되면 score 테이블의 cont 속성의 값이 sc보다 크거나 같은 튜플의 개수를 조회하여\n";
	cout << "total 테이블의 mem_count 속성에 입력한다.\n";
	kh();
	cout << "  30. 데이터베이스에 저장되어 실행되어 스토어드 프로시저라고도 불린다.\n";
	cout << "  일종의 트랜잭션 언어로 일련의 SQL 활용하여 일일 마감 작업 등 일괄 작업에 실행된다.\n\n";
	cout << "  31. CREATE OR REPLACE PROCEDURE score_count(sc IN INT)\n";
	cout << "      IS\n          a INT;\n";
	cout << "      BEGIN\n          SELECT count(*) INTO a FROM score WHERE cont >= sc\n";
	cout << "          INSERT INTO total(mem_count) VALUES(a);\n";
	cout << "          COMMIT;\n";
	cout << "      END;\n\n";

	cout << "32. 트리거에 대해서 간단하게 서술하시오.\n";
	cout << "33. 사원 테이블이 갱신될 때, 갱신된 튜플마다 태도, 성과 속성의 평균을 계산하여 50 이상이면 우수,\n";
	cout << "아니면 미달을 화면에 출력하는 트리거 사원_tri를 정의하라.\n";
	kh();
	cout << "  32. 데이터베이스에 저장되어 실행되며, 삽입 삭제 등의 이벤트가 발생했을 때 정의한 일련의 작업들이 자동으로 실행되는 것.\n";
	cout << "  보통 로그 메세지 출력, 데이터 무결성 유지를 위해 사용됨.\n\n";
	cout << "  33. CREATE TRIGER 사원_tri AFTER UPDATE ON 사원\n";
	cout << "      FOR EACH ROW\n      BEGIN\n";
	cout << "      IF (태도 + 성과) / 2 >= 50 THEN\n          DBMS_OUTPUT.PUT_LINE('우수');\n";
	cout << "      ELSE\n          DBMS_OUTPUT.PUT_LINE('미달');\n";
	cout << "      END IF;\n      END;\n\n";

	cout << "34. 사용자 정의 함수에 대해서 간단하게 서술하시오.\n";
	cout << "35. i_성별을 입력받아 1이면 남자, 2면 여자를 반환하는 사용자 정의 함수 GET_S_성별 이라는 이름으로 정의하라.\n";
	kh();
	cout << "  34. 프로시저처럼 일련의 SQL을 통해 작업을 수행하는 데, 파라미터로는 입력만 받을 수 있고,\n";
	cout << "  무조건 하나의 값을 RETURN을 통해 반환하며, SELECT만 사용할 수 있다.\n\n";
	cout << "  35. CREATE FUNCTION GET_S_성별(i_성별 INT)\n";
	cout << "      RETURN VARCHAR\n      IS\n      BEGIN\n";
	cout << "          IF i_성별 = 1 THEN\n              RETURN '남자';\n";
	cout << "          ELSE\n              RETURN '여자';\n          END IF;\n";
	cout << "      END;\n\n";

	cout << "36. 커서에 대해서 간단하게 서술하시오.\n";
	cout << "37. 묵시적 커서와 명시적 커서에 대해서 서술하시오.\n";
	cout << "38. 다음은 학생 테이블에서 국어, 영어 점수의 평균이 20점 이하인 학생의 학생코드와 이름을 출력하는 cs_stu 커서다. 괄호를 채워라\n";
	cout << "  ( 1 )\n    i_학생코드 INT;\n    c_이름 VARCHAR2(10);\n    ( 2 ) cs_stu\n";
	cout << "    IS\n    SELECT 학생코드, 이름 FROM 학생 WHERE (국어+영어)/2 <= 20;\n";
	cout << "  ( 3 )\n    ( 4 ) cs_stu;\n    LOOP\n      ( 5 ) cs_stu ( 6 ) i_학생코드, c_이름;\n";
	cout << "      EXIT WHEN cs_stu( 7 );\n";
	cout << "      DBMS_OUTPUT.PUT_LINE(i_학생코드||''||c_이름);\n    END LOOP;    ( 8 ) cs_stu;\n  END;\n\n";
	cout << "39. DELETE문을 수행한 후 커서의 속성을 활용하여 패치된 튜플의 수를 조회하려 한다. 다음의 빈 칸을 채우시오.\n";
	cout << "BEGIN\n  DELETE FROM 급여 WHERE 기본급 > 500 AND 부서 IS NULL;\n  DBMS_OUTPUT.PUT_LINE(SQL( ? ) );\nEND;";
	kh();
	cout << "  36. 쿼리문의 결과가 저장되어있는 메모리를 가리킬 수 있는 포인터를 말한다. OPEN, FETCH, CLOSE로 실행된다.\n\n";
	cout << "  37. 묵시적 커서 : 쿼리문을 진행하며 자동으로 만들어지고 진행된다. 정상적인 쿼리문 수행여부 판별을 위해 쓰인다.\n";
	cout << "      명시적 커서 : 사용자가 직접 정의하고 OPEN -> FETCH -> CLOSE로 진행시킨다. 쿼리문의 튜플을 제어하기 위해 사용된다.\n\n";
	cout << "  38. ( 1 ) : DECLARE,  ( 2 ) : OPEN,  ( 3 ) : BEGIN,  ( 4 ) : OPEN\n";
	cout << "  ( 5 ) : FETCH,  ( 6 ) : INTO,  ( 7 ) : %NOTFOUND,  ( 8 ) CLOSE\n\n";
	cout << "  39. SQL%ROWCOUNT\n\n";
	

	
}

void chapter9::section82(const std::string& s) {
	cout << s;
	cout << "다음에서 설명하는 소프트웨어 개발 보안 활동 관련 법령이 무엇인지 작성하시오.\n";
	cout << "1) 개인 정보의 처리 및 보호에 관한 사항을 정함으로써 개인의 자유와 권리를 보호한다\n";
	cout << "2) 개인 정보의 처리에 관한 기준, 개인 정보 침해의 유형 및 예방 조치 등에 관한 세부사항을 규정한다.\n";
	cout << "3) 개인정보 처리자가 개인 정보가 분실, 유출, 훼손되지 않도록 안전성 확보를 위한 기준을 마련한다\n";
	kh();
	cout << "  1) 개인 정보 보호법\n  2) 표준 개인 정보 보호 지침\n  3) 개인 정보의 안정성 확보 조치 기준\n\n";
}

void chapter9::section84(const std::string& s) {
	cout << s;
	cout << "세션 통제의 보안 약점에는 ( 1 )과 ( 2 )가 있다. \n( 1 )은 일정한 규칙이 존재하는 세션 ID가 발급되거나 타임 아웃이 너무 긴 경우 발생할 수 있다.\n";
	cout << "클라이언트들의 세션 정보를 가로채는 ( 3 )과 같은 공격을 통해 인가되지 않은 시스템의 기능을 이용할 수 있다.\n";
	cout << "( 2 )는 다중 스레드 환경의 싱글톤 패턴에서 레이스 컨디션으로 인해 동기화 오류가 발생하거나, 멤버 변수의 정보가 노출될 수 있는 것을 말한다.\n";
	cout << "이를 해결하기 위해 멤버 변수보다 지역 변수를 활용하여 변수의 범위를 제한한다.\n";
	cout << "또한, 세션을 설계할 시 모든 페이지에서 ( 4 )이 가능하게 하고, 세션 타임 아웃을 설정하며, ( 5 ) 변경 시 활성화된 세션을 삭제한다.\n";
	kh();
	cout << "  ( 1 ) : 불충분한 세션 관리\n  ( 2 ) : 잘못된 세션에 의한 정보 노출\n  ( 3 ) 세션 하이재킹\n  ( 4 ) 로그아웃\n  ( 5 ) 패스워드\n\n";
}

void chapter9::section85_to_91(const std::string& s) {
	cout << s;
	cout << "다음에 해당하는 보안 약점 이름을 작성하시오.\n";
	cout << "(입력 데이터 검증 및 표현, 보안 기능, 시간 및 상태, 에러 처리, 코드 오류, 캡슐화, API 오용)\n";
	cout << "1. 외부 입력 값을 통해 시스템 명령어의 실행을 유도함으로 권한을 탈취\n";
	cout << "2. 경로 조작에 사용되는 문자 '/', '\', '..' 등을 사용해 데이터 입출력 경로를 조작하고, 서버 자원을 수정하는 경로 순회 공격\n";
	cout << "3. 동적 쿼리에 사용되는 입력란에 SQL을 삽입하여 무단으로 DB를 조회한다\n";
	cout << "4. 사이트에 악의적인 스크립트를 삽입하여 방문자들에게 악성 코드를 설치시킨다. HTML 태그 사용을 제한하거나 특수 문자를 다른 문자로 치환한다.\n";
	cout << "5. 소스 코드 유출 시 내부에 하드코드된 패스워드를 이용한다. 패스워드를 암호화하거나 디폴트 패스워드의 사용을 피해야 한다.\n";
	cout << "6. 암호화된 파일을 해독해서 비밀번호 등을 탈취한다. IT보안인증사무국이 안정성을 확인한 암호 모듈을 사용해야 한다.\n";
	cout << "7. 접근 권한을 부여하지 않은 경로를 통해 정보를 탈취한다.\n";
	cout << "8. 보안 검사를 우회하여 인증과정 없이 중요한 정보를 접근한다.\n";
	cout << "9. 암호화되지 않은 평문 데이터를 전송하다 탈취당하는 경우다. HTTPS, SSL 같은 보안 채널을 써야 한다.\n";
	cout << "10. 무한 반복 혹은 무한 재귀함수에 의해 시스템 자원이 끊임없이 사용되고, 자원 고갈로 시스템이 정지된다.\n";
	cout << "11. Time of check와 Time of use 사이의 자원 불일치를 통한 동기화 오류, 교착상태 발생.\n";
	cout << "12. 오류를 모두 묶어서 동시에 처리하거나, 함수의 반환값을 처리하지 않아 발생하는 에러.\n";
	cout << "13-1. 오류 발생시 실행 환경, 사용자 정보, 디버깅 정보 등의 중요 정보가 소프트웨어 메세지로 외부에 노출된다.\n";
	cout << "13-2. 13-1의 상황에서 오류가 발생한 위치를 추적하기 위해 소프트웨어가 실행 도중 호출한 메소드 리스트를 기록한 것의 이름은?\n";
	cout << "14. 에러 처리를 하지 않아서 실행이 중단되거나 의도에 벗어난 동작을 실행하는 경우.\n";
	cout << "15. 포인터에 저장되어있는 메모리 주소가 널인 경우 발생하는 문제. 소프트웨어가 비정상 종료될 수 있음.\n";
	cout << "16. 자원 해제가 제대로 되지 않아 메모리에 자원이 남아있는 경우. 시스템이 자원을 계속 보유하기에 자원 부족 발생.\n";
	cout << "17. 이미 사용이 종료되어 반환된 메모리를 참조하는 경우 예상치 못한 값 또는 코드를 수행할 수 있음.\n";
	cout << "18. 변수에 이전에 사용하던 내용이 계속 남아있어 변수가 외부에 노출될 위험이 있다.\n";
	cout << "19. private 배열의 주소가 외부로 공개되는 문제.\n";
	cout << "20. private으로 선언된 배열을 외부에서 접근할 수 있는 문제.\n";
	cout << "21. 개발 중 버그 수정이나 결과값 확인을 위해 남겨둔 코드들로 인해 시스템 중요 정보나 인증 및 식별 절차를 생략하는 코드가 포함되어 있을 수 있다.\n";
	cout << "22. 시스템 메시지 등을 통해 시스템 내부 정보를 외부에 출력하도록 코딩한 경우.\n";
	cout << "23. 보안 문제로 사용이 금지된 API를 사용하거나 잘못된 방식으로 API를 사용하는 경우.\n";
	cout << "24. 도메인명에 의존하여 인증이나 접근 통제 등의 보안 결정을 내리는 경우, ( ? )을 악용하여 인증이나 접근 통제를 우회할 수 있다.\n";
	kh();
	cout << "  1. 운영체제 명령어 삽입\n  2. 경로 조작 및 자원 삽입\n  3. SQL 삽입\n  4. 크로스 사이트 스크립트\n  5. 하드코드된 패스워드\n  6. 취약한 암호화 알고리즘 사용\n";
	cout << "  7. 부적절한 인가\n  8. 적절한 인증 없이 중요기능 허용\n  9. 중요정보 평문 저장 및 전송\n  10. 종료되지 않는 반복문, 재귀함수\n  11. TOCTOU 경쟁 조건\n";
	cout << "  12. 부적절한 예외처리\n  13-1. 에러 메세지를 통한 정보노출\n  13-2. 스택 트레이스\n  14. 오류 상황 대응 부재\n  15. 널 포인터 역참조\n";
	cout << "  16. 부적절한 자원 해제\n  17. 해제된 자원 사용\n  18. 초기화되지 않은 변수 사용\n  19. public 메소드의 반환값으로 private 배열 사용\n";
	cout << "  20. private 배열에 public 데이터 할당\n  21. 제거되지 않은 디버그 코드\n  22. 시스템 데이터 정보 노출\n  23. 취약한 API 사용\n  24. DNS Lookup에 의존한 보안 결정\n\n";
}

void chapter9::section92(const std::string& s) {
	cout << s;
	cout << "암호화 방식은 단방향의 ( 1 ) 기법, 양방향의 ( 2 ), ( 3 ) 기법이 있다.\n( 1 )는 임의의 길이를 고정된 길이의 값이나 키로 변환하는 것을 의미한다.\n";
	cout << "SHA 시리즈, MD5, N-NASH 등이 있다.\n( 2 )는 ( 4 ), ( 5 )으로도 불리며, 동일한 키로 데이터를 암호화하고 복호화한다.\n";
	cout << "블록 암호화 방식(한 번에 하나의 데이터 블록 암호화)으론 : ( 6 ), ( 7 ), ( 8 ), ( 9 )가 있고,\n스트림 암호화 방식(평문과 동일한 길이의 스트림을 생성한 후 비트 단위로 암호화)으론 : LFSR, RC4가 있다.\n";
	cout << "( 3 )는 ( 10 )으로도 불린다. 암호화할 때는 ( ? )를, 복호화 할 때는 비밀키를 사용해 복호화 알고리즘 권한이 있는 사용자만이 복호화가 가능하다\n";
	cout << "대표적인 기법으론 RSA가 있고, 키 분배가 용이하고 관리해야할 키의 개수가 적지만, 암, 복호화 속도가 느리며, 알고리즘이 복잡하고, ( 2 ) 보다 파일의 크기가 크다.\n";
	cout << "( 6 ) 의 블록 크기는 64비트, 키 길이는 56비트다. NBS에서 만들었다.\n";
	cout << "( 7 ) 의 블록 크기는 128, 키 길이에 따라 128, 192, 256로 분류된다. NIST에서 DES를 업그레이드했다.\n";
	cout << "( 8 ) 의 블록 크기는 128, 키 길이에 따라 128, 256로 분류된다. KISA에서 개발.\n";
	cout << "( 9 ) 의 블록 크기는 128, 키 길이에 따라 128, 192, 256비트로 분류된다. 국가정보원과 산학연협회가 개발.\n";
	kh();
	cout << "  ( 1 ) : 해시\n  ( 2 ) : 개인키 암호화\n  ( 3 ) : 공개키 암호화\n  ( 4 ) : 대칭키 암호화\n  ( 5 ) : 단일키 암호화\n  ( 6 ) : DES\n  ( 7 ) : AES\n  ( 8 ) : SEED\n  ( 9 ) : ARIA\n  ( 10 ) : 비대칭키 암호화\n\n";
}

void chapter10::section93(const std::string& s) {
	cout << s;
	cout << "운영체제의 성능 평가 기준에 대하여 간략히 서술하시오.\n";
	kh();
	cout << "  1. 처리 능력 : 일정 시간내에 운영체제가 처리하는 일의 양\n";
	cout << "  2. 반환 시간 : 시스템에 작업을 의뢰한 시간부터 처리가 완료될 때까지 걸린 시간\n";
	cout << "  3. 사용 가능도 : 시스템을 사용할 필요가 있을 때 즉시 사용가능한 정도. 다중 프로그래밍 정도 등의 요소가 좌우함.\n";
	cout << "  4. 신뢰도 : 시스템이 주어진 문제를 정확하게 해결하는 정도.\n\n";
}

void chapter10::section95(const std::string& s) {
	cout << s;
	cout << "UNIX에서 현재 시스템의 프로세스와 메모리 사용 현황을 표시할 때 사용하는 명령어를 쓰시오.\n";
	kh();
	cout << "  top\n\n";
	
	cout << "Windows에서 디스크 표면을 트랙과 섹터로 나누어 초기화할 때 사용하는 명령어를 쓰시오.\n";
	kh();
	cout << "  format\n\n";
	
	cout << "Windows의 명령 프롬프트에서 file.txt 파일의 읽기 전용 속성은 해제하고 숨김 속성은 지정하려고 한다. 명령문을 쓰시오.\n";
	kh();
	cout << "  attrib -R+H file.txt\n  +(속성설정), -(속성해제), R(읽기), A(저장,백업), S(시스템 파일), H(숨김)\n\n";

	cout << "Unix에서 abc.txt 파일에 대해 다른 사용자의 읽기, 쓰기 권한을 제거하는 명령문을 쓰시오.\n";
	kh();
	cout << "  chmod o-rw abc.txt\n  *u(사용자), g(그룹), o(다른 사용자), a(모두), +(권한 추가), -(권한 삭제), =(권한 부여), r(읽기), w(쓰기), x(실행)\n\n";
	
	cout << "Windows에서 C 드라이브에 있는 file1.txt 파일을 file2.txt로 이름을 변경하여 D 드라이브로 이동하는 명령문을 쓰시오.\n";
	kh();
	cout << "  move file1.txt D:\\file2.txt\n\n";

	cout << "UNIX에서 현재 디렉토리에 있는 file1.txt 파일을 dir 디렉터리로 이동하되, 파일명을 file2.txt로 바꾸는 명령문을 쓰시오.\n";
	kh();
	cout << " mv file1.txt dir/file2.txt\n\n";

	cout << "dir의 옵션 종류를 간단하게 서술하시오. /p, /w, /o, /s\n";
	kh();
	cout << "  /p : 목록을 한 화면 단위로, /w : 가로로, /s : 하위 디렉토리까지, /o : 정렬 방식 설정(n 이름, d 날짜, s 크기)\n\n";
}