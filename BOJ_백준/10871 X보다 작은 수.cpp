#include <cstdio>

int main() {
	int N, X, num;
	scanf("%d %d",&N, &X);
	while (N--) {
		scanf("%d", &num);
		if (X > num) {
			printf("%d ", num);
		}
	}
	return 0;
}