#include <stdio.h>
#include <stdlib.h>
void find(int n);

int main() {
	int n;
	printf("���� ���� n�� �Է��ϼ���\n");
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
			for (int j = n - i; j > 1; j--) {//j�� n-i���� 2���� ���⸦ �մϴ�.
				printf(" ");
			}
			printf("*");//����� ������ �κп� *�� ����մϴ�.
			printf("\n");
		}
	}
}

