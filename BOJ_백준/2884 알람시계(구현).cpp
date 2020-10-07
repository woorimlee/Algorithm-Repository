#include <cstdio>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	//분 단위로 환산
	c = a * 60 + b - 45;
	//printf 하는 부분을 보면 나누기 및 나머지 연산자로 답을 확인하는데,
	//-값이 나오는 경우 + c가 0인 경우가 있기 때문에 나누는 단위인 60 * 24를 한 번 더해줌
	c += 60*24;
	printf("%d %d", c / 60 % 24, c % 60);
	return 0;
}