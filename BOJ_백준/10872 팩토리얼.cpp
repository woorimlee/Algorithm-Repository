#include <cstdio>
int main() {
	int N, ans = 1;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		ans *= i;
	}
	printf("%d", ans);
	return 0;
}