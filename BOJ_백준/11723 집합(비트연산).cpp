#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int S = 0;

//int는 0일때, 4 byte로 다음의 값을 가짐.
//00000000 00000000 00000000 00000000
//(2진수로 표현한 상황)
//뒤에서부터 20비트를 1~20까지의 집합 원소에 대응시켜서
//00000000 00000000 00000000 00000001이면 집합에 1이 있고,
//00000000 00000000 00000000 00001001이면 집합에 1과 4가 있다는 뜻으로
//사용할 예정.
//그를 위해 add, remove, check 등의 함수에서 
//비트 연산을 사용하는 중

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
		//string은 == "문자열"로 비교 검사할 수 있음
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
			//연산자 우선순위 조심
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
			//~0 == -1 == 모든 비트가 1
			S = ~0;
		}
		else if (str == "empty") 
			S = 0;
	}
	return 0;
}