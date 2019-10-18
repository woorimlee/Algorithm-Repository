#include <stdio.h>
#include <iostream>
using namespace std;

void SwapIntPtr(int** p1, int** p2)
{
	int *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void SwapIntPtr2(int **p1, int **p2);

int main(void) {

	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	cout << "ptr1 : " << &num1 << " ptr2 : " << &num2 << endl;
	cout << "ptr1 : " << ptr1 << " ptr2 : " << ptr2 << endl;
	SwapIntPtr(&ptr1, &ptr2);
	cout << "ptr1 : " << ptr1 << " ptr2 : " << ptr2 << endl;
	cout << "ptr1 : " << *ptr1 << " ptr2 : " << *ptr2 << endl;
	return 0;
 }

void SwapIntPtr2(int** p1, int** p2)
{
	int temp = **p1;
	**p1 = **p2;
	**p2 = temp;
}
//±êÇé Å×½ºÆ®