#include <stdio.h>

#include <stdlib.h>



int main()

{

	int a = 0;

	int d = 0;

	int n = 0;

	int x;

	int y;

	scanf_s("&d &d &d", &a, &d, &n);
	
	y = 1;

	a = 1;
	d = 3; 
	n = 5;

	for (x = a; x <= n; x++) {

		y = y + d;

	}

	printf_s("%d", y);

	return 0;

}

