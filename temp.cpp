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

<<<<<<< HEAD
\	return 0;
}
=======
	return 0;
}



>>>>>>> 2da2f10d8d4c14472c5ef9ee603438c381dc133e
