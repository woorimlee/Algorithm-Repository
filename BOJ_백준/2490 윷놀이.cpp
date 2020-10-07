#include <cstdio>
int main() {
	char num = 64;
	int temp;
	for (int i = 0; i < 3; i++) {
		num = 64;
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &temp);
			if (temp == 0)
				num++;
		}
		if (num == 64) 
			printf("E\n");
		else 
			printf("%c\n", num);
	}
	return 0;
}