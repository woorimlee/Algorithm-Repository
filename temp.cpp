#include <stdio.h>
#include <stdlib.h>
void find(int n);

int main() {
	int n;
	printf("양의 정수 n을 입력하세요\n");
	scanf("%d", &n);
	find(n);
	return 0;
}
void find(int n) {
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			for (int j = 1; j <= n; j++) {
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int j = n - i; j > 1; j--) {//j는 n-i부터 2까지 띄어쓰기를 합니다.
				printf(" ");
			}
			printf("*");//가운데의 마지막 부분에 *를 출력합니다.
			printf("\n");
		}
	}
}

