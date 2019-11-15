#include <iostream>
//출처 : http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=614

/*
 이 소스 코드에서 하고자 하는 일 :
	두 변수를 더해주는 소스 코드를 만들 것임.
	다만, 두 변수가 음수일 때 절댓값으로 바꿔줄 것인지 미정인 상태.
	따라서 우선은 더하는 역할을 받아줄 함수를 만든다.

 함수의 포인터를 선언하면 함수의원형만 결정하고 실제 함수는 정의하지 않아도 컴파일이
가능합니다.따라서 아래와 같이 코드를 구성할수도 있습니다.
*/
int UserSum(int a, int b, int (*fp)(int, int))
{
	int num = 0;

	// fp가 가리킬 함수에서 할 일 외에
	// 공통적으로 해야할 작업을 처리... ( 생략 )

	if (fp != nullptr)
		num = (*fp)(a, b);	//fp가 *가리키는 것은 int 자료형에 parameter로 int 두 개를 갖는 함수

	// 필요한 작업 마무리... ( 생략 )

	return num;
}
/*
int main() {
	int a = 10;
	int b = -1;
	int answer = UserSum(a, b, nullptr);
	std::cout << answer << std::endl;
	return 0;
}
 위와 같이 UserSum 함수를 구성하면 합산하는 기능을 하는 함수가 아직 정의 되지 않아도 위 함수를
컴파일할수 있습니다.이렇게 구성한 함수는 나중에 자신이 사용하는 시점에서 자신이 원하는데로
합산하는 기능을 가진 함수를 정의하고, 해당 함수의 이름을 인자로 넘겨줘서 아래와 같이 소스를
완성할수도 있습니다.
*/

int Sum(int a, int b)
{
	return a + b;
}

int ABS_Sum(int a, int b)
{
	// a 또는 b 변수가 음수이면 양수화 시킨다.
	if (a < 0) a = a * (-1);
	if (b < 0) b = b * (-1);

	return a + b;
}

int main() {
	int a = 10;
	int b = -1;
	int answer = UserSum(a, b, Sum); // 혹은 UserSum(a, b, ABS_Sum);
	std::cout << answer << std::endl;
	return 0;
}
/*
 이와같이 함수의 포인터를 사용하면 함수를 정의할때 기능변화에 대해 좀더 효과적으로 대처할수
있는 함수를 정의할수 있습니다.
*/