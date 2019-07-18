#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
	int n;
	int arr[10];
	int seed;
	scanf_s("%d %d", &n, &seed);
	srand(seed);	//seed°ª »ç¿ë

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % n;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

\	return 0;
}