#include <iostream>

using namespace std;

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	cout << a - b;
	return a - b;
}

void cal(int a, int b, void (*ppf)()) {
	//cout << (float(*)(int,int))ppf(a, b);
	 
}

int main() {
	int** pp;
	//포인터 == 특정 자료형 가리키기
	//포인터의 포인터 == 포인터 가리키기
	int arr[5] = { 0, };

	int* p1, *p2;
	int a = 10;
	int b = 15;

	p1 = &a;
	p2 = &b;
	pp = &p1;
	*pp = &b;
	cout << *pp  << "\n" << &a <<"\n" <<**pp;

	return 0;
}