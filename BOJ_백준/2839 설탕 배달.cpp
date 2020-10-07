#include <cstdio>
int main() {
	int N;
	scanf("%d", &N);
	for (int f = N / 5; f >= 0; f--) {
		if ((N - (f * 5)) % 3 == 0) {
			printf("%d", f + ((N - (f * 5)) / 3));
			return 0;
		}
	}
	printf("-1");
	return 0;
}